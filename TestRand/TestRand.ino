void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //randomSeed(100); // 난수 발생 초기값(종자값)
  randomSeed(analogRead(A0)); // 연결되지 않은 아날로그 포트 A0 값 읽기로 난수 초기화
}

void loop() {
  // put your main code here, to run repeatedly:
  //int n = random(10); // 0~9 범위의 난수
  int n = random(1, 31); // 1~30 범위의 난수 발생
  Serial.println(n);
  delay(1000);
}
