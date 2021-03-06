# Robot_Package_Retrieval

## Objective <br> 
The objective of our project is to design and build an automated robot car that will use different sensors to locate, retrieve and drop off a package to a predetermined location. The objective is to create an autonomous vehicle that can retrieve a package and return it back to the vehicle’s starting position. An Arduino and Raspberry Pi is used to aid in making the vehicle autonomous. The ultrasonic sensor along with a camera module are the equivalent of a pair of eyes for the vehicle. The chassis of the vehicle was first drafted in AutoCAD and later translated over to SolidWorks for more ease of use when viewing the design. The car will be utilizing two motors to drive the car. One will be for the front, and another will be for the rear wheels. The car will be rear wheel drive meaning the back 2 wheels will oversee generating all the power while the front 2 wheels are going to oversee directional motion.<br> 

## Results and Discussion<br> 

 ![Image1](/images/1.png)  
Figure 1. This is a flow chart of our robot package retrieval system.<br>
 
  ![Image2](/images/2.jpg)  
Figure 2. Min-Max normalization formula [1]. <br>
 
  ![Image3](/images/3.jpg)  
Figure 3. The finished product.<br>   
According to the Figure 1, the main purpose for the Arduino is to oversee the movement functions of the vehicle. For more accuracy distance measurement between either obstacles or the package, an ultralight sensor is used to navigate how close the front of the vehicle is to the object in front of it. By utilized Min-Max normalization formula from Figure 2, the sensor able to scale a range from 0 to 180 to the output of -1 to 1 [1]. The range from -1 to 1 is a value representing the location of the servo in the Servo class from gpiozero library [2]. Using formula, the servo motor can have 0-to180-degree rotational freedom. A simple code to allow the servo motor to be able to rotate back and forth from 0-to-180-degrees. <br> <br> 
For the ultrasonic sensor, it essentially has two sensors called transmitter and receiver. The way it works is that the transmitter sends a waveform signal. This wave signal would then hit a particular object. The waveform signal would then bounce back from the object to the receiver [3]. By calculating the time duration between the time, the sensor transmits and receives, it allows one to detect how close an object is to the sensor. This is done by utilizing speed distance formula which states that distance=duration*speed. Speed is derived from the speed of sound 0.13385 in/us (in standard). This is converted from speed of v = 343m/s. Recall that the time duration is between the time it leaves the transmitter and receivers. The time value would need to divide by 2 to derive the true distance between sensor and an object. So, the formula of distance =duration*(in standard/2). For the implementation, essentially a high signal is sent for 15ms and then a low signal is sent from the transmitter. The time will start recording once the high signal hits the receiver. The recording time would stop after the receiver receives a low signal. This is the time duration. By utilizing the formula above, the distance between an object and the sensor can be determined.  <br> 


## Work Cited <br> 

[1] “How to scale data into the 0-1 range using min-max normalization.,” knowledge Transfer, 29-Aug-2021. [Online]. Available: https://androidkt.com/how-to-scale-data-to-range-using-minmax-normalization/. [Accessed: 20-Mar-2022]. <br> 
[2] E. Gobler, “USPS or Amazon package stolen?,” CNET, 04-Nov-2021. [Online]. Available: https://www.cnet.com/home/security/protect-your-packages-from-porch-pirates-7-practical-tips/. [Accessed: 17-May-2022]. <br> 
[3] “How to scale data into the 0-1 range using min-max normalization.,” knowledge Transfer, 29-Aug-2021. [Online]. Available: https://androidkt.com/how-to-scale-data-to-range-using-minmax-normalization/. [Accessed: 20-Mar-2022]. <br> 

