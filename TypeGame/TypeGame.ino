#define SERIAL_RATE (9600)
#define MAX_RAND_CHAR (26+5) // 알파벳 소문자 + 구두점 기호

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

// 소문자 알파벳이나 구두점 기호(" .,!?")를 반환
char getRandChar() {
  char ch;
  int nRand = random(MAX_RAND_CHAR);
  if (nRand <= 25) ch = (char)(nRand + 'a'); // 알파벳 소문자
  else if (nRand == 26) ch = ' '; // 공백
  else if (nRand == 27) ch = '.'; // 마침표
  return ch;
}

// 난수된 길이 nMaxChar를 가진 문장 반환
String makeRandWords(int nMaxChar) {
  String str;
  for (int i = 0; i < nMaxChar; i++) {
    // str에 char 더하기
    char ch = getRandChar();
    str += ch;
  }
  return str;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(SERIAL_RATE);
  randomSeed(analogRead(A0));  // 난수 초기화
}

void loop() {
  // put your main code here, to run repeatedly:
  String sRand = makeRandWords(15);
  Serial.println("문제>" + sRand);
  String sInput = input("타자>");
  Serial.println(sInput);
}
