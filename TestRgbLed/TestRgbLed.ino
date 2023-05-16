#define PIN_R (8)
#define PIN_G (9)
#define PIN_B (10)

void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_R, OUTPUT);
  pinMode(PIN_G, OUTPUT);
  pinMode(PIN_B, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(PIN_B, LOW);
  digitalWrite(PIN_R, HIGH);
  delay(1000);
  digitalWrite(PIN_R, LOW);
  digitalWrite(PIN_G, HIGH);
  delay(1000);
  digitalWrite(PIN_G, LOW);
  digitalWrite(PIN_B, HIGH);
  delay(1000);
}
