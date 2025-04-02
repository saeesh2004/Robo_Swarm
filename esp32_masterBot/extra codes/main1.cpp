
#include <WiFi.h>

const char* ssid = "esp32";
const char* password = "123456789";
WiFiServer server(80);

// void setup() {
//   Serial.begin(115200);
//   delay(1000);

//   // Start Access Point
//   WiFi.softAP(ssid, password);
//   IPAddress IP = WiFi.softAPIP();

//   // Start the server
//   server.begin();
//   Serial.println("Server started");

//   // Print IP address
//   Serial.print("AP IP Address: ");
//   Serial.println(IP);
// }

// void loop() {
//   // Check if a client has connected
//   WiFiClient client = server.available();
//   if (client) {
//     Serial.println("New Client connected");
//     // Close the connection
//     client.stop();
//     Serial.println("Client disconnected");
//   }
// }


// #include <WiFi.h> // Include WiFi library for potential WiFi communication (replace with your chosen library if using a different protocol)

const int numRobots = 3;  // Number of robots in the swarm

// Define pins (replace with actual pin numbers)
int enablePins[numRobots] = {2, 3, 4};  // Enable pins for motor control
// Other motor control pins (M1A, M1B, etc.) would be defined here

// Estimated time (in milliseconds) for robots to travel a unit distance (calibrated value)
int travelTimePerUnit = 1000; 

// Function to move a robot forward a certain distance (replace with your motor control functions)
void moveForward(int robotID, int distance) {
  // Enable the motor driver for the robot
  digitalWrite(enablePins[robotID], HIGH);
  // Implement motor control logic to move forward for the specified distance and time
  delay(distance * travelTimePerUnit);
  // Disable the motor driver
  digitalWrite(enablePins[robotID], LOW);
}

// Function to rotate a robot a certain angle (replace with your motor control functions)
void rotateRobot(int robotID, int angle) {
  // Implement motor control logic to rotate the robot in the desired direction (left or right) for the calculated time
  int rotateTime = (angle * travelTimePerUnit) / 90; // Assuming 90 degrees rotation for a unit time
  if (angle > 0) {
    // Rotate right
    // Enable motors for right rotation
  } else {
    // Rotate left
    // Enable motors for left rotation
  }
  delay(rotateTime);
  // Disable motors
}

void setup() {
  // Initialize serial communication for potential debugging (if using serial communication)
  Serial.begin(115200);

  // Set enable pins as output
  for (int i = 0; i < numRobots; i++) {
    pinMode(enablePins[i], OUTPUT);
  }

  // Serial.begin(115200);
  delay(1000);
// 
  // Start Access Point
  WiFi.softAP(ssid, password);
  IPAddress IP = WiFi.softAPIP();
// 
  // Start the server
  server.begin();
  Serial.println("Server started");
// 
  // Print IP address
  Serial.print("AP IP Address: ");
  Serial.println(IP);

  // Initialize motor control pins here (M1A, M1B, etc.)
}

void loop() {
  // Form equilateral triangle
  moveForward(0, 2); // Robot 1 moves forward 2 units
  delay(travelTimePerUnit); // Wait for other robots to catch up (assuming similar starting positions)
  moveForward(1, 1);  // Robot 2 moves forward 1 unit
  moveForward(2, 1);  // Robot 3 moves forward 1 unit
  rotateRobot(2, 120); // Robot 3 rotates 120 degrees left

  // Hold the formation for a while (adjust delay as needed)
  delay(5000);

  // Return to initial positions
  rotateRobot(2, -120); // Robot 3 rotates 120 degrees right
  moveForward(2, 1);  // Robot 3 moves forward 1 unit
  moveForward(1, 1);  // Robot 2 moves forward 1 unit
  moveForward(0, 2);  // Robot 1 moves forward 2 units

  // Form right triangle
  rotateRobot(0, 90);  // Robot 1 rotates 90 degrees left
  moveForward(0, 1);  // Robot 1 moves forward 1 unit
  moveForward(2, 1);  // Robot 3 moves forward 1 unit
  delay(travelTimePerUnit); // Wait for Robot 2 to catch up
  moveForward(1, sqrt(2)); // Robot 2 moves forward sqrt(2) units (calculated for a 45-45-90 triangle)

  // Hold the formation for a while (adjust delay as needed)
  delay(5000);

  // Return to initial positions
  moveForward(2, 1);  // Robot 3 moves forward 1 unit
  moveForward(1, -sqrt(2)); // Robot 2 moves backward sqrt(2) units
  rotateRobot(0, -90); // Robot 1 rotates 90 degrees right
  moveForward(0#include <WiFi.h>

const char* ssid = "esp32";
const char* password = "123456789";
WiFiServer server(80);

// void setup() {
//   Serial.begin(115200);
//   delay(1000);

//   // Start Access Point
//   WiFi.softAP(ssid, password);
//   IPAddress IP = WiFi.softAPIP();

//   // Start the server
//   server.begin();
//   Serial.println("Server started");

//   // Print IP address
//   Serial.print("AP IP Address: ");
//   Serial.println(IP);
// }

// void loop() {
//   // Check if a client has connected
//   WiFiClient client = server.available();
//   if (client) {
//     Serial.println("New Client connected");
//     // Close the connection
//     client.stop();
//     Serial.println("Client disconnected");
//   }
// }


// #include <WiFi.h> // Include WiFi library for potential WiFi communication (replace with your chosen library if using a different protocol)

const int numRobots = 3;  // Number of robots in the swarm

// Define pins (replace with actual pin numbers)
int enablePins[numRobots] = {2, 3, 4};  // Enable pins for motor control
// Other motor control pins (M1A, M1B, etc.) would be defined here

// Estimated time (in milliseconds) for robots to travel a unit distance (calibrated value)
int travelTimePerUnit = 1000; 

// Function to move a robot forward a certain distance (replace with your motor control functions)
void moveForward(int robotID, int distance) {
  // Enable the motor driver for the robot
  digitalWrite(enablePins[robotID], HIGH);
  // Implement motor control logic to move forward for the specified distance and time
  delay(distance * travelTimePerUnit);
  // Disable the motor driver
  digitalWrite(enablePins[robotID], LOW);
}

// Function to rotate a robot a certain angle (replace with your motor control functions)
void rotateRobot(int robotID, int angle) {
  // Implement motor control logic to rotate the robot in the desired direction (left or right) for the calculated time
  int rotateTime = (angle * travelTimePerUnit) / 90; // Assuming 90 degrees rotation for a unit time
  if (angle > 0) {
    // Rotate right
    // Enable motors for right rotation
  } else {
    // Rotate left
    // Enable motors for left rotation
  }
  delay(rotateTime);
  // Disable motors
}

void setup() {
  // Initialize serial communication for potential debugging (if using serial communication)
  Serial.begin(115200);

  // Set enable pins as output
  for (int i = 0; i < numRobots; i++) {
    pinMode(enablePins[i], OUTPUT);
  }

  // Serial.begin(115200);
  delay(1000);
// 
  // Start Access Point
  WiFi.softAP(ssid, password);
  IPAddress IP = WiFi.softAPIP();
// 
  // Start the server
  server.begin();
  Serial.println("Server started");
// 
  // Print IP address
  Serial.print("AP IP Address: ");
  Serial.println(IP);

  // Initialize motor control pins here (M1A, M1B, etc.)
}

void loop() {
  // Form equilateral triangle
  moveForward(0, 2); // Robot 1 moves forward 2 units
  delay(travelTimePerUnit); // Wait for other robots to catch up (assuming similar starting positions)
  moveForward(1, 1);  // Robot 2 moves forward 1 unit
  moveForward(2, 1);  // Robot 3 moves forward 1 unit
  rotateRobot(2, 120); // Robot 3 rotates 120 degrees left

  // Hold the formation for a while (adjust delay as needed)
  delay(5000);

  // Return to initial positions
  rotateRobot(2, -120); // Robot 3 rotates 120 degrees right
  moveForward(2, 1);  // Robot 3 moves forward 1 unit
  moveForward(1, 1);  // Robot 2 moves forward 1 unit
  moveForward(0, 2);  // Robot 1 moves forward 2 units

  // Form right triangle
  rotateRobot(0, 90);  // Robot 1 rotates 90 degrees left
  moveForward(0, 1);  // Robot 1 moves forward 1 unit
  moveForward(2, 1);  // Robot 3 moves forward 1 unit
  delay(travelTimePerUnit); // Wait for Robot 2 to catch up
  moveForward(1, sqrt(2)); // Robot 2 moves forward sqrt(2) units (calculated for a 45-45-90 triangle)

  // Hold the formation for a while (adjust delay as needed)
  delay(5000);

  // Return to initial positions
  moveForward(2, 1);  // Robot 3 moves forward 1 unit
  moveForward(1, -sqrt(2)); // Robot 2 moves backward sqrt(2) units
  rotateRobot(0, -90); // Robot 1 rotates 90 degrees right
  moveForward(0, 1);  // Robot 1 moves forward 1 unit 

  // Add a delay between formations (adjust as needed)
  delay(10000);
}
, 1);  // Robot 1 moves forward 1 unit 

  // Add a delay between formations (adjust as needed)
  delay(10000);
}
