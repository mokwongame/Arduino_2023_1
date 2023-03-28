void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(8, INPUT); // 8번 포트를 INPUT으로 사용  
}

void loop() {
  // put your main code here, to run repeatedly:
  int nDigital = digitalRead(8); // 8번 포트에서 입력을 읽기
  if (nDigital == HIGH) Serial.println("high");
  else Serial.println("low"); // nDigital == LOW
  delay(1000);
}
