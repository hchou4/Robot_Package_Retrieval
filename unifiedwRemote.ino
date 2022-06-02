#include <Servo.h>
#include <IRremote.h>

int IRReceiverP = 12;
IRrecv irrecv(IRReceiverP);
decode_results results;



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

  //IRreceiver
  Serial.begin(9600);

  irrecv.enableIRIn(); // turn on the IR receiver
   

  //END IRreceiver





  
  
  //set up stop
  pinMode(stpnServoP,INPUT);
  

  
  // put your setup code here, to run once:
  servo.attach(8);
  servo.write(0); //start at 180 position
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
  
  int A = 100;
     
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

    //Print out
    Serial.print("Distance: ");
    Serial.println(distance);
    
  //distance = 6;
    
//    if(distance >5) // greater than 5 inches
//    {
//       if (distance > 30)
//       {
//          A = 255;//Full speed
//       }else
//       {
//          A = 100;
//       }
       
  
    //IR
    if(irrecv.decode(&results)){
     Serial.println(results.value, HEX);

     irrecv.resume();

     switch (results.value) {
       case 0xFF5AA5: // left arrow
          Serial.println("Left arrow registered");
          servo.write(145); // turn 45 degree angle servo motor to the right
          break;
       case 0xFF10EF: //right arrow
          Serial.println("Right arrow registered");
          servo.write((-145)); // turn 45 degree angle servo motor to the left
          break;
       case 0xFF18E7: // top arrow
          Serial.println("Top arrow registered");
          Go_forward(m1pin1,m1pin2,enmA,A);
          break;
       case 0xFF4AB5: //down arrow
          Serial.println("Down arrow registered");
          Go_backward(m1pin1,m1pin2,enmA,A);
          break;
       case 0xFF38C7: // ok button stop
          Serial.println("OK registered");
          Turn_off_motor(m1pin1,m1pin2,enmA,A);
          break;

       case 0xFF9867: //0 button for start
          Serial.println("0 registered");
          Turn_on_motor(m1pin1,m1pin2,enmA,A);
          break;
       
       case 0xFF6897: // * 
          Serial.println("* key registered");
          if(A==255)
          {
            A = 255;
          }else
          {
            A= A +5;
          }
          
          break;
          
       case 0xFFB04F: // #
          Serial.println("# key registered");
          if(A==0)
          {
            A =0;
          }else{
            A = A -5;

          }
          
          break;

       
     }
    
    
  }
      

       

       
//    }else
//    {
//      digitalWrite(m1pin1,LOW);
//      digitalWrite(m1pin2,LOW);
//    }


  






    delay(50);
  //IR END
  
  
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
void Turn_on_motor (int m1pin1,int m1pin2, int enmA, int A)
{
    digitalWrite(m1pin1,HIGH);
    digitalWrite(m1pin2,HIGH);
    analogWrite(enmA,A);
}
