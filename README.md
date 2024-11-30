# Ultrasonic Height Detector

This project measures the height of an object using an **ultrasonic sensor** and a **servo motor**, calculating height with trigonometry.

## Components
- **Arduino Uno/ESP32**
- **HC-SR04 Ultrasonic Sensor**
- **SG90 Servo Motor**
- Breadboard, Jumper Wires, Power Supply

## Circuit Connections
| **Component Pin** | **Connect To**     |
|--------------------|--------------------|
| HC-SR04 VCC        | 5V                |
| HC-SR04 GND        | GND               |
| HC-SR04 TRIG       | Digital Pin 9     |
| HC-SR04 ECHO       | Digital Pin 10    |
| Servo Motor VCC    | 5V                |
| Servo Motor GND    | GND               |
| Servo Motor Signal | Digital Pin 11    |

## How It Works
1. The servo sweeps from 0° to 90° while measuring distances.
2. A sudden increase in distance detects the object’s top edge.
3. Height is calculated using:
   \[
   h = d_{\text{base}} - d_{\text{top}} \cdot \sin(\theta_{\text{top}})
   \]

## Code
```cpp
#include <Servo.h>

const int trigPin = 9, echoPin = 10;
Servo servo;
float baseDistance, currentDistance, topDistance = 0;
int topAngle = -1; const float threshold = 10.0;

long measureDistance() {
  digitalWrite(trigPin, LOW); delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  return (pulseIn(echoPin, HIGH) * 0.034) / 2;
}

void setup() {
  pinMode(trigPin, OUTPUT); pinMode(echoPin, INPUT);
  servo.attach(11); Serial.begin(9600); 
  servo.write(0); delay(500);
  baseDistance = measureDistance();
}

void loop() {
  for (int angle = 0; angle <= 90; angle += 5) {
    servo.write(angle); delay(500);
    currentDistance = measureDistance();
    if (currentDistance - baseDistance > threshold) {
      topAngle = angle; topDistance = currentDistance;
      float height = baseDistance - topDistance * sin(radians(topAngle));
      Serial.print("Height: "); Serial.println(height);
      delay(5000); break;
    }
  }
}
