# TRILIGHT
LED art piece, hardware consisting of 3 connected rings

## Setup for Mac
1. Download the Arduino IDE: https://www.arduino.cc/en/Guide/MacOSX
2. Copy folders from "Libraries" in this repo into ~/documents/arduino/libraries
3. Open a program in the Arduino IDE

## Running programs
1. Open program from the "Programs" folders in the Arduino IDE
2. Make any edits (if desired) and save
3. Connect USB cable
4. Press "upload" (right facing arrow in top bar)

## Troubleshooting


Error connecting to board:
- Tools/Board should be "Arduino/Genuino Uno"
- Tools/Port should find and recognize the Arduino ex: dev/cu.usbmodem14511 (Arduino/Genuino Uno). If it doesn't find it, try restarting the IDE with the usb plugged in.


Program not working:
- Make sure libraries files are up to date (particularly colors.h)
