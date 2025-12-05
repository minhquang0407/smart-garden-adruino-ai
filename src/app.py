import streamlit as st
import cv2
from ultralytics import YOLO
import serial
import time
import numpy as np
import face_recognition 

# --- CẤU HÌNH ---
st.set_page_config(page_title="Smart Garden AI Pro", layout="wide", page_icon="🌱")

# --- CSS ---
st.markdown("""
    <style>
        .stMetric { background-color: #f8f9fa; border-radius: 10px; padding: 10px; border: 1px solid #ddd; }
        div[data-testid="stImage"] { border: 2px solid #4CAF50; border-radius: 10px; }
        .stButton button { width: 100%; font-weight: bold; }
    </style>
""", unsafe_allow_html=True)

# --- SESSION STATE ---
if 'ser' not in st.session_state: st.session_state.ser = None
if 'is_connected' not in st.session_state: st.session_state.is_connected = False
if 'current_state' not in st.session_state: st.session_state.current_state = "R"
if 'last_interaction_time' not in st.session_state: st.session_state.last_interaction_time = time.time()
if 'last_sent_crop_time' not in st.session_state: st.session_state.last_sent_crop_time = 0
if 'owner_encoding' not in st.session_state: st.session_state.owner_encoding = None

# --- CONSTANTS ---
MODEL_PATH = 'models/best.pt' 
TIMEOUT_SECONDS = 5 * 60
SECURITY_MAP = {'Others': 'R', 'Admin': 'A', 'Strange': 'L'}
CROP_MAP_SEND = {'Coffee': '0', 'wheat': '1'} 
CROP_NAMES_DISPLAY = ["Coffee", "Flowers", "Groundnuts", "Maize", "Paddy", "Potato", "Pulse", "Sugarcane", "Wheat"]

def load_owner_face():
    if st.session_state.owner_encoding is None:
        try:
            # Load ảnh chủ nhân từ file
            image = face_recognition.load_image_file("owner.jpg")
            # Mã hóa khuôn mặt thành vector số
            encodings = face_recognition.face_encodings(image)
            if len(encodings) > 0:
                st.session_state.owner_encoding = encodings[0]
                st.toast("✅ Đã nạp dữ liệu khuôn mặt chủ nhân!", icon="👤")
            else:
                st.error("⚠️ Không tìm thấy khuôn mặt trong ảnh owner.jpg")
        except FileNotFoundError:
            st.error("❌ Thiếu file owner.jpg! Hãy thêm ảnh của bạn vào.")
        except Exception as e:
            st.error(f"Lỗi Face ID: {e}")

# Gọi hàm nạp ngay khi chạy
load_owner_face()

# --- SIDEBAR ---
with st.sidebar:
    st.header("🔌 Cấu hình")
    input_port = st.text_input("Cổng COM", "COM3")
    col1, col2 = st.columns(2)
    with col1:
        if st.button("Kết nối", type="primary"):
            try:
                if st.session_state.ser: st.session_state.ser.close()
                st.session_state.ser = serial.Serial(input_port, 9600, timeout=0.1)
                time.sleep(2)
                st.session_state.is_connected = True
                st.toast("Kết nối thành công!", icon="✅")
            except Exception as e: st.error(f"Lỗi: {e}")
    with col2:
        if st.button("Ngắt kết nối"):
            if st.session_state.ser: st.session_state.ser.close()
            st.session_state.ser = None
            st.session_state.is_connected = False

# --- LOAD YOLO ---
@st.cache_resource
def load_yolo():
    return YOLO(MODEL_PATH)

try:
    model = load_yolo()
except:
    st.error("Lỗi Model YOLO")
    st.stop()

# --- HÀM GỬI LỆNH ---
def set_state(action_name):
    new_code = SECURITY_MAP[action_name]
    if new_code != st.session_state.current_state:
        if st.session_state.ser and st.session_state.is_connected:
            try: st.session_state.ser.write(new_code.encode())
            except: pass
        st.session_state.current_state = new_code

# --- UI CHÍNH ---
st.title("🌱 HỆ THỐNG GIÁM SÁT TƯỚI TIÊU (DYNAMIC AI)")
col_cam, col_data = st.columns([2, 1])
with col_cam:
    st.subheader("Camera Giám Sát")
    cam_placeholder = st.empty()
    stop_cam = st.checkbox("Tắt Camera", value=False)
with col_data:
    st.subheader("Trạng thái")
    m_security = st.empty()
    m_info = st.empty()
    m_crop = st.empty()

# --- MAIN LOOP ---
if not stop_cam:
    cap = cv2.VideoCapture(0)
    if not cap.isOpened(): st.error("Lỗi Camera")
    else:
        set_state("Others")
        
        while not stop_cam:
            ret, frame = cap.read()
            if not ret: break
            
            small_frame = cv2.resize(frame, (0, 0), fx=0.25, fy=0.25)
            rgb_small_frame = cv2.cvtColor(small_frame, cv2.COLOR_BGR2RGB)

            face_locations = face_recognition.face_locations(rgb_small_frame)
            face_encodings = face_recognition.face_encodings(rgb_small_frame, face_locations)

            is_owner_detected = False
            is_stranger_detected = False

            for face_encoding in face_encodings:
                if st.session_state.owner_encoding is not None:
                    matches = face_recognition.compare_faces([st.session_state.owner_encoding], face_encoding, tolerance=0.5)
                    if True in matches:
                        is_owner_detected = True
                    else:
                        is_stranger_detected = True 

            now = time.time()
            security_status = "AUTO / GIÁM SÁT"
            color_status = "off"

            if is_owner_detected:
                st.session_state.last_interaction_time = now
                set_state('Admin')
                security_status = "🔓 CHÀO CHỦ NHÂN (ADMIN)"
                color_status = "normal"
                cv2.putText(frame, "HELLO OWNER", (20, 50), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)
            
            elif is_stranger_detected:
                set_state('Strange')
                security_status = "🚨 CẢNH BÁO: NGƯỜI LẠ"
                color_status = "inverse"
                cv2.putText(frame, "LOCKED", (20, 50), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 2)
                for (top, right, bottom, left) in face_locations:
                    top *= 4; right *= 4; bottom *= 4; left *= 4 # Scale lại toạ độ
                    cv2.rectangle(frame, (left, top), (right, bottom), (0, 0, 255), 2)

            else:
                if st.session_state.current_state == 'A':
                    left = TIMEOUT_SECONDS - (now - st.session_state.last_interaction_time)
                    if left > 0:
                        security_status = f"⏳ ADMIN CÒN: {int(left)}s"
                        m_info.info("Đang chờ tương tác...")
                    else:
                        set_state("Others")
                elif st.session_state.current_state == 'L':
                    set_state("Others")
                
                if st.session_state.current_state == 'R':
                    results = model(frame, verbose=False, conf=0.5)
                    detected_crops = []
                    for r in results:
                        for c in r.boxes.cls:
                            name = model.names[int(c)]
                            detected_crops.append(name)
                            
                    frame = results[0].plot()

                    if now - st.session_state.last_sent_crop_time > 2.0:
                        for obj in detected_crops:
                            obj_lower = obj.lower()
                            for key in CROP_MAP_SEND:
                                if key.lower() == obj_lower:
                                    if st.session_state.is_connected and st.session_state.ser:
                                        try: st.session_state.ser.write(CROP_MAP_SEND[key].encode())
                                        except: pass
                                    st.session_state.last_sent_crop_time = now
                                    m_crop.success(f"Phát hiện: {obj}")
                                    break

            m_security.metric("Trạng thái An Ninh", security_status, delta_color=color_status)

            frame_rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
            cam_placeholder.image(frame_rgb, channels="RGB", use_container_width=True)
            time.sleep(0.01)

    cap.release()
