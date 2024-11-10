#include <LiquidCrystal.h>
#include <Servo.h>  // Include Servo library

// Initialize the LCD (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
Servo myServo;   // Create a Servo object

const int buzzer = 9;         // Buzzer connected to pin 9
const int greenLED = 8;       // Green LED for class ongoing
const int redLED = 7;         // Red LED for break time
const int bellButton = 6;     // Optional: button to manually ring the bell

unsigned long previousMillis = 0; // Store last time the bell was rung

unsigned long classDuration = 30000;   // Class duration of 30 seconds
unsigned long breakDuration = 15000;   // Break duration of 15 seconds

// Class start times (with breaks of 15 seconds)
unsigned long classStartMillis[] = {
  0,                     
  classDuration + breakDuration,                      
  2 * (classDuration + breakDuration),                
  3 * (classDuration + breakDuration),                
  4 * (classDuration + breakDuration)                 
};

String classNames[] = {"1st: DSA", "2nd: FOCP", "3rd: DECA", "4th: CN", "5th: Maths"};

String currentClass = "";     // To hold the current class name for displaying
bool lastClassEnded = false;  // To track when the last class ends
bool buzzerRung = false;      // To track if the buzzer has rung
bool motorMovedClockwise = false; // To track if the motor has moved clockwise

void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(greenLED, OUTPUT);  // Set the green LED pin as OUTPUT
  pinMode(redLED, OUTPUT);    // Set the red LED pin as OUTPUT
  pinMode(bellButton, INPUT_PULLUP); // Button with internal pull-up resistor

  myServo.attach(10); // Attach the servo control pin to pin 10
  myServo.write(0);   // Set initial position of servo to 0 degrees

  lcd.begin(16, 2); // Initialize the 16x2 LCD
  lcd.setCursor(0, 0);
  lcd.print("School Bell System");
}

void loop() {
  unsigned long currentMillis = millis();

  // Check if it's time for any class bell to ring
  for (int i = 0; i < sizeof(classStartMillis) / sizeof(classStartMillis[0]); i++) {
    unsigned long classEndMillis = classStartMillis[i] + classDuration;
    unsigned long breakEndMillis = classEndMillis + breakDuration;

    // Handle class time
    if (currentMillis >= classStartMillis[i] && currentMillis < classEndMillis) {
      currentClass = classNames[i];
      displayClassAndTime(currentClass, currentMillis); // Display class and time during the class
      digitalWrite(greenLED, HIGH); // Turn on green LED
      digitalWrite(redLED, LOW);     // Turn off red LED
      buzzerRung = false;            // Reset buzzer state

      // Rotate to 90 degrees clockwise only once
      if (!motorMovedClockwise) {
        myServo.write(90); // Rotate to 90 degrees (clockwise)
        motorMovedClockwise = true; // Set the flag to true
      }
    }

    // Handle break time after the class
    if (currentMillis >= classEndMillis && currentMillis < breakEndMillis) {
      currentClass = "Break Time!";
      showBreak(currentClass);
      displayClassAndTime(currentClass, currentMillis); // Display break and time during the break
      digitalWrite(greenLED, LOW);     // Turn off green LED
      digitalWrite(redLED, HIGH);      // Turn on red LED

      // Ring the buzzer only once when transitioning from class to break
      if (!buzzerRung) {
        ringBell("Class Over");
        buzzerRung = true;  // Set buzzer state to prevent ringing again
      }

      // Rotate back to 0 degrees anticlockwise only when class ends
      myServo.write(0); // Rotate back to 0 degrees (anticlockwise)
      motorMovedClockwise = false; // Reset the flag for next class
    }

    // Mark the last class as ended
    if (i == (sizeof(classStartMillis) / sizeof(classStartMillis[0]) - 1) && currentMillis >= classEndMillis) {
      if (!lastClassEnded) {
        lastClassEnded = true;  // Mark that the last class has ended
        digitalWrite(greenLED, LOW); // Ensure both LEDs are off after the last class
        digitalWrite(redLED, LOW);
      }
    }
  }

  // Manual bell ringing with a button
  if (digitalRead(bellButton) == LOW) {
    ringBell("Manual Ring");
    myServo.write(0);  // Rotate servo motor to 0 degrees when manually ringing
  }
}

// Function to ring the bell
void ringBell(String className) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(className);
  lcd.setCursor(0, 1);
  lcd.print("Bell is ringing!");

  digitalWrite(buzzer, HIGH); // Turn on the buzzer
  delay(3000);                // Ring for 3 seconds
  digitalWrite(buzzer, LOW);  // Turn off the buzzer

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("School Bell System");
}

// Function to show break time
void showBreak(String breakMsg) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(breakMsg);
  lcd.setCursor(0, 1);
  lcd.print("15 sec break");
  delay(1000);  // Small delay to allow for visual update, rest handled in main loop
}

// Function to display both class and elapsed time on the LCD
void displayClassAndTime(String className, unsigned long currentMillis) {
  lcd.setCursor(0, 0);
  lcd.print(className);
  displayElapsedTime(currentMillis);
}

// Function to display the elapsed time since the program started
void displayElapsedTime(unsigned long currentMillis) {
  unsigned long totalSeconds = currentMillis / 1000;
  unsigned long hours = totalSeconds / 3600;
  unsigned long minutes = (totalSeconds % 3600) / 60;
  unsigned long seconds = totalSeconds % 60;

  lcd.setCursor(0, 1);
  lcd.print("Time: ");
  if (hours < 10) lcd.print('0');
  lcd.print(hours);
  lcd.print(':');
  if (minutes < 10) lcd.print('0');
  lcd.print(minutes);
  lcd.print(':');
  if (seconds < 10) lcd.print('0');
  lcd.print(seconds);
}
