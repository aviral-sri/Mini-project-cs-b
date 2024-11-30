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
3. Height of the object is calculated using the formula:
                     ***h = d_base - d_top * sin(θ_top)***

### Explanation:
- **h**: The height of the object relative to the base.
- **d_base**: The distance measured at the base angle (0°).
- **d_top** The distance measured at the top edge of the object.
- **θ_top**: The angle at which the top edge of the object is detected (measured by the servo motor).

This formula uses trigonometric principles to determine the height of the object based on the distance measurements and the angle of detection.

## Applications

The **Height Detection System** using an ultrasonic sensor and servo motor has several practical applications when implicated on large scale:

### 1. **Automated Object Height Measurement**
   - This system can be used to measure the height of objects in various industries, such as packaging, warehousing, and quality control.
   
### 2. **Robotics**
   - It can be integrated into robotic systems to measure and interact with objects based on their height, improving automation in tasks like object sorting or picking.

### 3. **3D Scanning and Mapping**
   - When combined with horizontal scanning, it can be used for basic 3D object scanning to map dimensions or shapes.

### 4. **Surveillance and Security**
   - In security applications, the system can detect the height of objects or people in specific areas to trigger alarms or record measurements.

### 5. **Construction and Architecture**
   - The system can measure the height of structures or objects at construction sites for various tasks like surveying and material management.

