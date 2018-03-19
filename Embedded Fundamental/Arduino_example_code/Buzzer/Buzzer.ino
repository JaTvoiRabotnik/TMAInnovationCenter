#define speakerPin 27
void setup() {
  // put your setup code here, to run once:
  pinMode (speakerPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(speakerPin, HIGH);
  delay(200);
  digitalWrite(speakerPin, LOW);
  delay(1000);
}
