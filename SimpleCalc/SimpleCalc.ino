#define SERIAL_RATE (9600)

String input(const String& sTitle) {
  Serial.print(sTitle);
  while (Serial.available() == 0)
    ;
  String sInput;
  while (Serial.available()) {
    char c = Serial.read();
    sInput += c;
    delay(10);  // Serial 속도와 관계
  }
  sInput.trim();
  return sInput;
}

// &: reference(참조) 표시; 값을 가져오지 않고 직접 위치에 접근해서 참조
// const: 함수 내부에서 입력 변수를 상수(const)로 취급(변경하지 않음)
double inputDouble(const String& sTitle) {
  String sX = input(sTitle);
  double x = sX.toDouble();
  Serial.println(x);
  return x;
}

char inputOp(const String& sTitle) {
  String sOp = input(sTitle);
  char op = sOp[0]; // 0번 위치의 문자를 가져옴
  Serial.println(op);
  return op;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(SERIAL_RATE);
}

void loop() {
  // put your main code here, to run repeatedly:
  double x = inputDouble("입력 x: ");
  double y = inputDouble("입력 y: ");
  char op = inputOp("연산자: ");
}
