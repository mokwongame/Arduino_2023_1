// nPort: 깜박일 출력 포트; nPeriod: 깜박일 주기(단위: ms)
void blinkLed(int nPort, int nPeriod) {
  digitalWrite(nPort, HIGH); // LED on
  delay(nPeriod/2);
  digitalWrite(nPort, LOW); // LED off
  delay(nPeriod/2);
}

void setup() {  // 한번만 호출
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);  // 13번에 LED 연결; 13번을 출력(OUTPUT)
}

void loop() {  // 계속 호출
  // put your main code here, to run repeatedly:
  blinkLed(13, 2000); // 13번 포트를 2000 msec동안 깜박임
} // 다 끝나면 loop() 함수 처음 부분이 다시 실행
