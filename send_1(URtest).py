import serial
import time

ser = serial.Serial("COM5", 115200)
time.sleep(2)  # 等 ESP32 重啟穩定

try:
    while True:
        ser.write(b'1')
        print("Sent '1'")
        time.sleep(3)
except KeyboardInterrupt:
    print("中斷，關閉序列埠")
    ser.close()
