//#include <SoftwareSerial.h>
//SoftwareSerial TSerial(1,0);
// p0 - tx
// p1 - rx

int PushButton=4;
int LED=5;

//int LED_state=LOW;
int Button_state=LOW;

int Button_newstate;


void setup() {
 Serial.begin(9600);
 pinMode(PushButton, INPUT);
 pinMode(LED, OUTPUT);
 Button_state=digitalRead(PushButton); 
} 
void loop() {
  


  //Button_newstate=digitalRead(PushButton);
  if (digitalRead(PushButton)== HIGH) {
    //if (LED_state==LOW){ 
      Serial.println("AT+SEND=0,1,H");
      digitalWrite(LED,HIGH);
      delay(1000);
      Serial.println("AT+SEND=0,1,L");
      digitalWrite(LED,LOW);
      delay(1000);
      //digitalWrite(LED,LOW);
      //delay(1000);
      
    //}
  }
    //Button_state=Button_newstate;
         




}
//}
  


