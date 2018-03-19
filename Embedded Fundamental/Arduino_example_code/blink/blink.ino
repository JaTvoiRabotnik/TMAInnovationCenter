/* Blink led with LoLin32 Board*/
#define LED_IN  27  // assign input digital pin for led module with port D1
 void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_IN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_IN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_IN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
