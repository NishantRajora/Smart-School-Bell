Project Overview: Automated School Bell System whith door lock, and timetable display
This code is for an Automated School Bell System that manages a school’s bell ringing schedule using an Arduino, a servo motor, an LCD, a buzzer, and LED indicators. The system displays class schedules, indicates break times, and automates bell ringing at the beginning and end of classes.


Shows the current class name and elapsed time in hours, minutes, and seconds.
During break time, displays “Break Time!” with a 15-second countdown.
Servo Motor Control:

The servo motor rotates clockwise to 90 degrees to indicate the start of a class and back to 0 degrees after the class ends.
This motion simulates the ringing of a traditional bell.
Buzzer Activation:

The buzzer sounds at the end of each class to signal the beginning of a break.
A button allows for manual bell ringing at any time, activating the buzzer for 3 seconds.
LED Indicators:

Green LED: Indicates an ongoing class session.
Red LED: Indicates a break period.
