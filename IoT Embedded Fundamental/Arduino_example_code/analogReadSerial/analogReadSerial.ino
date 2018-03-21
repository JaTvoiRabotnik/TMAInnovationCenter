/*
  AnalogReadSerial
  Reads an analog input on pin 34, prints the result to the serial monitor.
  Graphical representation is available using serial plotter (Tools > Serial Plotter menu)
  Attach the center pin of a potentiometer to pin 34 with port A1,
  and the outside pins to +3.3V and ground.
*/
#define PIN_ANALOG_PORT_1 34

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 115200 bits per second:
  Serial.begin(115200);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 34:
  int sensorValue = analogRead(PIN_ANALOG_PORT_1);
  // print out the value you read:
  Serial.println(sensorValue);
  delay(1);        // delay in between reads for stability
}
