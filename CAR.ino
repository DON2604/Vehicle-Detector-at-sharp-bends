const int pingPin = 4;//big
const int echoPin = 5;
const int GREENB = 11;
const int YELLOWB = 10;
const int REDB = 9;

const int pingPin2 = 2; //small
const int echoPin2 = 3;
const int GREENS = 8;
const int YELLOWS= 7;
const int REDS = 6;



void setup() {
   Serial.begin(9600); // Starting Serial Terminal
   pinMode(GREENB,OUTPUT);
   pinMode(REDB,OUTPUT);
   pinMode(YELLOWB,OUTPUT);
   pinMode(GREENS,OUTPUT);
   pinMode(REDS,OUTPUT);
   pinMode(YELLOWS,OUTPUT);
   
}

void loop() {
   long duration, inches, cm,duration2,inches2,cm2;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   
   pinMode(pingPin2, OUTPUT);
   digitalWrite(pingPin2, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin2, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin2, LOW);
   
   pinMode(echoPin2, INPUT);
   duration2 = pulseIn(echoPin2, HIGH);
 
   inches = microsecondsToInches(duration);
   cm = microsecondsToCentimeters(duration);
   
   inches2 = microsecondsToInches(duration2);
   cm2 = microsecondsToCentimeters(duration2);
   Serial.print(inches);
   Serial.print("in, ");
   Serial.print(cm);
   Serial.print("cm");
   Serial.println();
   Serial.print(inches2);
   Serial.print("  in2, ");
   Serial.print(cm2);
   Serial.print("  cm2");
      Serial.println();
         Serial.println();
            Serial.println();
               
   
   delay(100);
    
    if(cm<=15)
    digitalWrite(REDS,HIGH);
    else
    digitalWrite(REDS,LOW);
    if(cm<=35 && cm>15)
    digitalWrite(YELLOWS,HIGH);
    else
    digitalWrite(YELLOWS,LOW);
    if(cm>35)
    digitalWrite(GREENS,HIGH);
    else
    digitalWrite(GREENS,LOW);
    
    if(cm2<=12.5)
    digitalWrite(REDB,HIGH);
    else
    digitalWrite(REDB,LOW);
    if(cm2<=20 && cm2>12.5)
    digitalWrite(YELLOWB,HIGH);
    else
    digitalWrite(YELLOWB,LOW);
    if(cm2>20.5)
    digitalWrite(GREENB,HIGH);
    else
    digitalWrite(GREENB,LOW);
 
}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
