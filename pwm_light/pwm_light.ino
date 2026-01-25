#define LED_PIN 15 //define the led pin

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  for (int i = 0; i < 255; i++) { //make light fade in
    analogWrite(LED_PIN, i);
    delay(5);
  }
  for (int i = 255; i > -1; i--) { //make light fade out
    analogWrite(LED_PIN, i);
    delay(5);
  }
}