const int currentPin = A0;  // Connect OUT1 to A0
float voltage, current;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int analogValue = analogRead(currentPin);
  voltage = analogValue * (5.0 / 1023.0); // Convert ADC to voltage

  // For example, if sensor is 0.066 V/A (66mV per Amp for ACS712 30A type)
  current = (voltage - 2.4935) / 0.066;  // Adjust based on your sensor specs

  Serial.print("Current: ");
  Serial.print(current);
  Serial.println(" A");

  delay(500);
}
