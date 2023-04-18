#define SERIAL_RATE (9600)
// 연산을 위한 열거형 상수
enum OpType {
  OP_ADD,
  OP_SUB,
  OP_MUL,
  OP_DIV,
  OP_REM
};
int nNumMax = 20;  // 암산할 최대 자연수
int nOpMax = OP_SUB;

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

int inputInt(const String& sTitle) {
  String sN = input(sTitle);
  int n = sN.toInt();
  Serial.println(n);
  return n;
}

void printProblem(int a, int b, OpType op) {
  switch (op) {
    case OP_ADD: Serial.println(String(a) + " + " + String(b) + " = ?"); break;
    case OP_SUB: Serial.println(String(a) + " - " + String(b) + " = ?"); break;
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(SERIAL_RATE);
  randomSeed(analogRead(A0));  // 난수 발생 초기화
}

void loop() {
  // put your main code here, to run repeatedly:
  int a = random(1, nNumMax + 1);     // 1~nNumMax까지 난수 발생
  int b = random(1, nNumMax + 1);     // 1~nNumMax까지 난수 발생
  OpType op = random(0, nOpMax + 1);  // 0~nOpMax까지 난수 발생
  printProblem(a, b, op);
  unsigned long startTime = millis(); // 밀리초 단위로 현재 시간 출력
  int playAns = inputInt("답은? ");
  unsigned long calcTime = millis() - startTime; // 계산 시간 = 끝 시간 - 시작 시간
  Serial.println("\n암산 시간 = " + String(calcTime / 1e3) + "초");
}
