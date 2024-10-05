#include <Wire.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27, 16, 2); 


const int green1Pin = 4; 
const int yellow1Pin = 3; 
const int red1Pin = 2;  
const int green2Pin = 7; 
const int yellow2Pin = 6; 
const int red2Pin = 5;     
const int green3Pin = 10;  
const int yellow3Pin = 9;  
const int red3Pin = 8;     
const int green4Pin = 13;  
const int yellow4Pin = 12; 
const int red4Pin = 11;    

// Timing settings (in milliseconds)
const int greenDuration = 5000;   // Green light duration for normal operation
const int yellowDuration = 2000;  // Yellow light duration
const int redDuration = 5000;     // Red light duration
const int emergencyGreenDuration = 20000; // Green light duration for emergency
const int blinkDuration = 500; // Blink duration for red LED
const int blinkCount = 3; // Number of blinks

// Variables to track the current state and timing
unsigned long previousMillis = 0;
int currentStep = 0;
bool emergencyActive = false;

void setup() {
  // Initialize LCD
  lcd.begin(16, 2);
  lcd.backlight(); // Turn on the backlight

  // Initialize pins as outputs
  pinMode(green1Pin, OUTPUT);
  pinMode(yellow1Pin, OUTPUT);
  pinMode(red1Pin, OUTPUT);
  pinMode(green2Pin, OUTPUT);
  pinMode(yellow2Pin, OUTPUT);
  pinMode(red2Pin, OUTPUT);
  pinMode(green3Pin, OUTPUT);
  pinMode(yellow3Pin, OUTPUT);
  pinMode(red3Pin, OUTPUT);
  pinMode(green4Pin, OUTPUT);
  pinMode(yellow4Pin, OUTPUT);
  pinMode(red4Pin, OUTPUT);
  
  Serial.begin(9600); // Start serial communication
  lcd.clear();
  lcd.print("Welcome!");
}

void loop() {
  if (Serial.available() > 0) {
    char input = Serial.read(); // Read the input character
    if (input == '1') { // If '1' is received, trigger emergency
      emergencyActive = true;
    }
  }

  if (emergencyActive) {
    emergencyVehicleProcedure();
  } else {
    normalTrafficLightCycle();
  }
}

void emergencyVehicleProcedure() {
  emergencyActive = false;

  // Blink red LED for lane 1 three times
  for (int i = 0; i < blinkCount; i++) {
    digitalWrite(red1Pin, HIGH); // Turn on red LED
    delay(blinkDuration);
    digitalWrite(red1Pin, LOW); // Turn off red LED
    delay(blinkDuration);
  }

  // Set Lane 1 to Green and turn off others
  digitalWrite(green1Pin, HIGH);
  digitalWrite(red2Pin, HIGH);
  digitalWrite(red3Pin, HIGH);
  digitalWrite(red4Pin, HIGH);
  digitalWrite(yellow1Pin, LOW);
  digitalWrite(yellow2Pin, LOW);
  digitalWrite(yellow3Pin, LOW);
  digitalWrite(yellow4Pin, LOW);
  
  digitalWrite(green2Pin, LOW);
  digitalWrite(green3Pin, LOW);
  digitalWrite(green4Pin, LOW);
  
  
  // Display emergency message
  lcd.clear();
  lcd.print("Emergency vehicle");
  lcd.setCursor(0, 1);
  lcd.print("is behind, pls!");

  // Emergency vehicle has priority for 20 seconds
  delay(emergencyGreenDuration); 
  lcd.clear();
  
  // Return to normal operation
  previousMillis = millis(); // Reset timing for normal operation
  currentStep = 0;
}

void normalTrafficLightCycle() {
  
  lcd.print("Welcome!");
  unsigned long currentMillis = millis();

  switch (currentStep) {
    case 0:
      // Direction 1: Green, Direction 2: Red
      digitalWrite(green1Pin, HIGH);
      digitalWrite(red1Pin, LOW);
      digitalWrite(green2Pin, LOW);
      digitalWrite(red2Pin, HIGH);
      digitalWrite(red3Pin, HIGH);
      digitalWrite(red4Pin, HIGH);
      if (currentMillis - previousMillis >= greenDuration) {
        previousMillis = currentMillis;
        currentStep++;
      }
      break;

    case 1:
      // Direction 1: Yellow
      digitalWrite(green1Pin, LOW);
      digitalWrite(yellow1Pin, HIGH);
      if (currentMillis - previousMillis >= yellowDuration) {
        previousMillis = currentMillis;
        digitalWrite(yellow1Pin, LOW);
        currentStep++;
      }
      break;

    case 2:
      // Direction 2: Green, Direction 1: Red
      digitalWrite(green2Pin, HIGH);
      digitalWrite(red2Pin, LOW);
      digitalWrite(green1Pin, LOW);
      digitalWrite(red1Pin, HIGH);
      if (currentMillis - previousMillis >= greenDuration) {
        previousMillis = currentMillis;
        currentStep++;
      }
      break;

    case 3:
      // Direction 2: Yellow
      digitalWrite(green2Pin, LOW);
      digitalWrite(yellow2Pin, HIGH);
      if (currentMillis - previousMillis >= yellowDuration) {
        previousMillis = currentMillis;
        digitalWrite(yellow2Pin, LOW);
        currentStep++;
      }
      break;

    case 4:
      // Direction 3: Green
      digitalWrite(green3Pin, HIGH);
      digitalWrite(red3Pin, LOW);
      digitalWrite(red2Pin, HIGH);
      if (currentMillis - previousMillis >= greenDuration) {
        previousMillis = currentMillis;
        currentStep++;
      }
      break;

    case 5:
      // Direction 3: Yellow
      digitalWrite(green3Pin, LOW);
      digitalWrite(yellow3Pin, HIGH);
      if (currentMillis - previousMillis >= yellowDuration) {
        previousMillis = currentMillis;
        digitalWrite(yellow3Pin, LOW);
        currentStep++;
      }
      break;

    case 6:
      // Direction 4: Green
      digitalWrite(green4Pin, HIGH);
      digitalWrite(red4Pin, LOW);
      digitalWrite(red3Pin, HIGH);
      if (currentMillis - previousMillis >= greenDuration) {
        previousMillis = currentMillis;
        currentStep++;
      }
      break;

    case 7:
      // Direction 4: Yellow
      digitalWrite(green4Pin, LOW);
      digitalWrite(yellow4Pin, HIGH);
      if (currentMillis - previousMillis >= yellowDuration) {
        previousMillis = currentMillis;
        digitalWrite(yellow4Pin, LOW);
        currentStep = 0; // Cycle back to the first step
      }
      break;
  }
}
