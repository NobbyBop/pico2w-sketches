#define LED_EXT 15

// Blinks a light connected to GP15.

void setup() {
  pinMode(LED_EXT, OUTPUT);
}

void loop() {
  digitalWrite(LED_EXT, HIGH);
  delay(1000);
  digitalWrite(LED_EXT, LOW);
  delay(1000);
}
