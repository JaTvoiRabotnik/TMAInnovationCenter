//Libraries
#include "DHT.h"

//Constants
#define DHTPIN 22 // what pin we're connected to
#define DHTTYPE DHT11 // DHT 11 

DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino
//Variables
int chk;
float hum; //Stores humidity value
float temp; //Stores temperature value

void setup()
{Serial.begin(9600);
  dht.begin();
}
void loop()
{
  //Read data and store it to variables hum and temp
  hum = dht.readHumidity();
  temp= dht.readTemperature();
  //Print temp and humidity values to serial monitor
  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.print(" %, Temp: ");
  Serial.print(temp);
  Serial.println(" Celsius");
  delay(2000); //Delay 2 sec.
}
