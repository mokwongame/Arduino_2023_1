#define SERIAL_RATE (9600)
#define PIN_VOLT (A0)
#define PIN_R (8)
#define PIN_G (9)
#define PIN_B (10)
#define CHECK_R (1)
#define CHECK_G (2)
#define CHECK_B (4)
#define VMAX (4.9)
#define VSTEP (VMAX / 7.)

// nVolt: 0~1023 (0이면 0V, 1023이면 5V)
double getVolt(int nPort) {
  int nVolt = analogRead(nPort);  // 아날로그 포트는 A로 시작
  // 1023:5 = nVolt:volt => 1023/5 = nVolt/volt => volt = 5/1023*nVolt
  double volt = 5. / 1023. * nVolt;  // double 나눗셈을 위해 소수점 추가
  return volt;
}

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

void turnOffLed() {
  digitalWrite(PIN_R, LOW);
  digitalWrite(PIN_G, LOW);
  digitalWrite(PIN_B, LOW);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(SERIAL_RATE);
  initLed();
  turnOffLed();
}

void loop() {
  // put your main code here, to run repeatedly:
  double volt = getVolt(PIN_VOLT);
  Serial.println("volt = " + String(volt));
  // 색깔: 0~7
  // roundoff(반올림): round 함수
  int nColor = round(volt / VSTEP);  // 0~7
  Serial.println("color = " + String(nColor));
  turnRgbLed(nColor);
  delay(100);  // 100 msec 지연
}
