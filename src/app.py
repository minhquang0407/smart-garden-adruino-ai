import streamlit as st
import cv2
from ultralytics import YOLO
import serial
import time
import numpy as np

# --- CẤU HÌNH TRANG WEB ---
st.set_page_config(page_title="Smart Garden AI Master", layout="wide", page_icon="🌱")

# CSS làm đẹp
st.markdown("""
    <style>
        /* Khung chứa Metric */
        div[data-testid="stMetric"] {
            background-color: #f8f9fa; /* Màu xám rất nhạt */
            border: 1px solid #e0e0e0;
            padding: 15px;
            border-radius: 10px;
            box-shadow: 2px 2px 5px rgba(0,0,0,0.1); /* Đổ bóng nhẹ */
        }

        /* Chữ tiêu đề (Label) của Metric */
        div[data-testid="stMetric"] label {
            color: #333333 !important; /* Màu đen đậm */
            font-weight: bold;
            font-size: 1.1rem;
        }

        /* Chữ giá trị (Value) của Metric */
        div[data-testid="stMetric"] div[data-testid="stMetricValue"] {
            color: #000000 !important; /* Màu đen tuyền */
            font-weight: 900; /* Rất đậm */
        }

        /* Khung hình ảnh */
        div[data-testid="stImage"] {
            border: 3px solid #4CAF50;
            border-radius: 10px;
        }

        /* Nút bấm */
        .stButton button {
            width: 100%;
            font-weight: bold;
        }
    </style>
""", unsafe_allow_html=True)

# --- KHỞI TẠO SESSION STATE (Biến toàn cục) ---
if 'ser' not in st.session_state: st.session_state.ser = None
if 'is_connected' not in st.session_state: st.session_state.is_connected = False
if 'current_state' not in st.session_state: st.session_state.current_state = "R"
if 'last_interaction_time' not in st.session_state: st.session_state.last_interaction_time = time.time()
if 'last_sent_crop_time' not in st.session_state: st.session_state.last_sent_crop_time = 0

# --- CẤU HÌNH HẰNG SỐ ---
MODEL_PATH = 'models/best.pt'
TIMEOUT_SECONDS = 5 * 60
SECURITY_MAP = {'Others': 'R', 'Admin': 'A', 'Strange': 'L'}
CROP_MAP_SEND = {'Coffee': '0', 'wheat': '1'}
CROP_NAMES_DISPLAY = ["Coffee", "Wheat"]

# --- SIDEBAR: CẤU HÌNH KẾT NỐI (ĐÃ TRẢ LẠI CHO BẠN) ---
with st.sidebar:
    st.header("🔌 Cấu hình")
    input_port = st.text_input("Cổng COM", "COM12")

    col_btn1, col_btn2 = st.columns(2)

    with col_btn1:
        if st.button("Kết nối", type="primary"):
            try:
                if st.session_state.ser: st.session_state.ser.close()
                st.session_state.ser = serial.Serial(input_port, 9600, timeout=0.1)
                time.sleep(2)
                st.session_state.is_connected = True
                st.toast("✅ Kết nối thành công!", icon="🔌")
            except Exception as e:
                st.error(f"Lỗi: {e}")

    with col_btn2:
        if st.button("Ngắt kết nối"):
            if st.session_state.ser:
                st.session_state.ser.close()
            st.session_state.ser = None
            st.session_state.is_connected = False
            st.toast("Đã ngắt kết nối.", icon="zzz")

    st.divider()
    st.info("Trạng thái: " + ("🟢 Online" if st.session_state.is_connected else "🔴 Offline"))


# --- LOAD MODEL ---
@st.cache_resource
def load_model():
    return YOLO(MODEL_PATH)


try:
    model = load_model()
except:
    st.error("❌ Lỗi Model! Kiểm tra đường dẫn.")
    st.stop()


# --- HÀM GỬI LỆNH ---
def set_state(action_name):
    new_code = SECURITY_MAP[action_name]
    if new_code != st.session_state.current_state:
        if st.session_state.ser and st.session_state.is_connected:
            try:
                st.session_state.ser.write(new_code.encode())
                print(f"👉 Gửi lệnh: {new_code}")
            except:
                pass
        st.session_state.current_state = new_code


# ==========================================
# GIAO DIỆN CHÍNH
# ==========================================
st.title("🌱 TRUNG TÂM ĐIỀU KHIỂN VƯỜN THÔNG MINH")

col_cam, col_data = st.columns([2, 1])

with col_cam:
    st.subheader("📹 Camera AI")
    cam_placeholder = st.empty()

    # Nút dừng Camera (Chỉ là biến local để break vòng lặp)
    stop_cam = st.checkbox("Tắt Camera", value=False)

with col_data:
    st.subheader("📊 Thông số Arduino")
    m_crop = st.empty()
    m_soil = st.empty()
    m_env = st.empty()
    m_pump = st.empty()
    m_mode = st.empty()
    st.divider()
    m_security = st.empty()
    m_timer = st.empty()

# ==========================================
# VÒNG LẶP CHÍNH (Chỉ chạy khi chưa bấm Tắt Camera)
# ==========================================
if not stop_cam:
    cap = cv2.VideoCapture(0)

    if not cap.isOpened():
        st.error("❌ Không bật được Camera")
    else:
        # Gửi lệnh Reset
        set_state("Others")

        while not stop_cam:
            ret, frame = cap.read()
            if not ret: break

            # 1. YOLO AI
            results = model(frame, verbose=False, conf=0.1)
            detected_objects = []
            for r in results:
                for c in r.boxes.cls:
                    detected_objects.append(model.names[int(c)])

            now = time.time()
            security_text = "BÌNH THƯỜNG"
            security_color = "off"

            # 2. LOGIC AN NINH
            if 'Admin' in detected_objects:
                st.session_state.last_interaction_time = now  # Reset đồng hồ
                set_state('Admin')

                # Hiển thị thông báo thân thiện
                cv2.putText(frame, "HELLO OWNER - ACCESS GRANTED", (20, 50),
                            cv2.FONT_HERSHEY_SIMPLEX, 0.8, (0, 255, 0), 2)

                # Nếu có người lạ đứng cạnh, báo thêm (cho ngầu)
                if 'Strange' in detected_objects:
                    cv2.putText(frame, "(Guest Detected)", (20, 80),
                                cv2.FONT_HERSHEY_SIMPLEX, 0.6, (0, 255, 255), 1)
            elif 'Strange' in detected_objects and st.session_state.current_state != 'R':
                set_state('Strange')
                security_text = "PHÁT HIỆN NGƯỜI LẠ!"
                security_color = "inverse"
                cv2.putText(frame, "LOCKED", (50, 50), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 2)
            else:
                set_state("Others")
                if st.session_state.current_state == 'R':
                    m_timer.empty()
                    if now - st.session_state.last_sent_crop_time > 2.0:
                        for obj in detected_objects:
                            if obj in CROP_MAP_SEND:
                                if st.session_state.is_connected and st.session_state.ser:
                                    try:
                                        st.session_state.ser.write(CROP_MAP_SEND[obj].encode())
                                    except:
                                        pass
                                st.session_state.last_sent_crop_time = now
                                break

            m_security.metric("Trạng thái", security_text, delta_color=security_color)

            # 3. ĐỌC ARDUINO (Khi đã kết nối)
            if st.session_state.is_connected and st.session_state.ser:
                if st.session_state.ser.in_waiting > 0:
                    try:
                        line = st.session_state.ser.readline().decode('utf-8').strip()
                        parts = line.split(',')

                        if len(parts) >= 6:
                            crop_id = int(parts[0])
                            raw_soil = int(parts[1])
                            t = float(parts[2])
                            h = float(parts[3])
                            pump = int(parts[4])
                            is_manual = int(parts[5])

                            soil_pct = max(0, min(100, (1 - raw_soil / 1023) * 100))

                            c_name = CROP_NAMES_DISPLAY[crop_id] if 0 <= crop_id < len(
                                CROP_NAMES_DISPLAY) else "Unknown"

                            m_crop.metric("Loại Cây", c_name)
                            m_soil.metric("Độ Ẩm Đất", f"{soil_pct:.1f}%", f"{raw_soil} ADC")
                            m_env.metric("Môi Trường", f"{t}°C / {h}%")

                            pump_lbl = "ĐANG CHẠY 💦" if pump == 1 else "ĐANG TẮT 💤"
                            m_pump.metric("Máy Bơm", pump_lbl, delta_color="inverse" if pump == 1 else "off")

                            mode_lbl = "THỦ CÔNG (MANUAL)" if is_manual == 1 else "TỰ ĐỘNG (AI)"
                            m_mode.info(f"Chế độ: {mode_lbl}")
                    except:
                        pass

            # 4. VẼ HÌNH
            annotated_frame = results[0].plot()
            frame_rgb = cv2.cvtColor(annotated_frame, cv2.COLOR_BGR2RGB)
            cam_placeholder.image(frame_rgb, channels="RGB", use_container_width=True)

            time.sleep(0.01)

    cap.release()
else:

    st.warning("Camera đã tắt.")
