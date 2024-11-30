# Thermistor Temperature Measurement using Arduino

## Overview
This project demonstrates how to measure temperature using an NTC thermistor and an Arduino. The thermistor's resistance varies with temperature, and the Arduino calculates the temperature using the Steinhart-Hart equation. The results are displayed on the Serial Monitor.

---

## Features
- Accurate temperature measurement using a thermistor.
- Noise reduction through sampling and averaging.
- Optional power control for the voltage divider to save energy.
- Outputs include ADC values, thermistor resistance, and temperature in °C.

---

## Components Required
- **Arduino Board** (e.g., Uno, Nano, etc.)
- **NTC Thermistor (10kΩ)**  
- **Resistor (10kΩ)** (for voltage divider)
- **Jumper Wires** and **Breadboard**
- (Optional) **0.1 µF Capacitor** (for noise reduction)

---

## Circuit Diagram
1. Connect one leg of the thermistor to **5V**.  
2. Connect the other leg of the thermistor to:
   - One end of the **10kΩ resistor**.  
   - **Analog pin A0** (middle connection).  
3. Connect the other end of the **10kΩ resistor** to **GND**.  
4. (Optional) Connect the junction of the thermistor and resistor to a **control pin** (e.g., pin 7) for power control.  

---

## Code Explanation
1. **Power Control**:  
   The voltage divider can be powered via a digital pin to save energy in battery-powered applications.  
   ```cpp
   #define VD_POWER_PIN 7
   digitalWrite(VD_POWER_PIN, HIGH); // Power on
   digitalWrite(VD_POWER_PIN, LOW);  // Power off
