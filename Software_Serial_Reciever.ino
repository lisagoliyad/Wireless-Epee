//address 2
#define LEDPin 3
String incomingstring;

void setup() {
  pinMode(LEDPin,OUTPUT);
  Serial.begin(57600);
  
}
void loop() {
  if(Serial.available()){ 
    //digitalWrite(LEDPin, HIGH);
    incomingstring= Serial.readString();
    if (incomingstring.indexOf("H") >0) {
      digitalWrite(LEDPin, HIGH);
      delay(1000);
      digitalWrite(LEDPin, LOW);
      //delay(1000);

    }
    //digitalWrite(LEDPin, LOW);
    //delay(1000);
  
    }
  }
