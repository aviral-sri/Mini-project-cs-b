// Pin definitions and constants
#define NTC_PIN A0                 // Pin connected to the voltage divider
#define VD_POWER_PIN 7             // Pin to power the voltage divider (optional)
#define SAMPLING_RATE 10           // Number of samples to average
#define RREF 10000.0               // Reference resistor value in ohms
#define NOMINAL_RESISTANCE 10000.0 // Resistance of the thermistor at 25°C
#define NOMINAL_TEMPERATURE 25.0   // Nominal temperature in Celsius
#define BETA 3950.0                // Beta coefficient of the thermistor

void setup() {
  pinMode(VD_POWER_PIN, OUTPUT);
  digitalWrite(VD_POWER_PIN, LOW); // Ensure the divider is off initially
  Serial.begin(9600);
  Serial.println("Thermistor Temperature Measurement");
}

void loop() {
  uint8_t i;
  float samples = 0;
  float average;

  // Power the voltage divider
  digitalWrite(VD_POWER_PIN, HIGH);

  // Take voltage readings
  for (i = 0; i < SAMPLING_RATE; i++) {
    samples += analogRead(NTC_PIN);
    delay(10); // Small delay between samples
  }

  // Turn off the voltage divider to save power (optional)
  digitalWrite(VD_POWER_PIN, LOW);

  // Calculate the average ADC reading
  average = samples / SAMPLING_RATE;
  Serial.print("ADC Reading: ");
  Serial.println(average);

  // Calculate thermistor resistance
  average = 1023 / average - 1; // (Vin/Vout - 1)
  average = RREF / average;    // Resistance of the thermistor
  Serial.print("Thermistor Resistance: ");
  Serial.print(average);
  Serial.println(" ohms");

  // Calculate temperature using the Steinhart-Hart equation
  float temperature;
  temperature = average / NOMINAL_RESISTANCE;           // (R/Ro)
  temperature = log(temperature);                      // ln(R/Ro)
  temperature /= BETA;                                 // 1/B * ln(R/Ro)
  temperature += 1.0 / (NOMINAL_TEMPERATURE + 273.15); // + (1/To)
  temperature = 1.0 / temperature;                     // Invert
  temperature -= 273.15;                               // Convert Kelvin to Celsius

  // Print temperature
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  delay(1000); // Wait before the next reading
}
