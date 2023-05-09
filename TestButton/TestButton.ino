#define LEFT_BUTTON (2)
#define RIGHT_BUTTON (3)

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LEFT_BUTTON, INPUT_PULLUP);
  pinMode(RIGHT_BUTTON, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  int nInputLeft = digitalRead(LEFT_BUTTON);
  int nInputRight = digitalRead(RIGHT_BUTTON);
  Serial.println("left = " + String(nInputLeft) + " | right = " + String(nInputRight));
  delay(500);
}
