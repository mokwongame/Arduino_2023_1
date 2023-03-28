void setup() {
  // put your setup code here, to run once:
  // Serial: class(설계도)의 instance(예시, 설계도로 제품)
  // class 자료형으로 만든 변수는 instance라고 부름
  Serial.begin(9600); // Serial을 9600 bps(bits per second)로 시작
  // .begin(): Serial instance가 가진 멤버 함수(method)
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Hello, world");
  delay(1000);
}
