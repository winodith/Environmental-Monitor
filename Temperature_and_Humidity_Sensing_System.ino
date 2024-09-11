#include "DHT.h"

// Define the sensor pins and LED pins
#define DHTPIN 2 // DHT22 data pin
#define DHTTYPE DHT22
#define MOISTURE_PIN A0 // Soil Moisture Sensor analog pin
#define GREEN_LED 9
#define RED_LED 10

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Initialize Serial, sensors, and LEDs
  Serial.begin(9600);
  dht.begin();
  pinMode(MOISTURE_PIN, INPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
}

void loop() {
  // Read data from DHT22
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Read soil moisture level
  int moistureLevel = analogRead(MOISTURE_PIN);

  // Print data to Serial for debugging
  Serial.print("Temperature: ");
  Serial.println(temperature);
  Serial.print("Humidity: ");
  Serial.println(humidity);
  Serial.print("Soil Moisture Level: ");
  Serial.println(moistureLevel);

  // Logic for LEDs
  digitalWrite(GREEN_LED, HIGH);  // Keep Green LED on

  if (temperature > 30 && moistureLevel < 300) {
    digitalWrite(RED_LED, HIGH);  // Turn Red LED on if temperature > 30 and soil moisture is low
  } else {
    digitalWrite(RED_LED, LOW);   // Otherwise, turn Red LED off
  }

  delay(2000); // Wait 2 seconds before next reading
}
