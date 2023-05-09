#define SERIAL_RATE (9600)
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

void initGame() {
  Serial.begin(SERIAL_RATE);
  pinMode(LEFT_BUTTON, INPUT_PULLUP);
  pinMode(RIGHT_BUTTON, INPUT_PULLUP);
  randomSeed(analogRead(A0));
}

void setup() {
  // put your setup code here, to run once:
  initGame();
}

void loop() {
  // put your main code here, to run repeatedly:
  // 버튼 누르지 않는 상태 확인
  ButtonType nInput = getButtonInput();
  while (nInput != BT_NONE) {
    Serial.println("버튼을 누르지 마세요.");
    delay(500);
    nInput = 
    getButtonInput();
  }
  // 난수 발생, 게임 시작
}
