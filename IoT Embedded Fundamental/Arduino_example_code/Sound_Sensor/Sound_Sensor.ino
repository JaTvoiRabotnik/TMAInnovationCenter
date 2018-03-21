int soundSensor = 4;   //Pin 4 for Sound Sensor
int LED = 13;           //Pin 13 for LED
int statusSensor = 0;
bool switchLED = false;

void setup() 
{
  pinMode (LED, OUTPUT);
}

void loop()
{
  statusSensor = analogRead (soundSensor);

  if(statusSensor > 500)
  {
    switchLED = !switchLED;
  }
  
  if (switchLED)
  {
    digitalWrite(LED, HIGH);
  }
  else
  {
    digitalWrite(LED, LOW);
  }
  delay(100);
}


