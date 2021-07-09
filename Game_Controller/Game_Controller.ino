#include <Keyboard.h>
#include <Mouse.h>

//Joystick
const int SW_Pin = 2;
const int X_Pin = A0;
const int Y_Pin = A1;

//Key Press Buttons
#define pin_W 10
#define pin_A 15
#define pin_S 14
#define pin_D 16

// parameters for reading the joystick:
int range = 12;               // output range of X or Y movement
int responseDelay = 5;        // response delay of the mouse, in ms
int threshold = range / 4;    // resting threshold
int center = range / 2;       // resting position value

void setup() {
  pinMode(SW_Pin, INPUT_PULLUP);
  pinMode(pin_W, INPUT_PULLUP);
  pinMode(pin_A, INPUT_PULLUP);
  pinMode(pin_S, INPUT_PULLUP);
  pinMode(pin_D, INPUT_PULLUP);

  Keyboard.begin();
  Mouse.begin();
  digitalWrite(SW_Pin, HIGH);

  Serial.begin(9600);
}

void loop() {
  while (digitalRead(pin_W) == LOW) {
    Keyboard.press('w');
    Serial.println("w Pressed");
  }

  //delay(100);

  Keyboard.release('w');

  while (digitalRead(pin_A) == LOW) {
    Keyboard.press('a');
    Serial.println("a Pressed");
  }

  //delay(100);

  Keyboard.release('a');


  while (digitalRead(pin_S) == LOW) {
    Keyboard.press('s');
    Serial.println("s Pressed");
  }

  //delay(100);

  Keyboard.release('s');


  while (digitalRead(pin_D) == LOW) {
    Keyboard.press('d');
    Serial.println("d Pressed");
  }

  //delay(100);

  Keyboard.release('d');


  //Read in joystick input
  int xReading = -readAxis(X_Pin);
  int yReading = -readAxis(Y_Pin);

  Mouse.move(xReading, yReading, 0);
  if (digitalRead(SW_Pin) == LOW) {
    Mouse.press(MOUSE_LEFT);
  } else {
    if (Mouse.isPressed(MOUSE_LEFT)) {
      Mouse.release(MOUSE_LEFT);
    }
  }

  delay(5);

}

int readAxis(int axis) {
  int reading = analogRead(axis);
  reading = map(reading, 0, 1023, 0, range);
  int distance = reading - center;

  if (abs(distance) < threshold) {
    distance = 0;
  }
  return distance;
}
