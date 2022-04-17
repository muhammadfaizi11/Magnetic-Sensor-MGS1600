#include <Wire.h>

//#define Slave Serial3
// Slave Read Magnetic Sensor
#define ForkRight 50
#define ForkLeft 52
#define RightMarker A4
#define LeftMarker A3
#define TrackPresent A2
#define AnalogOut A0
int forkRight, forkLeft, trackPresent, analogOut, markerLeft, markerRight;
float magnetic, magnetPrev, kemiringan;
int a,b,c,d;
float readMarkerLeft[4] = {a,b,c,d};
unsigned long currentTime;
unsigned long previousTime = 0;

void ForkRightDetect() {
  digitalWrite(ForkRight, HIGH);
  digitalWrite(ForkRight, LOW);
}

void ForkLeftDetect() {
  digitalWrite(ForkLeft, HIGH);
  digitalWrite(ForkLeft, LOW);
}

int forkRightVal(){
  int forkRightValue = digitalRead(ForkRight);
  Serial.print(" FR: ");
  Serial.println(forkRightValue);
  return forkRightValue;
}

int forkLeftVal(){
  int forkLeftValue = digitalRead(ForkLeft);
  Serial.print(" FL: ");
  Serial.println(forkLeftValue);
  return forkLeftValue;
}

int trackDetect() {
  int TrackPresentValue = digitalRead(TrackPresent);
  Serial.print(" TP: ");
  Serial.println(TrackPresentValue);
  return TrackPresentValue;
}
int AnalogOutDetect() {
  int AnalogOutValue = analogRead(AnalogOut);
  Serial.print(" AO: ");
  Serial.println(AnalogOutValue);
  return AnalogOutValue;
}
int RightMarkerDetect() {
  int RightMarkerValue = digitalRead(RightMarker);
  Serial.print(" RM: ");
  Serial.println(RightMarkerValue);
  return RightMarkerValue;
}
int LeftMarkerDetect() {
  int LeftMarkerValue = digitalRead(LeftMarker);
  Serial.print(" LM: ");
  Serial.println(LeftMarkerValue);
  return LeftMarkerValue;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ForkRight, OUTPUT);
  pinMode(ForkLeft, OUTPUT);
  pinMode(RightMarker, INPUT);
  pinMode(LeftMarker, INPUT);
  pinMode(TrackPresent, INPUT);
  pinMode(AnalogOut, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
//  magnetic=0;
//  magnetPrev=0;
//  kemiringan=0;
//  forkLeft = forkLeftVal();
//  forkRight = forkRightVal();
  trackPresent = trackDetect();
  analogOut = AnalogOutDetect();
  markerLeft = LeftMarkerDetect();
  markerRight = RightMarkerDetect();
  magnetic = analogOut;
  currentTime = millis(); 
  if(currentTime-previousTime>=100){
    previousTime = currentTime;
    magnetPrev = magnetic;
  }
  kemiringan = magnetic-magnetPrev;
  Serial.print("Magnetic : ");
  Serial.println(magnetic);
  Serial.print("Kemiringan : ");
  Serial.println(kemiringan);
//  delay(500);
}
