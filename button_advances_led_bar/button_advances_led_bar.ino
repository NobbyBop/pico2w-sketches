#define BUTTON_PIN 15

short pins[10] = {28, 27, 26, 22, 21, 20, 19, 18, 17, 16};
short pindex = 0;

void setup() {
  pinMode(BUTTON_PIN, INPUT);

  // Set each of the LED BAR pins as outputs.
  for(short i = 0; i < 10; i++){
    pinMode(pins[i], OUTPUT);
  }

  //Initialize the first LED BAR to ON.
  digitalWrite(pins[pindex], HIGH);
}

void loop() {
  if(digitalRead(BUTTON_PIN) == LOW){
    delay(20);
    if(digitalRead(BUTTON_PIN) == LOW){
      // the button has been pressed.
      digitalWrite(pins[pindex], LOW);
      pindex++;
      if(pindex > 9){
        pindex = 0;
      }
      digitalWrite(pins[pindex], HIGH);
    }
    while(digitalRead(BUTTON_PIN) == LOW);
  }
}