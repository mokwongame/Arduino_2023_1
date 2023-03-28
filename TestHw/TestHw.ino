void setup() {  // 한번만 호출
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);  // 13번에 LED 연결; 13번을 출력(OUTPUT)
}

void loop() {  // 계속 호출
  // put your main code here, to run repeatedly:
  // HIGH: 5V, LOW: 0V
  digitalWrite(13, HIGH); // 13번 포트에 출력을 HIGH
  delay(1000); // CPU를 1000 msec(밀리초) 동안 지연(delay)
  digitalWrite(13, LOW); // 13번 포트에 출력을 LOW
  delay(1000);
} // 다 끝나면 loop() 함수 처음 부분이 다시 실행
