#define LED_IN 27
int freq = 5000;
int ledChannel = 0;
int resolution = 8;
 
void setup() {
 
  ledcSetup(ledChannel, freq, resolution);//setup the channel, frequency and resolution we specified
  ledcAttachPin(LED_IN, ledChannel);//attach the pin to the PWM channel
  //ledcAttachPin(22, ledChannel); //un-comment this line if you LED 22 on board
 
}
 
void loop() {
   for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){
  ledcWrite(ledChannel, dutyCycle);
  delay(7);
  }
 
  for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
     ledcWrite(ledChannel, dutyCycle);
     delay(7);
  } 
}
