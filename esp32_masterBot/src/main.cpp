#include <WiFi.h>
#include <WebServer.h>
#include <Wire.h>
#include <ArduinoJson.h>

String command;             //String to store app command state.
int speedCarA = 92;
int speedCarB = 82;
int speedCarAback = 89;
int speedCarBback = 82;
int speedCarAAngle = 188;
int speedCarBAngle = 164;
int speedCar = 100;          // 400 - 1023.
int speed_Coeff = 3;

const char* ssid = "NodeMCU Car";
WebServer server(80);

// 10.8 V -> 98 L & 97 R -> Bot 1
// Bot2 ->  
// Pin definitions for ESP32
#define ENA   14          // Enable/speed motors Right        GPIO14
#define ENB   12          // Enable/speed motors Left         GPIO12
#define IN_1  15          // L298N in1 motors Right           GPIO13
#define IN_2  13          // L298N in2 motors Right           GPIO15
#define IN_3  2           // L298N in3 motors Left            GPIO0
#define IN_4  0           // L298N in4 motors Left            GPIO2

void goAhead(int delayS) { 
  digitalWrite(IN_1, LOW);
  digitalWrite(IN_2, HIGH);
  analogWrite(ENA, speedCarA);

  digitalWrite(IN_3, LOW);
  digitalWrite(IN_4, HIGH);
  analogWrite(ENB, speedCarB);
  delay(delayS);
}

void goBack(int time) { 
  digitalWrite(IN_1, HIGH);
  digitalWrite(IN_2, LOW);
  analogWrite(ENA, speedCarAback);

  digitalWrite(IN_3, HIGH);
  digitalWrite(IN_4, LOW);
  analogWrite(ENB, speedCarBback);
  delay(time);
}

void goRight() { 
  digitalWrite(IN_1, LOW);
  digitalWrite(IN_2, HIGH);
  analogWrite(ENA, speedCarAAngle);

  digitalWrite(IN_3, HIGH);
  digitalWrite(IN_4, LOW);
  analogWrite(ENB, speedCarBAngle);
}

void goLeft() {
  digitalWrite(IN_1, HIGH);
  digitalWrite(IN_2, LOW);
  analogWrite(ENA, speedCarAAngle);
  digitalWrite(IN_3, LOW);
  digitalWrite(IN_4, HIGH);
  analogWrite(ENB, speedCarBAngle);
}

void angle(int angles, bool right) {
  int fullCircle = 3650 / 360;
  if(right){
    goRight();
    delay(fullCircle * angles);
  }else {
    goLeft();
    delay(fullCircle * angles);
  }
}

void stopRobot() {  
  digitalWrite(IN_1, LOW);
  digitalWrite(IN_2, LOW);

  digitalWrite(IN_3, LOW);
  digitalWrite(IN_4, LOW);
}

void equilateralTriangleBot(){
  goAhead(1500);
  stopRobot();
  delay(3000);  
  goBack(1500);
  stopRobot();
}


void moveToRightAngleBot(){
  goAhead(3000);
  stopRobot();
  delay(3000);
  goBack(3000);
  stopRobot();
}

void march(){
  goAhead(3000);
  stopRobot();
  delay(2000);
  angle(180, true);
  stopRobot();

  delay(2000);
  goAhead(3000);
  stopRobot();
  angle(180, true);
  stopRobot();
}

void HTTP_handleRoot() {
  if (server.hasArg("f")) {
    Serial.print("here");
    Serial.println(server.arg("f"));
  }
  command = server.arg("f");
  Serial.println(command);
  if (command == "l") {
    march();
  }
  else if (command == "e") {
    equilateralTriangleBot();
    char myChar = 'e';
  }
  else if (command == "r") {
    moveToRightAngleBot();
    char myChar = 'r';
  }
  else if (command == "d1") {
    speedCarA--;
  }
  else if (command == "d2") {
    speedCarB--;
  }
  else if (command == "i1") {
    speedCarA++;
  }
  else if (command == "i2") {
    speedCarB++;
  }
  else {
    Serial.println("here");
    stopRobot();
  }
  delay(2000); 
  server.send(200, "text/html", "received");
  delay(1);
}

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);  
  pinMode(IN_1, OUTPUT);
  pinMode(IN_2, OUTPUT);
  pinMode(IN_3, OUTPUT);
  pinMode(IN_4, OUTPUT); 

  Serial.begin(115200);

  // Connecting WiFi
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);

  // Starting Web-server
  server.on("/formation", HTTP_handleRoot);
  server.onNotFound(HTTP_handleRoot);
  server.begin();   
  Serial.print("server started");
}

void loop() {
  server.handleClient();
  delay(1000);
}