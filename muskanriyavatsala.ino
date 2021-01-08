   
 #include <Servo.h> 
int incomingByte=0;
const int motora=2;
const int motorb=3;
const int motorc=4;
const int motord=5;
Servo myservo;  
const int trigPin = 6;
const int echoPin = 7; 
const int sw1=11;
int pos = 0; 
int left=0,right=0;
int sw1state=0,flamestate=0; 
const int flame=10;
const int buzzer=8;
void setup() {
  pinMode(motora, OUTPUT);
   pinMode(motorb, OUTPUT);
    pinMode(motorc, OUTPUT);
     pinMode(motord, OUTPUT);
     digitalWrite (motora,LOW);
                   digitalWrite (motorb,LOW);
                    digitalWrite (motorc,LOW);
                     digitalWrite (motord,LOW); 
     myservo.attach(9);
      pinMode(buzzer, OUTPUT);
       pinMode(flame, INPUT);
        pinMode(sw1,INPUT);
     digitalWrite (buzzer,LOW);
 Serial.begin(9600);
 }
long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
}

void loop() {
 
  sw1state=digitalRead(sw1);
  flamestate=digitalRead(flame);
 if( sw1state==1)
  {
    flamestate=digitalRead(flame);
    if(flamestate==0)
    {
       digitalWrite (motora,LOW);
                   digitalWrite (motorb,LOW);
                    digitalWrite (motorc,LOW);
                     digitalWrite (motord,LOW);
                digitalWrite (buzzer,HIGH);      
      
      }
          if(flamestate==1)
    {
 
                digitalWrite (buzzer,LOW);      
      
      }
  long duration, cm;
   pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  cm = microsecondsToCentimeters(duration);
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  myservo.write(90); // tell servo to go to position in variable 'pos' 
    delay(30); 
     digitalWrite (motora,HIGH);
                   digitalWrite (motorb,LOW);
                    digitalWrite (motorc,HIGH);
                     digitalWrite (motord,LOW);

  if(cm<30)
  {
     digitalWrite (motora,LOW);
                   digitalWrite (motorb,LOW);
                    digitalWrite (motorc,LOW);
                     digitalWrite (motord,LOW);
                     delay(50);
                  digitalWrite (motora,LOW);
                   digitalWrite (motorb,HIGH);
                    digitalWrite (motorc,LOW);
                     digitalWrite (motord,HIGH);
                     delay(700);
                      digitalWrite (motora,LOW);
                   digitalWrite (motorb,LOW);
                    digitalWrite (motorc,LOW);
                     digitalWrite (motord,LOW);
                                    
   for(pos = 90; pos <= 175; pos += 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(10);                       // waits 15ms for the servo to reach the position 
  }

   
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  cm = microsecondsToCentimeters(duration);
  left=cm;
  delay(10);
  for(pos = 175; pos>=5; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(10);                       // waits 15ms for the servo to reach the position 
  } 

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  cm = microsecondsToCentimeters(duration);
  right=cm;
 
  delay(100);
 if(left>right)
{   myservo.write(90); 
 

digitalWrite (motora,HIGH);
                   digitalWrite (motorb,LOW);
                    digitalWrite (motorc,LOW);
                     digitalWrite (motord,HIGH); 
                     
                     delay(1200);
                  }

if(right>left)
{
   myservo.write(90);

digitalWrite (motora,LOW);
                   digitalWrite (motorb,HIGH);
                    digitalWrite (motorc,HIGH);
                     digitalWrite (motord,LOW); 
                     digitalWrite(trigPin, LOW);
                     delay(1200);
                                
  }
}
  }
  
 if(sw1state==0)
 {
  if (Serial.available() > 0) {
      flamestate=digitalRead(flame);
    if(flamestate==0)
    {
       digitalWrite (motora,LOW);
                   digitalWrite (motorb,LOW);
                    digitalWrite (motorc,LOW);
                     digitalWrite (motord,LOW);
                digitalWrite (buzzer,HIGH);      
      
      }
          if(flamestate==1)
    {
 
                digitalWrite (buzzer,LOW);      
      
      }
    
                // read the incoming byte:
                incomingByte = Serial.read();
                if(incomingByte=='S')  ///// go forward 
                {
                  digitalWrite (motora,LOW);
                   digitalWrite (motorb,LOW);
                    digitalWrite (motorc,LOW);
                     digitalWrite (motord,LOW);
                     
                  
                }
                if(incomingByte=='L')///// take back 
                {
                 digitalWrite (motora,HIGH);
                   digitalWrite (motorb,LOW);
                    digitalWrite (motorc,LOW);
                     digitalWrite (motord,HIGH);
             
                }
                if(incomingByte=='R')  ///// go forward 
                {
                digitalWrite (motora,LOW);
                   digitalWrite (motorb,HIGH);
                    digitalWrite (motorc,HIGH);
                     digitalWrite (motord,LOW); 
                  
                                                  }
                if(incomingByte=='F')///// take back 
                {
                digitalWrite (motora,HIGH);
                   digitalWrite (motorb,LOW);
                    digitalWrite (motorc,HIGH);
                     digitalWrite (motord,LOW);   
             
                }
                if(incomingByte=='B')  ///// go forward 
                {
                  digitalWrite (motora,LOW);
                   digitalWrite (motorb,HIGH);
                    digitalWrite (motorc,LOW);
                     digitalWrite (motord,HIGH);
                 }
                 }
  }

  }
                
                
            
