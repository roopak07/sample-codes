#define EN        8  
#define X_DIR     5
#define X_STP     2
#include<String.h>
int delayTime=20; //Delay between each pause (uS) ,speed 
int stps=10000;// Steps to move 10000 ,no:of steps
int ival,i;

void setup(){
  Serial.begin(9600);

  pinMode(X_DIR, OUTPUT); 
  pinMode(X_STP, OUTPUT);
  pinMode(EN, OUTPUT);
  digitalWrite(EN, LOW); // actuating stepper motor, low- on , high-off
}
void loop(){
    digitalWrite(X_DIR, true); //direction of stepper motor  
    for (i=0 ; i < stps; i++) 
    {
    digitalWrite(X_STP, HIGH);
    delayMicroseconds(delayTime); 
    digitalWrite(X_STP, LOW);
    delayMicroseconds(delayTime);
    }
 }
