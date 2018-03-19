void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.write('1');
  delay(2000);
  Serial.write('0');
  delay(2000);
}
