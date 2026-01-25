// const byte ledPins[] = {16, 17, 18, 19, 20, 21, 22, 26, 27, 28}; //define led pins
// const int dutys[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4095, 2047, 1023, 512, 256, 128, 64, 32, 16, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; //define the pwm dutys
// int ledCounts; //the number of leds

// int delayTimes = 50; //flowing speed ,the smaller, the faster

// void setup() {
//   ledCounts = sizeof(ledPins); //get the led counts
//   for (int i = 0; i < ledCounts; i++) { //setup the pwm channels
//   pinMode(ledPins[i], OUTPUT);
// }
// }
// void loop() {
//   for (int i = 0; i < 20; i++) { //flowing one side to other side
//     for (int j = 0; j < ledCounts; j++) {
//       analogWrite(ledPins[j], map(dutys[i+j], 0, 4095, 0, 255));
//     }
//     delay(delayTimes);
//   }
//   for (int i = 0; i < 20; i++) { //flowing one side to other side
//     for (int j = 0; j < ledCounts; j++) {
//       analogWrite(ledPins[ledCounts - j - 1], map(dutys[i+j], 0, 4095, 0, 255));
//     }
//     delay(delayTimes);
//   }
// }

/* This is an interesting approach... 
 but I am going to try it in a way that makes more sense intuitively to me.
 I don't like or understand the need for using map here. It overcomplicates the readability.
*/


const byte ledPins[] = {16, 17, 18, 19, 20, 21, 22, 26, 27, 28}; //define led pins
const byte strengths[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  255, 192, 96, 48, 24, 16, 8, 4, 2, 1, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

// 1 for forwards, 0 for backwards
char direction = 1;

/*
 Location is the location of each pin in the sequence of strengths.
 Going forward it is initialized like this:
 [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
 and backwards like:
 [9, 8, 7, 6, 5, 4, 3, 2, 1]
 And each iteration of the outer loop advances each number by one, so the first pin will get to
 255 first, then the second, and so on, and then decrease, until all pins have gotten 255 and then back down to 0.
 The direction just controls which pin (front/back) gets to go first.
 */

short location[10];

void setup() {
  for (int i = 0; i < 10; i++) { //setup the pwm channels
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {

  // One way...
  if(direction){
    for(int i = 0; i < 10; i++){
      location[i] = i;
    }
  } else {
    for(int i = 0; i < 10; i++){
      location[i] = 9-i;
    }
  }

  for(int i = 0; i < 20; i++){
    for(int j = 0; j < 10; j++){
      analogWrite(ledPins[j], strengths[location[j]]);
      location[j] = location[j] + 1;
    }
    delay(50);
  }

  direction = 1-direction;

}