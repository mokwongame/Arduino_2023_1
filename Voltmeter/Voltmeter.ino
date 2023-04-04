void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // nVolt: 0~1023 (0이면 0V, 1023이면 5V)
  int nVolt = analogRead(A0);  // 아날로그 포트는 A로 시작
  // 1023:5 = nVolt:volt => 1023/5 = nVolt/volt => volt = 5/1023*nVolt
  double volt = 5. / 1023. * nVolt; // double 나눗셈을 위해 소수점 추가
  Serial.println(volt);
  delay(1000);
}
