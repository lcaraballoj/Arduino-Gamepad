uint8_t buf[8] = {0}; //Initializes the keyboard buffer

const int SW_Pin = 2;
const int X_Pin = 0;
const int Y_Pin = 1;

//Key Press Buttons
#define pin_W 4
#define pin_A 5
#define pin_S 6
#define pin_D 7

void setup() {
  pinMode(SW_Pin, INPUT);
  pinMode(pin_W, INPUT);
  pinMode(pin_A, INPUT);
  pinMode(pin_S, INPUT);
  pinMode(pin_D, INPUT);

  digitalWrite(SW_Pin, HIGH);

  Serial.begin(9600);
}

void loop() {

  Serial.print("Switch: ");
  Serial.print(digitalRead(SW_Pin));
  Serial.print("\n");
  Serial.print("X-axis: ");
  Serial.print(analogRead(X_Pin));
  Serial.print("\n");
  Serial.print("Y-axis: ");
  Serial.print(analogRead(Y_Pin));
  Serial.print("\n");  

  if (digitalRead(pin_W) == HIGH) {
    buf[2] = 26;
    Serial.write(buf, 8);
    Serial.println("W Pressed");

    delay(200);

    keyReleased();
  }
  if (digitalRead(pin_A) == HIGH) {
    buf[2] = 26;
    Serial.write(buf, 8);
    Serial.println("A Pressed");

    delay(200);

    keyReleased();
  }

   if (digitalRead(pin_S) == HIGH) {
    buf[2] = 26;
    Serial.write(buf, 8);
    Serial.println("S Pressed");

    delay(200);

    keyReleased();
  }
  
  if (digitalRead(pin_D) == HIGH) {
    buf[2] = 26;
    Serial.write(buf, 8);
    Serial.println("D Pressed");

    delay(200);

    keyReleased();
  }
  
  Serial.print("\n\n");
  delay(200);
}

void keyReleased() {
  buf[0] = {0};
  buf[2] = {0};
  Serial.write(buf, 8);
}
