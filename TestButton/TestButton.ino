#define LEFT_BUTTON (2)
#define RIGHT_BUTTON (3)

enum ButtonType {  // 버튼이 눌러진 상태용 열거형 상수
  BT_NONE,
  BT_LEFT,
  BT_RIGHT,
  BT_BOTH
};

ButtonType getButtonInput() {
  int nInputLeft = digitalRead(LEFT_BUTTON);
  int nInputRight = digitalRead(RIGHT_BUTTON);
  ButtonType nResult;
  if (nInputLeft == LOW) {
    if (nInputRight == LOW) nResult = BT_BOTH;
    else nResult = BT_LEFT;
  } else {
    if (nInputRight == LOW) nResult = BT_RIGHT;
    else nResult = BT_NONE;
  }
  return nResult;
}

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

  ButtonType nResult = getButtonInput();
  Serial.println("button type = " + String(nResult));
  delay(500);
}
