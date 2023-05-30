#define SERIAL_RATE  (9600)
#define PIN_VOLT    (A0)

// nVolt: 0~1023 (0이면 0V, 1023이면 5V)
double getVolt(int nPort) {
  int nVolt = analogRead(nPort);  // 아날로그 포트는 A로 시작
  // 1023:5 = nVolt:volt => 1023/5 = nVolt/volt => volt = 5/1023*nVolt
  double volt = 5. / 1023. * nVolt;  // double 나눗셈을 위해 소수점 추가
  return volt;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(SERIAL_RATE);
}

void loop() {
  // put your main code here, to run repeatedly:
  double volt = getVolt(PIN_VOLT);
  Serial.println("volt = " + String(volt));
  delay(500); // 500 msec 지연
}



