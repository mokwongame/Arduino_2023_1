// nPort: 깜박일 출력 포트; nPeriod: 깜박일 주기(단위: ms)
void blinkLed(int nPort, int nPeriod) {
  digitalWrite(nPort, HIGH);  // LED on
  delay(nPeriod / 2);
  digitalWrite(nPort, LOW);  // LED off
  delay(nPeriod / 2);
}

// nVolt: 0~1023 (0이면 0V, 1023이면 5V)
double getVolt(int nPort) {
  int nVolt = analogRead(nPort);  // 아날로그 포트는 A로 시작
  // 1023:5 = nVolt:volt => 1023/5 = nVolt/volt => volt = 5/1023*nVolt
  double volt = 5. / 1023. * nVolt;  // double 나눗셈을 위해 소수점 추가
  return volt;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  double volt = getVolt(A0);
  Serial.println(volt);
  if (volt <= 0.5) blinkLed(13, 3000);
  else if (volt >= 3. && volt <= 3.6) blinkLed(13, 1000);
  else if (volt >= 4.5) blinkLed(13, 100);
}
