//#include <ESP8266WiFi.h>  //Thư viện ESP8266
#include <BlynkSimpleEsp8266.h>
#define BLYNK_PRINT Serial
char auth[] = "8bt2-4f_nYf8j6hG_TUZc1WuKh9b_4Ny";
char ssid[] = "GW020_CDE720";
char pass[] = "meocon3569";

//khai bao led
int ledPin1 = D0;  //16
int ledPin2 = D1;  //15
int ledPin3 = D2;  //04
int ledPin4 = D3;  //0
int ledPin5 = D4;

int btnPin1 = D5;  //1124
int btnPin2 = D6;  //
int btnPin3 = D7;  //13
int btnPin4 = D8;  //15
BlynkTimer timer;

int ledState1 = HIGH;
int btnState1 = HIGH;
int ledState2 = HIGH;
int btnState2 = HIGH;
int ledState3 = HIGH;
int btnState3 = HIGH;
int ledState4 = HIGH;
int btnState4 = HIGH;
int ledState5 = HIGH;
int btnState5 = HIGH;


void setup() {
  Blynk.begin(auth, ssid, pass);
  Serial.begin(9600);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);

  pinMode(btnPin1, INPUT_PULLUP);
  pinMode(btnPin2, INPUT_PULLUP);
  pinMode(btnPin3, INPUT_PULLUP);
  pinMode(btnPin4, INPUT_PULLUP);
  //pinMode(btnPin5, INPUT_PULLUP);
  digitalWrite(ledPin1, ledState1);
  digitalWrite(ledPin2, ledState2);
  digitalWrite(ledPin3, ledState3);
  digitalWrite(ledPin4, ledState4);
  digitalWrite(ledPin5, ledState5);
}

BLYNK_CONNECTED() {
  Blynk.syncVirtual(V1);
  Blynk.syncVirtual(V2);
  Blynk.syncVirtual(V3);
  Blynk.syncVirtual(V4);
  Blynk.syncVirtual(V5);
}
BLYNK_WRITE(V1) {
  ledState1 = param.asInt();
  digitalWrite(ledPin1, ledState1);
  Serial.print("on the mic ");
}
BLYNK_WRITE(V2) {
  ledState2 = param.asInt();
  digitalWrite(ledPin2, ledState2);
}
BLYNK_WRITE(V3) {
  ledState3 = param.asInt();
  digitalWrite(ledPin3, ledState3);
}
BLYNK_WRITE(V4) {
  ledState4 = param.asInt();
  digitalWrite(ledPin4, ledState4);
}
BLYNK_WRITE(V5) {
  ledState5 = param.asInt();
  digitalWrite(ledPin5, ledState5);
}
void checkPhysicalButton1() {
  if (digitalRead(btnPin1) == LOW) {
    if (btnState1 != LOW) {
      ledState1 = !ledState1;
      digitalWrite(ledPin1, ledState1);
      Blynk.virtualWrite(V1, ledState1);
    }
    btnState1 = LOW;
  } else {
    btnState1 = HIGH;
  }
}
void checkPhysicalButton2() {
  if (digitalRead(btnPin2) == LOW) {
    if (btnState2 != LOW) {
      ledState2 = !ledState2;
      digitalWrite(ledPin2, ledState2);
      Blynk.virtualWrite(V2, ledState2);
    }
    btnState2 = LOW;
  } else {
    btnState2 = HIGH;
  }
}
void checkPhysicalButton3() {
  if (digitalRead(btnPin3) == LOW) {
    if (btnState3 != LOW) {
      ledState3 = !ledState3;
      digitalWrite(ledPin3, ledState3);
      Blynk.virtualWrite(V3, ledState3);
    }
    btnState3 = LOW;
  } else {
    btnState3 = HIGH;
  }
}
void checkPhysicalButton4() {
  if (digitalRead(btnPin4) == LOW) {
    if (btnState4 != LOW) {
      ledState4 = !ledState4;
      digitalWrite(ledPin4, ledState4);
      Blynk.virtualWrite(V4, ledState4);
    }
    btnState4 = LOW;
  } else {
    btnState4 = HIGH;
  }
}

void loop() {
  Blynk.run();
  timer.run();
  checkPhysicalButton1();
  checkPhysicalButton2();
  checkPhysicalButton3();
  checkPhysicalButton4();
}
