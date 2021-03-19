import cv2
from serial import Serial
import time
faceCascade = cv2.CascadeClassifier("Resources/haarcascade_frontalface_alt.xml")
ser = Serial("COM3",baudrate=9600,timeout=1)
cap = cv2.VideoCapture(0)
cap.set(3,640)
cap.set(4,480)
ret, imgResult = cap.read()
while True:
    success, img = cap.read()
    imgGray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    faces = faceCascade.detectMultiScale(imgGray, 1.1, 2)
    for (x,y,w,h) in faces:
        ser.write(str(x).encode())
        time.sleep(1)
        print(x)
        cv2.rectangle(img,(x,y),(x+w,y+w),(255,0,0),2)
        #cv2.line(img, (0,0), (x+int(w/2)+1,y+int(h/2)+1), (0, 255, 0), 5)
        #cv2.putText(img,"test",(x + int(w / 2) + 1, y + int(h / 2) + 1),cv2.FONT_HERSHEY_PLAIN,2, (0, 255, 0), 5)
    cv2.imshow("result", img)

    if cv2.waitKey(1) & 0xFF==ord('q'):
        ser.close()
        break