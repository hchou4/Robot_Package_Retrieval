#include <Servo.h>

Servo servo;
const int trigP =10;
const int echoP = 11;
const int stpnServoP = 8;

//back motor
int enmA = 5;
int m1pin1 = 6;
int m1pin2 = 7;//sdfasdf


const double cm_standard = 0.034;//cm/us  //v= 343m/s = 
const double in_standard = 0.013385;//inch/us
long duration;
double distance;
void setup() {
  //set up stop
  pinMode(stpnServoP,INPUT);
  

  
  // put your setup code here, to run once:
  servo.attach(8);
  servo.write(0);
  delay(2000);

  //ultralight sensor
    // put your setup code here, to run once:
  pinMode(trigP, OUTPUT);
  pinMode(echoP, INPUT);
  Serial.begin(9600);

  //back motor
  pinMode(enmA,OUTPUT);
  pinMode(m1pin1,OUTPUT);
  pinMode(m1pin2,OUTPUT);

}

void loop() {

    //back motor
//  //Forward
//  digitalWrite(m1pin1,HIGH);
//  digitalWrite(m1pin2,LOW);
  int A = 100;
//  analogWrite(enmA,A);
//    delay(1000);
//    A=255;
//  analogWrite(enmA,A);
//      delay(1000);

//
//    //BackWard
//  digitalWrite(m1pin1,LOW);
//  digitalWrite(m1pin2,HIGH);
//  A = 100;
//  analogWrite(enmA,A);
//    delay(1000);
//    A=255;
//  analogWrite(enmA,A);
//      delay(1000);

    //end back motor
    
    //Make sure trig output signal is low
    digitalWrite(trigP,LOW);
    delayMicroseconds(3); //wait 3ms
  
    //send trig signal high.
    digitalWrite(trigP, HIGH);
    delayMicroseconds(15);// for 15ms
    
    digitalWrite(trigP, LOW);//send low
  
    //if echo input is high then start timing and recorded the time 
    //until echo signal is low.
    duration = pulseIn(echoP, HIGH);
    distance = duration*(in_standard/2); // calculate distance, divide by 2 cause the pulse is send two way

    if(distance >5) // greater than 5 inches
    {
       if (distance > 30)
       {
          A = 255;//Full speed
       }else
       {
          A = 100;
       }

       Go_forward(m1pin1,m1pin2,enmA,A);
       
    }else
    {
      digitalWrite(m1pin1,LOW);
      digitalWrite(m1pin2,LOW);
    }


  
    //Print out
    Serial.print("Distance: ");
    Serial.println(distance);

    delay(200);
  
}
void Go_forward (int m1pin1,int m1pin2, int enmA, int A)
{
    digitalWrite(m1pin1,HIGH);
    digitalWrite(m1pin2,LOW);
    analogWrite(enmA,A);
}

void Go_backward (int m1pin1,int m1pin2, int enmA, int A)
{
    digitalWrite(m1pin1,LOW);
    digitalWrite(m1pin2,HIGH);
    analogWrite(enmA,A);
}
void Turn_off_motor (int m1pin1,int m1pin2, int enmA, int A)
{
    digitalWrite(m1pin1,LOW);
    digitalWrite(m1pin2,LOW);
    analogWrite(enmA,A);
}
