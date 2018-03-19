/*
 DigitalReadSerial
 Reads a digital input on pin 27, prints the result to the serial monitor
 This example code is in the public domain.
 */

// digital pin 27 has a pushbutton attached to it. Give it a name:
// you must connect module button into port D1, with input pin is 27
int const pushButton = 27;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 115200 bits per second:
  Serial.begin(115200);
  // make the pushbutton's pin an input:
  pinMode(pushButton, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  int buttonState = digitalRead(pushButton);
  // print out the state of the button:
  Serial.println(buttonState);
  delay(1);        // delay in between reads for stability
  }
