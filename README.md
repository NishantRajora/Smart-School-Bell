# 🛎️ Automated School Bell System with Door Lock & Timetable Display

An **Arduino-based school automation system** that handles **automatic bell ringing**, **class schedule display**, **break indicators**, **manual ringing**, and **LED + servo-based signals** for real-time school day operations.

---

## 📌 Project Overview

This system is designed to automate and streamline the bell ringing and scheduling process in schools. It uses a **servo motor**, **LCD display**, **buzzer**, **LED indicators**, and **push buttons** to create a smart, responsive environment.

---

## 🎯 Key Features

### 📅 Real-Time Class Scheduler
- Displays the **current class name** and **elapsed time (HH:MM:SS)**.
- During breaks, shows **"Break Time!"** with a **15-second countdown** on the LCD.

### ⚙️ Servo Motor Control
- Rotates to **90°** at the start of a class, simulating a bell ring.
- Returns to **0°** after class ends.

### 🔔 Buzzer Activation
- Buzzer **sounds at the end of every class** to indicate break time.
- A **manual bell button** triggers a **3-second ring** on demand.

### 💡 LED Indicators
- 🟢 **Green LED**: Indicates an ongoing class session.
- 🔴 **Red LED**: Indicates a break period.

### 🔐 Door Lock Integration (Optional)
- Servo or electromagnetic lock can be integrated to **lock/unlock classroom doors** based on schedule (customizable in code).

---

## 🧰 Hardware Components

| Component          | Description                          |
|-------------------|--------------------------------------|
| Arduino UNO       | Main microcontroller                 |
| LCD Display (16x2)| Displays timetable and break info    |
| Buzzer            | Signals start/end of sessions        |
| Servo Motor       | Simulates bell movement              |
| LEDs (Green/Red)  | Show class/break states              |
| Push Button       | For manual ringing                   |
| Resistors         | 220Ω or 10kΩ depending on usage      |
| Power Supply      | 5V or USB from computer              |
| Jumper Wires      | For circuit connections              |
| Breadboard        | Prototyping platform                 |

---

## 🔌 Circuit Diagram

> _Include a Fritzing diagram or hand-drawn image showing connections between components._

---

## 💾 Arduino Code Features

- `millis()` based timer for real-time elapsed time tracking.
- `Servo.h` and `LiquidCrystal.h` libraries for control.
- Conditional logic for class vs break period detection.
- Modular code structure for maintainability.

---

## 🚀 How It Works

1. System starts and sets current time/class.
2. Servo rotates at class start; buzzer rings if break ends.
3. LCD shows current class and real-time timer.
4. During break, LCD shows countdown and red LED lights up.
5. Manual ringing possible via push button.
6. After class ends, servo resets and buzzer rings again.

---

## 🧪 Sample Output

```
LCD Output:
[Class: Science]
[Time: 00:14:23]

LCD Output (Break):
[Break Time!]
[Time Left: 00:00:15]
```

---

## 🧱 Libraries Used

```cpp
#include <Servo.h>
#include <LiquidCrystal.h>
```

---

## 📈 Future Enhancements

- ⏱️ Add **RTC module (e.g., DS3231)** for real-time accuracy.
- 🔐 Integrate **electromagnetic door lock**.
- 📱 Remote control via **Bluetooth or IoT (e.g., ESP8266)**.
- 🖥️ Upload schedule from **external source (CSV/EEPROM)**.
- 🧠 Add **sound detection** for ambient response or override.

---

## ⚠️ Disclaimer

> This system is a **prototype for educational use** and not meant for deployment in critical security zones without additional safety and backup mechanisms.

---

## 🏫 Ideal For

> 🎓 **School/College Projects**  
> 🏫 **Automation Demonstrations**  
> 💡 **Intro to Embedded Systems**

---

