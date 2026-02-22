# Automated School Bell System with Door Lock and Timetable Display

## Overview

This project is an Arduino-based school automation system designed to manage automatic bell ringing, class scheduling, break notifications, and optional door lock control.

The system integrates a servo motor, LCD display, buzzer, LED indicators, and push buttons to simulate real-time school operations. It demonstrates practical applications of embedded systems, real-time control logic, and hardware-software integration.

---

## Project Objectives

- Automate school bell ringing based on predefined class schedules  
- Display current class information and elapsed time  
- Indicate break periods with countdown timer  
- Enable manual bell triggering  
- Provide optional door locking mechanism  
- Demonstrate real-time microcontroller programming  

---

## Key Features

### 1. Real-Time Class Scheduler

- Displays current class name on a 16x2 LCD  
- Shows elapsed class time in HH:MM:SS format  
- Displays “Break Time” during intervals  
- Break period includes a 15-second countdown  

---

### 2. Servo Motor Bell Simulation

- Rotates to 90° at the beginning of each class  
- Returns to 0° after class completion  
- Can be configured to simulate mechanical bell movement  

---

### 3. Buzzer Alert System

- Activated at the end of each class  
- Signals transition to break period  
- Manual push button allows 3-second bell activation  

---

### 4. LED Status Indicators

- Green LED: Class in session  
- Red LED: Break period  

Provides quick visual feedback of system state.

---

### 5. Optional Door Lock Integration

- Can control servo-based or electromagnetic lock  
- Configurable locking/unlocking based on timetable  
- Enhances automation scope for classroom management  

---

## Hardware Components

| Component | Description |
|-----------|------------|
| Arduino UNO | Microcontroller unit |
| 16x2 LCD Display | Displays class and timing information |
| Servo Motor | Simulates bell and optional door lock |
| Buzzer | Audio alert mechanism |
| LEDs (Red & Green) | Status indicators |
| Push Button | Manual bell trigger |
| Resistors (220Ω / 10kΩ) | Current limiting and pull-down/pull-up |
| Breadboard | Prototyping platform |
| Jumper Wires | Circuit connections |
| 5V Power Supply | System power |

---

## Software and Libraries

The project uses standard Arduino libraries:

```cpp
#include <Servo.h>
#include <LiquidCrystal.h>
```

Core implementation includes:

- `millis()`-based non-blocking timing system  
- Conditional logic for state transitions  
- Modular structure for scheduling control  
- Real-time elapsed time tracking  

---

## System Workflow

1. System initializes and loads predefined class schedule  
2. LCD displays current class information  
3. Servo rotates to simulate bell at class start  
4. Green LED turns ON during class session  
5. At class completion:
   - Buzzer activates  
   - Red LED turns ON  
   - LCD displays break countdown  
6. After break ends:
   - Next class begins  
   - System resets state  
7. Manual ringing available at any time via push button  

---

## Sample Output

Class Session:

```
Class: Science
Time: 00:14:23
```

Break Session:

```
Break Time!
Time Left: 00:00:15
```

---

## Engineering Concepts Demonstrated

- Embedded system design  
- Real-time event handling  
- State-based logic control  
- Hardware-software interfacing  
- Timer-based scheduling using `millis()`  
- Basic automation system design  

---

## Limitations

- No Real-Time Clock (RTC) module for accurate calendar-based scheduling  
- Schedule stored in code (not externally configurable)  
- Prototype-level security for door lock integration  

---

## Future Enhancements

- Integration of RTC module (e.g., DS3231) for real-world time tracking  
- External schedule upload via EEPROM or SD card  
- Wireless control using Bluetooth or Wi-Fi (ESP8266/ESP32)  
- IoT dashboard integration for remote monitoring  
- Electromagnetic lock integration with fail-safe mechanism  
- Sound sensor override functionality  

---

## Ideal Applications

- School and college academic projects  
- Embedded systems demonstrations  
- Introductory automation system prototypes  
- Microcontroller-based control system learning  

---

## Disclaimer

This project is a prototype developed for educational and demonstration purposes. It is not intended for deployment in critical infrastructure environments without additional fail-safe mechanisms and compliance testing.

---

## Author

Nishant Rajora  
Interested in embedded systems, automation, and applied technology development
