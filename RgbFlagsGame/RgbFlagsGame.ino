#define SERIAL_RATE (9600)
#define PIN_R (8)
#define PIN_G (9)
#define PIN_B (10)
#define CHECK_R (1)
#define CHECK_G (2)
#define CHECK_B (4)
#define LEFT_BUTTON (2)
#define RIGHT_BUTTON (3)
#define DELAY_LED (200)

enum ButtonType {  // 버튼이 눌러진 상태용 열거형 상수
  BT_NONE,
  BT_LEFT,
  BT_RIGHT,
  BT_BOTH
};

void initLed() {
  pinMode(PIN_R, OUTPUT);
  pinMode(PIN_G, OUTPUT);
  pinMode(PIN_B, OUTPUT);
}

void initGame() {
  Serial.begin(SERIAL_RATE);
  pinMode(LEFT_BUTTON, INPUT_PULLUP);
  pinMode(RIGHT_BUTTON, INPUT_PULLUP);
  randomSeed(analogRead(A0));
  initLed();
}

void turnRgbLed(int nColor) {
  int nR = nColor & CHECK_R;  // &: 비트 단위 and 연산
  int nG = nColor & CHECK_G;
  int nB = nColor & CHECK_B;
  digitalWrite(PIN_R, (nR) ? HIGH : LOW);
  digitalWrite(PIN_G, (nG) ? HIGH : LOW);
  digitalWrite(PIN_B, (nB) ? HIGH : LOW);
}

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

void displayLed() {
  for (int i = 1; i <= 7; i++) {
    turnRgbLed(i);
    delay(DELAY_LED);
  }
}

void setup() {
  // put your setup code here, to run once:
  initGame();
  int nInput = getButtonInput();
  while (nInput == BT_NONE) {
    displayLed();
    nInput = getButtonInput();
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}
