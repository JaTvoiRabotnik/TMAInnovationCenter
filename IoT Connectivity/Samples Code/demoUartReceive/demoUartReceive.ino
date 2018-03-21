void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  //digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available() > 0) {
    char ch = Serial.read();
    if (ch == '0') {
      Serial.println("Tat den");
      digitalWrite(LED_BUILTIN, HIGH);
    }
    if (ch == '1') {
      Serial.println("Bat den");
      digitalWrite(LED_BUILTIN, LOW);
    }
  }
}
