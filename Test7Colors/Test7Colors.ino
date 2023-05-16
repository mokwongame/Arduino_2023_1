#define PIN_R (8)
#define PIN_G (9)
#define PIN_B (10)
#define CHECK_R (1)
#define CHECK_G (2)
#define CHECK_B (4)
/*
RGB 색깔 표시 => 3비트 처리
000(0): Black
001(1): R
010(2): G
100(4): B
*/
void initLed() {
  pinMode(PIN_R, OUTPUT);
  pinMode(PIN_G, OUTPUT);
  pinMode(PIN_B, OUTPUT);
}

void turnRgbLed(int nColor) {
  int nR = nColor & CHECK_R;  // &: 비트 단위 and 연산
  int nG = nColor & CHECK_G;
  int nB = nColor & CHECK_B;
  digitalWrite(PIN_R, (nR) ? HIGH : LOW);
  digitalWrite(PIN_G, (nG) ? HIGH : LOW);
  digitalWrite(PIN_B, (nB) ? HIGH : LOW);
}

void setup() {
  // put your setup code here, to run once:
  initLed();
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 1; i <= 7; i++)
  {
      turnRgbLed(i);
      delay(500);
  }
}




