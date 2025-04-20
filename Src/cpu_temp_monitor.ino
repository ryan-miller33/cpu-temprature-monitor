const int sensorPin = A0;
float voltage, temperature;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  voltage = sensorValue * (5.0 / 1023.0);
  temperature = voltage * 100.0; // LM35: 10mV per degree Celsius

  Serial.print("CPU Temp: ");
  Serial.print(temperature);
  Serial.println(" °C");

  delay(1000);
}
