// nPort: 깜박일 출력 포트; nPeriod: 깜박일 주기(단위: ms)
void blinkLed(int nPort, int nPeriod) {
  digitalWrite(nPort, HIGH);  // LED on
  delay(nPeriod / 2);
  digitalWrite(nPort, LOW);  // LED off
  delay(nPeriod / 2);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(8, INPUT);    // 8번 포트를 INPUT으로 사용
  pinMode(13, OUTPUT);  // 13번 포트를 출력(output)으로 사용
}

// 입력 5V: 1초에 한번 깜박임
// 입력 0V: 3초에 한번 깜박임
void loop() {
  // put your main code here, to run repeatedly:
  int nDigital = digitalRead(8);  // 8번 포트에서 입력을 읽기
  if (nDigital == HIGH) {         // 5V
    Serial.println("high");
    blinkLed(13, 1000);  // 13번 포트를 1000 msec동안 깜박임
  } else {
    Serial.println("low");  // nDigital == LOW
    blinkLed(13, 3000);     // 13번 포트를 3000 msec동안 깜박임
  }
  //delay(1000);
}
