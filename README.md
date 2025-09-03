# ESP32 Bluetooth Controlled Car

## Overview
This project controls a car using an ESP32 DevKit V1 via Bluetooth and an L298N motor driver.

## Components
- ESP32 DevKit V1
- L298N Motor Driver
- DC Motors (BO Motors)
- Bluetooth (built-in ESP32)
- Battery (7.4V – 12V depending on motor)

## Commands
- `F` → Forward
- `B` → Backward
- `L` → Left
- `R` → Right
- `I` → Forward Right
- `J` → Backward Right
- `G` → Forward Left
- `H` → Backward Left

## Wiring

| ESP32 Pin | L298N Pin | Function             |
|-----------|-----------|----------------------|
| GPIO14    | ENA       | Enable Motor A (PWM) |
| GPIO26    | IN1       | Motor A Direction 1  |
| GPIO25    | IN2       | Motor A Direction 2  |
| GPIO27    | ENB       | Enable Motor B (PWM) |
| GPIO33    | IN3       | Motor B Direction 1  |
| GPIO32    | IN4       | Motor B Direction 2  |
| 5V        | 5V (Logic)| L298N logic supply   |
| GND       | GND       | Common ground        |
| Battery + | 12V (Vs)  | Motor power supply   |

- **OUT1, OUT2** → Motor A  
- **OUT3, OUT4** → Motor B  

⚠️ Note: Connect ESP32 **GND** and L298N **GND** together

## Circuit Diagram

![Circuit Diagram](Diagram/Rc car circuit.jpg)

## Install USB Driver for ESP32

To upload code into ESP32 using Arduino IDE, you need to install the USB-to-UART driver:

- [CP210X USB Driver (Windows, Mac, Linux)](https://www.silabs.com/software-and-tools/usb-to-uart-bridge-vcp-drivers?tab=downloads)
- [CH340 USB Driver (Windows, Mac, Linux)](https://sparks.gogo.co.nz/ch340.html)

Download and install the driver.
## In Arduino IDE:

Go to Tools → Board.

Install ESP32 board support (if not already):

File → Preferences → Additional Board Manager URLs
Add:https://dl.espressif.com/dl/package_esp32_index.json
Then go to Tools → Board → Board Manager → search ESP32 → Install.

Recompile and upload.




## How to Use
1. Upload the `RC_Code.ino` file to ESP32 using Arduino IDE.
2. Pair ESP32 with phone using Bluetooth (Device Name: `Idea lab car`).
3. Use a Bluetooth terminal app to send the commands (`F`, `B`, `L`, `R`, etc.).
4. The car moves based on the command received.

