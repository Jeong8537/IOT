import logging
import cv2
import time
from telegram import Update
from telegram.ext import Application, CommandHandler, ContextTypes

logging.basicConfig(
    format="%(asctime)s - %(name)s - %(levelname)s - %(message)s", level=logging.INFO
)

def takePhoto():
    cap = cv2.VideoCapture(0)
    cap.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
    cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)
    if not cap.isOpened():
        print("camera open error")
        return
    ret, image=cap.read()
    if not ret:
        print("frame read error")
        return
    
    time.sleep(1)
    cv2.imwrite("./image.jpg", image)
    cap.release()
    cv2.destroyAllWindows()