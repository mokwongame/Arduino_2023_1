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

void setup() {
  // put your setup code here, to run once:
  Serial.begin(SERIAL_RATE);
}

void loop() {
  // put your main code here, to run repeatedly:
  String sX = input("입력 x: ");
  double x = sX.toDouble();
  Serial.println(x);
}
