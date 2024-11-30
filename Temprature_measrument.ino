#include <Servo.h>

// Pin Definitions
const int trigPin = 9;
const int echoPin = 10;
Servo servo;

// Variables
float baseDistance;
float currentDistance;
int topAngle = -1;
float topDistance = 0;
const float threshold = 10.0; // Threshold for detecting the edge (in cm)

// Function to Measure Distance
long measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH); // Measure the time for the echo
  return (duration * 0.034) / 2;          // Convert to cm
}

void setup() {
  // Initialize Pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Initialize Servo
  servo.attach(11);
  
  // Serial Monitor for Debugging
  Serial.begin(9600);
  
  // Measure the Base Distance at 0°
  servo.write(0); // Move servo to 0°
  delay(500);
  baseDistance = measureDistance();
  Serial.print("Base Distance: ");
  Serial.println(baseDistance);
}

void loop() {
  for (int angle = 0; angle <= 90; angle += 5) { // Sweep from 0° to 90°
    servo.write(angle); // Move servo to the angle
    delay(500); // Allow the servo to stabilize

    currentDistance = measureDistance();
    Serial.print("Angle: ");
    Serial.print(angle);
    Serial.print("° Distance: ");
    Serial.println(currentDistance);

    // Detect Top Edge (Sudden Increase in Distance)
    if (currentDistance - baseDistance > threshold) {
      topAngle = angle;
      topDistance = currentDistance;
      Serial.println("Top edge detected!");

      // Calculate Height Using Trigonometry
      float height = baseDistance - topDistance * sin(radians(topAngle));
      Serial.print("Object Height: ");
      Serial.print(height);
      Serial.println(" cm");

      delay(5000); // Pause for 5 seconds before restarting
      break; // Stop scanning after detection
    }
  }
}
