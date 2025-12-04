#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include "model.h"

// ==========================================
// 1. C?U HÌNH & BI?N TOÀN C?C
// ==========================================

// --- LCD + DHT ---
LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(4, DHT11);

// --- PIN ---
int soilPin = A0;
int relayPin = 6;   // n?u xài relay
int ledOn = 8;
int ledOff = 9;

int buttonMode = 10;
int buttonAction = 11;

// ==========================================
//     L298N Motor Driver
// ==========================================
int IN1 = 3;
int IN2 = 5;
int ENA = 6;          // PWM
int motorSpeed = 200; // T?C Ð? C? Ð?NH

// ==========================================
// TR?NG THÁI H? TH?NG
// ==========================================
bool pumpState = false;
bool isManual = false;
bool isAdmin = false;
bool isLock = false;

bool modeJustPressed = false;

int lastModeState = HIGH;
int lastActionState = HIGH;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

bool isWateringCycle = false;
unsigned long wateringStartTime = 0;
const unsigned long WATERING_DURATION = 30000;

float t = 0, h = 0;
int raw_soil = 0;
int percent_soil = 0;

unsigned long lastDhtRead = 0;

int current_crop_id = 0;
const int MAX_CROP_ID = 1;
const char* cropNames[] = {"Coffee", "Wheat"};

unsigned long lastLcdUpdate = 0;
const unsigned long lcdInterval = 500;

unsigned long lastSerial = 0;


// ==========================================
// 2. HÀM B?T/T?T BOM
// ==========================================

// --- B?t/t?t Motor L298N ---
void motorOn() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, motorSpeed);
}

void motorOff() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);
}

// --- HÀM QU?N LÝ PUMP (GI? NGUYÊN) ---
void setPump(bool on) {
  pumpState = on;

  // LED báo
  digitalWrite(ledOn, on ? LOW : HIGH);
  digitalWrite(ledOff, on ? HIGH : LOW);

  // Bom b?ng L298N
  if (on) motorOn();
  else motorOff();

  // (N?u mu?n xài relay thì m? dòng du?i)
  // digitalWrite(relayPin, on ? HIGH : LOW);
}


// ==========================================
// 3. NH?N L?NH T? PYTHON
// ==========================================
void receiveFromPython() {
  if (!Serial.available()) return;

  char cmd = Serial.read();

  if (cmd == 'A') {
    isAdmin = true;
    isLock = false;
  }
  else if (cmd == 'L') {
    isLock = true;
    isAdmin = false;
    isManual = false;
    setPump(false);
    isWateringCycle = false;

    lcd.clear();
    lcd.setCursor(0,0); lcd.print("SYSTEM LOCKED!");
    lcd.setCursor(0,1); lcd.print("STRANGER!!!");
    delay(1000);
  }
  else if (cmd == 'R') {
    isLock = false;
    isAdmin = false;
    isManual = false;
  }
  else if (cmd >= '0' && cmd <= '9') {
    int new_id = cmd - '0';
    if (new_id <= MAX_CROP_ID) {
      current_crop_id = new_id;
      isWateringCycle = false;
      setPump(false);
      lcd.clear();
    }
  }
}


// ==========================================
// 4. Ð?C C?M BI?N
// ==========================================
void readSensors() {
  raw_soil = analogRead(soilPin);
  percent_soil = map(raw_soil, 0, 1023, 100, 0);

  if (millis() - lastDhtRead > 2000) {
    lastDhtRead = millis();
    float nt = dht.readTemperature();
    float nh = dht.readHumidity();
    if (!isnan(nt) && !isnan(nh)) {
      t = nt;
      h = nh;
    }
  }
}


// ==========================================
// 5. NÚT B?M (GI? NGUYÊN LOGIC C?A B?N)
// ==========================================
void handleButtons() {
  int readingMode = digitalRead(buttonMode);

  if (readingMode != lastModeState) lastDebounceTime = millis();

  if ((millis() - lastDebounceTime) > debounceDelay) {
    static int buttonState = HIGH;

    if (readingMode != buttonState) {
      buttonState = readingMode;

      if (buttonState == LOW) {
        isManual = !isManual;
        setPump(false);
        isWateringCycle = false;
        modeJustPressed = true;
        lcd.clear();
      }
    }
  }

  lastModeState = readingMode;

  if (!modeJustPressed) {
    int readingAction = digitalRead(buttonAction);
    static unsigned long lastDebAct = 0;
    static int actState = HIGH;

    if (readingAction != lastActionState) lastDebAct = millis();

    if ((millis() - lastDebAct) > debounceDelay) {
      if (readingAction != actState) {
        actState = readingAction;
        if (actState == LOW) {
          if (isManual) {
            setPump(!pumpState);
          } else {
            current_crop_id++;
            if (current_crop_id > MAX_CROP_ID) current_crop_id = 0;
            lcd.clear();
          }
        }
      }
    }
    lastActionState = readingAction;
  } 
  else modeJustPressed = false;
}


// ==========================================
// 6. AI AUTO MODE (GI? NGUYÊN)
// ==========================================
void runAutoMode() {

  if (isWateringCycle) {
    if (millis() - wateringStartTime >= WATERING_DURATION) {
      setPump(false);
      isWateringCycle = false;
      lcd.clear();
    }
  }
  else {
    static unsigned long lastAI = 0;

    if (millis() - lastAI > 1000) {
      lastAI = millis();

      float input[] = { (double)current_crop_id, (double)raw_soil, (double)t, (double)h };
      float output[2];

      score(input, output);

      if (output[0] > 0.5) {
        setPump(false);
        isWateringCycle = true;
        wateringStartTime = millis();
      } 
      else setPump(true);
    }
  }
}


// ==========================================
// 7. G?I D? LI?U PYTHON
// ==========================================
void sendToPython() {
  if (millis() - lastSerial > 500) {
    Serial.print(current_crop_id);
    Serial.print(",");
    Serial.print(raw_soil);
    Serial.print(",");
    Serial.print(t);
    Serial.print(",");
    Serial.print(h);
    Serial.print(",");
    Serial.print(pumpState ? 1 : 0);
    Serial.print(",");
    Serial.println(isManual ? 1 : 0);
    lastSerial = millis();
  }
}


// ==========================================
// 8. LCD HI?N TH? (GI? NGUYÊN)
// ==========================================
void updateScreen() {
  if (millis() - lastLcdUpdate >= lcdInterval) {
    lastLcdUpdate = millis();
    lcd.setCursor(0,0);

    if (isLock) {
      lcd.print("LOCKED:STRANGER ");
    }
    else if (isManual) {
      lcd.print("MANUAL P:");
      lcd.print(pumpState ? "ON " : "OFF");
    }
    else {
      lcd.print("AT:");
      lcd.print(cropNames[current_crop_id]);
      lcd.print(isAdmin ? " ADM" : " AI ");
    }

    lcd.setCursor(0,1);

    if (isLock) {
      lcd.print("SYSTEM LOCK... ");
    } else {
      lcd.print("S:");
      lcd.print(percent_soil);
      lcd.print("% T:");
      lcd.print((int)t);
      lcd.print(" H:");
      lcd.print((int)h);
    }
  }
}


// ==========================================
// 9. SETUP
// ==========================================
void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.init();
  lcd.backlight();

  pinMode(relayPin, OUTPUT);
  pinMode(ledOn, OUTPUT);
  pinMode(ledOff, OUTPUT);

  pinMode(buttonMode, INPUT_PULLUP);
  pinMode(buttonAction, INPUT_PULLUP);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  setPump(false);

  lcd.setCursor(0,0);
  lcd.print("SMART GARDEN AI");
  delay(1500);
  lcd.clear();
}


// ==========================================
// 10. LOOP CHÍNH
// ==========================================
void loop() {
  receiveFromPython();
  readSensors();

  if (isAdmin && !isLock)
    handleButtons();
  else {
    if (!digitalRead(buttonMode) || !digitalRead(buttonAction)) {
      lcd.setCursor(0,0);
      lcd.print("ACCESS DENIED  ");
      delay(300);
      lcd.clear();
    }
  }

  if (isLock) setPump(false);
  else if (isManual) {} 
  else runAutoMode();

  sendToPython();
  updateScreen();
}
