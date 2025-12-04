<img width="1824" height="796" alt="image" src="https://github.com/user-attachments/assets/c2d5da99-91cd-48e3-aa9d-fbfbd1f527ac" /># 🌱 Smart Garden AI - Hệ Thống Tưới Tiêu Thông Minh Đa Giác Quan

![Python](https://img.shields.io/badge/Python-3.10+-blue.svg)
![Arduino](https://img.shields.io/badge/Hardware-Arduino_Uno-teal.svg)
![AI](https://img.shields.io/badge/AI-Random_Forest_%26_YOLOv11-orange.svg)
![Dashboard](https://img.shields.io/badge/Dashboard-Streamlit-red.svg)

## 📖 Giới thiệu (Overview)

**Smart Garden AI** là một hệ thống IoT nông nghiệp công nghệ cao, giải quyết bài toán tưới tiêu tự động dựa trên dữ liệu cảm biến và hình ảnh thực tế.

Dự án tạo ra sự đột phá bằng cách kết hợp **Edge AI (Trí tuệ nhân tạo tại biên)** chạy trực tiếp trên vi điều khiển Arduino Uno (Random Forest) và **Computer Vision (Thị giác máy tính)** chạy trên máy tính (YOLOv8), mang lại khả năng chăm sóc cây trồng chính xác và bảo mật an ninh cho khu vườn.

---

## 🚀 Tính năng Nổi bật (Key Features)

### 1. 🧠 Edge AI trên Vi điều khiển (Arduino)
- Sử dụng thuật toán **Random Forest (Mini)** đã được tối ưu hóa để chạy trên chip ATmega328P (32KB Flash).
- Tự động ra quyết định tưới dựa trên: *Độ ẩm đất, Nhiệt độ, Độ ẩm không khí, Loại cây*.
- Hoạt động độc lập ngay cả khi mất kết nối với máy tính.

### 2. 👁️ Computer Vision (YOLOv8)
- Tự động nhận diện loại cây (Lúa, Ngô, Cà phê...) qua Camera và gửi lệnh cấu hình xuống Arduino.
- **Tính năng An ninh:**
    - Nhận diện **Chủ nhân**: Mở khóa quyền điều khiển (Admin Mode).
    - Nhận diện **Người lạ**: Tự động khóa hệ thống, ngắt bơm khẩn cấp (Security Lock).

### 3. 📊 Dashboard Giám sát (Streamlit)
- Giao diện Web App hiện đại, hiển thị biểu đồ thời gian thực (Real-time plotting).
- Điều khiển bật/tắt bơm, chuyển chế độ từ xa.
- Theo dõi trạng thái kết nối và log hoạt động.

### 4. 🛡️ Cơ chế An toàn & Logic
- **Non-blocking Timer:** Hệ thống đa nhiệm, không dùng `delay()`.
- **Anti-Chattering:** Chống nhiễu bơm bằng chu trình tưới thông minh (Holding Cycle).
- **Session Timeout:** Tự động khóa quyền Admin sau 5 phút không tương tác.

---

## 🛠️ Kiến trúc Hệ thống (System Architecture)

### Phần cứng (Hardware)
* **Vi điều khiển:** Arduino Uno R3.
* **Cảm biến:**
    * Capacitive Soil Moisture Sensor v1.2 (Độ ẩm đất).
    * DHT11 (Nhiệt độ & Độ ẩm không khí).
* **Cơ cấu chấp hành:** Relay 5V + Máy bơm mini.
* **Hiển thị:** LCD 1602 I2C.
* **Input:** 2 Nút bấm (Mode & Action).

### Công nghệ Phần mềm (Tech Stack)
* **Python:**
    * `Ultralytics YOLOv11`: Nhận diện vật thể.
    * `Scikit-learn`: Huấn luyện mô hình Random Forest.
    * `m2cgen`: Chuyển đổi model Python sang C++.
    * `Streamlit`: Giao diện người dùng.
    * `PySerial`: Giao tiếp UART.
* **Arduino (C++):** Xử lý logic thời gian thực, đọc cảm biến.

---

## ⚙️ Cài đặt & Hướng dẫn (Installation)

### 1. Phần cứng (Arduino)
1.  Kết nối cảm biến theo sơ đồ:
    - Soil Sensor: A0
    - DHT11: D4
    - Relay: D6
    - Buttons: D10, D11
    - LCD: I2C (SDA/SCL)
2.  Mở `smart_irrigation_with_adruinoUno/arduino_firmware/main.ino` bằng Arduino IDE.
3.  Cài đặt thư viện: `LiquidCrystal_I2C`, `DHT sensor library`.
4.  Nạp code vào mạch.

### 2. Phần mềm (Python)
1.  Cài đặt các thư viện cần thiết:
    ```bash
    pip install streamlit ultralytics pyserial opencv-python scikit-learn pandas m2cgen
    ```
2.  Huấn luyện hoặc tải model YOLO (`best.pt`) vào thư mục dự án.
3.  Kết nối Arduino với máy tính qua cổng USB.
4.  Chạy ứng dụng:
    ```bash
    streamlit run src/app.py
    ```

---

## 🧠 Phương pháp Huấn luyện AI (AI Methodology)

### Random Forest (Tưới tiêu)
* **Dataset:** Dữ liệu thu thập thực tế + Chuyên gia giả lập (Expert System).
* **Dataset Path:** smart_irrigation_with_adruinoUno\ai_training\RandomForest\irrigation.csv 
* **Validation:** Sử dụng **Stratified 5-Fold Cross-Validation** để đánh giá độ ổn định.
* **Cấu hình tối ưu:** `n_estimators=5`, `max_depth=10` (Độ chính xác ~92.66% trên tập kiểm thử).
* **Triển khai:** Model được huấn luyện lại trên 100% dữ liệu và transpile sang C (`model.h`).

### YOLOv8 (Thị giác)
* **Dataset:** Tự thu thập và gán nhãn thủ công cho các lớp: *Coffee, Wheat, Owner, Stranger*.
* **Dataset Link: https://drive.google.com/file/d/1o6WhIhmDbxElmCeNoEqlcfEF4jM2tlPX/view?usp=sharing**
* **Training:** Fine-tuning từ `yolo8n.pt`.

---

## 📸 Hình ảnh Demo

### 1. Giao diện Streamlit
*[CHÈN ẢNH CHỤP MÀN HÌNH DASHBOARD CỦA BẠN VÀO ĐÂY]*

### 2. Sơ đồ đấu nối (Wiring)
*[CHÈN ẢNH MẠCH ĐIỆN HOẶC SƠ ĐỒ FRITZING VÀO ĐÂY]*

### 3. Hoạt động thực tế
*[CHÈN ẢNH LCD HIỂN THỊ HOẶC GIF DEMO]*

---

## 🤝 Đóng góp
Dự án được thực hiện bởi **[Nguyễn Minh Quang]** - Sinh viên  [HCMUS].


---
*If you find this project useful, please give it a star! ⭐*
