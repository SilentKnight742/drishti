import serial
from time import sleep

nodemcu=serial.Serial('COM7',9600)

while (nodemcu.isOpen()):
    data=int(input("Enter number"))

    if data==1:
        nodemcu.write(str.encode('1'))
    elif data==2:
        nodemcu.write(str.encode('2'))
    else:
        print("error")