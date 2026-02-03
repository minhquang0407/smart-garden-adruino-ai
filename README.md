# Smart Garden AI 
**Multi-Sensory Intelligent Irrigation System**

## Overview

**Smart Garden AI** is a high-tech IoT agricultural system that automates irrigation using sensor data and real-time computer vision.

This project implements a hybrid architecture combining **Edge AI** (Random Forest on Arduino Uno) and **Computer Vision** (YOLOv8 on PC) to ensure precise plant care and physical security.

## Key Features

### 1. Edge AI on Microcontroller (Arduino)

* **Embedded ML:** Runs an optimized Random Forest algorithm directly on the ATmega328P chip (32KB Flash).
* **Autonomous Logic:** Decides irrigation cycles based on soil moisture, temperature, air humidity, and plant type without requiring PC connectivity.

### 2. Computer Vision (YOLOv8)

* **Plant Recognition:** Identifies crop types (e.g., Rice, Corn, Coffee) via camera and automatically configures the Arduino parameters.
* **Security System:**
* **Face ID:** Grants "Admin Mode" control upon recognizing the owner.
* **Intrusion Detection:** Automatically locks the system and disables pumps if a stranger is detected.



### 3. Monitoring Dashboard (Streamlit)

* Modern web interface for real-time data plotting.
* Remote control capabilities (pump toggle, mode switching).
* Connection status monitoring and activity logging.

### 4. Safety & Logic Mechanisms

* **Non-blocking Timer:** Multitasking architecture eliminating `delay()` usage.
* **Anti-Chattering:** Prevents pump hardware damage using intelligent holding cycles.
* **Session Timeout:** Auto-locks Admin privileges after 5 minutes of inactivity.

## System Architecture

### Hardware

* **Microcontroller:** Arduino Uno R3.
* **Sensors:** Capacitive Soil Moisture Sensor v1.2 (A0), DHT11 (D4).
* **Actuators:** Relay 5V (D6), Mini Pump.
* **Interface:** LCD 1602 I2C, Control Buttons (D10, D11).

### Tech Stack

* **Python:** `Ultralytics YOLOv11` (Vision), `Scikit-learn` (Training), `m2cgen` (Model Transpilation), `Streamlit` (UI), `PySerial` (UART).
* **C++ (Arduino):** Real-time sensor processing and actuator control.

## AI Methodology

### Random Forest (Irrigation Logic)

* **Data Source:** Real-world sensor data combined with Expert System inputs.
* **Model:** Validated via Stratified 5-Fold Cross-Validation (Accuracy ~92.66%).
* **Deployment:** Transpiled from Python to C code (`model.h`) for embedded execution.

### YOLOv8 (Vision)

* **Dataset:** Custom labeled dataset for classes: *Coffee, Wheat, Owner, Stranger*.
* **Training:** Fine-tuned on the `yolo8n.pt` base model.

## Installation

### 1. Hardware Setup (Arduino)

1. Connect sensors: Soil (A0), DHT11 (D4), Relay (D6), Buttons (D10, D11), LCD (I2C).
2. Install `LiquidCrystal_I2C` and `DHT sensor library` in Arduino IDE.
3. Flash `smart_irrigation_with_adruinoUno/arduino_firmware/main.ino` to the board.

### 2. Software Setup (Python)

**Prerequisite:** Python 3.10 or 3.11.

**Step 1: Install Dependencies**

```bash
pip install -r requirements.txt

```

**Step 2: Install Face Recognition**
*Note: `face-recognition` requires `dlib`.*

* **macOS/Linux:** `pip install face-recognition`
* **Windows:**
1. `pip install cmake`
2. Download the `dlib` .whl file matching your Python version.
3. `pip install <path_to_dlib.whl>`
4. `pip install face-recognition`



**Step 3: Security Configuration**

1. Take a clear portrait photo of yourself.
2. Rename it to `owner.jpg`.
3. Place it in the `smart_irrigation_with_adruinoUno/src` directory.

**Step 4: Launch**
Connect the Arduino via USB and run:

```bash
streamlit run src/app.py

```

## Credits

Developed by **Nguyen Minh Quang** - University of Science, VNU.

---

*If you find this project useful, please give it a star!*
