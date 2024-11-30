+# Ultrasonic Height Detector

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
3. ## Height Calculation Formula

The height of the object is calculated using the formula:

\[
h = d_{\text{base}} - d_{\text{top}} \cdot \sin(\theta_{\text{top}})
\]

### Explanation:
- **\( h \)**: The height of the object relative to the base.
- **\( d_{\text{base}} \)**: The distance measured at the base angle (0°).
- **\( d_{\text{top}} \)**: The distance measured at the top edge of the object.
- **\( \theta_{\text{top}} \)**: The angle at which the top edge of the object is detected (measured by the servo motor).

This formula uses trigonometric principles to determine the height of the object based on the distance measurements and the angle of detection.
