#define MY_PIN_LED 15
#define PIN_BUTTON 13
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin MY_PIN_LED as an output.
  pinMode(MY_PIN_LED, OUTPUT);
  pinMode(PIN_BUTTON, INPUT);
}
// the loop function runs over and over again forever
void loop() {
  if (digitalRead(PIN_BUTTON) == LOW) {
    digitalWrite(MY_PIN_LED,HIGH);
  }else{
    digitalWrite(MY_PIN_LED,LOW);
  }
}