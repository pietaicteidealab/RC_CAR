#include "BluetoothSerial.h"
BluetoothSerial SerialBT;

int enA = 14;
int enB = 27;
int in1 = 26;
int in2 = 25;
int in3 = 33;
int in4 = 32;
int speed = 200; // Motor speed (0-255)

void setup() {
  Serial.begin(115200);
  SerialBT.begin("Idea lab car");  // Bluetooth device name
  Serial.println("Bluetooth started. Pair with ESP32_CAR.");

  // Pin setup   
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
}

void loop() {
  if (SerialBT.available()) {      // Read from Bluetooth, not Serial
    char command = SerialBT.read();
    moveCar(command);
  }
}

void moveCar(char command) {
  switch (command) {
    case 'F': forward(); break;
    case 'B': backward(); break;
    case 'L': left(); break;
    case 'R': right(); break;
    case 'I': forwardRight(); break;
    case 'J': backwardRight(); break;
    case 'G': forwardLeft(); break;
    case 'H': backwardLeft(); break;
    default: stopCar();
  }
}

void forward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, speed);
  analogWrite(enB, speed);
}

void backward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, speed);
  analogWrite(enB, speed);
}

void left() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, speed);
  analogWrite(enB, speed);
}

void right() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, speed);
  analogWrite(enB, speed);
}

void forwardRight() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, speed);
  analogWrite(enB, speed / 2);
}

void backwardRight() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, speed);
  analogWrite(enB, speed / 2);
}

void forwardLeft() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, speed / 2);
  analogWrite(enB, speed);
}

void backwardLeft() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, speed / 2);
  analogWrite(enB, speed);
}

void stopCar() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
