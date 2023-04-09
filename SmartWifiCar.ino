/*Nodemcu ESP8266 WIFI control car with New Blynk app.
   This code created by the SriTu Hobby team.
   https://www.srituhobby.com
*/

//Include the library files
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Define motor pins
#define ENA D0
#define IN1 D1
#define IN2 D2
#define IN3 D3
#define IN4 D4
#define ENB D5

// Variables for Blynk widget values
bool forward = 0; 
bool backward = 0; 
bool left = 0; 
bool right = 0; 
bool stop = 0; 
int Speed;

char auth[] = "gYpsdkbCFKsysKXQGCTHeQEXuuG59qTW"; //Enter your Blynk auth token
char ssid[] = "Worlder world 4g"; //Enter your WIFI name
char pass[] = "Worlderworld"; //Enter your WIFI passowrd
#define BLYNK_TEMPLATE_ID "TMPLJsjSbqgl"
#define BLYNK_DEVICE_NAME "SmartWiFiCar"


void setup() {
  Serial.begin(115200);
  //Set motor pins as output pins
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  //Initialize the Blynk library
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

// Get forward values
BLYNK_WRITE(V0) {
  forward  = param.asInt();
}
// Get backward values
BLYNK_WRITE(V1) {
  backward = param.asInt();
}

// Get left values
BLYNK_WRITE(V2) {
  left = param.asInt();
}

// Get right values
BLYNK_WRITE(V3) {
  right = param.asInt();
}

// Get stop values
BLYNK_WRITE(V4) {
  stop = param.asInt();
}

//Get slider values
BLYNK_WRITE(V5) {
  Speed = param.asInt();
  Serial.println("Speed is" + Speed);
}
void smartcar() {
  if (stop == 1) {
    carStop();
    Serial.println("Handbrake On");
  } else if (forward == 1) {
    if (left == 1) {
      carForwardLeft();
      Serial.println("carForwardLeft");
    } else if (right == 1) {
      carForwardRight();
      Serial.println("carForwardRight");
    } else {
      carForward();
      Serial.println("carForward");
    }
  } else if (backward == 1) {
    if (left == 1) {
      carBackwardLeft();
      Serial.println("carBackwardLeft");
    } else if (right == 1) {
      carBackwardRight();
      Serial.println("carBackwardRight");
    } else {
      carBackward();
      Serial.println("carBackward");
    }
  } else if (left == 1) {
    carLeft();
    Serial.println("carLeft");
  } else if (right == 1) {
    carRight();
    Serial.println("carRight");
  } else {
    carStop();
    Serial.println("carstop");
  }
}

void loop() {
  Blynk.run();// Run the blynk function
  smartcar();// Call the main function
}

/**************Motor movement functions*****************/
void carBackward() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void carForward() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, HIGH); // Swap HIGH and LOW
  digitalWrite(IN2, LOW); // Swap HIGH and LOW
  digitalWrite(IN3, LOW); // Swap HIGH and LOW
  digitalWrite(IN4, HIGH); // Swap HIGH and LOW
}

void carLeft() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, LOW); //HIGH
  digitalWrite(IN2, HIGH); // LOW
  digitalWrite(IN3, LOW); //HIGH
  digitalWrite(IN4, HIGH); //LOW
}
void carRight() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, HIGH); //
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void carStop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void carForwardRight() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
}

void carForwardLeft() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void carBackwardLeft() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void carBackwardRight() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}


