from gpiozero import Servo
from time import sleep

servo = Servo(12, min_pulse_width=0.5/1000, max_pulse_width=2.5/1000)

a = -1
b = 1
    
min1 = 0
max2 = 360
mode1 = True
mode2 = False
i =0    
    
while True:
    if (i==180):
        mode1 =False
        mode2 =True
    if (i==0):
        mode1= True
        mode2 = False
    
    if(mode1):
        i= i+1
    if(mode2):
       i = i-1
       
       
    servo.value  = (1.0*(b-a)*(i-min1)/(max2-min1)) + a;   
    sleep(0.02)
