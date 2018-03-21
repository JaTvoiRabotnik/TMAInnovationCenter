#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>


const char* ssid     = "TIC";
const char* password = "T1cVi3tn@m";

const char* mqttServer = "broker.getblocky.com";
const int mqttPort = 1883;
const char* mqttUser = "chipId";
const char* mqttPassword = "ByGjpuqh-";

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(10);

  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  client.setServer(mqttServer, mqttPort);

  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");

    if (client.connect("ESP32Client", mqttUser, mqttPassword )) {

      Serial.println("connected");

    } else {

      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);

    }
  }

}

void loop() {
  client.loop();
  // Collect Sensor data
  int h = random(10, 100); //dht.readHumidity();
  // Read temperature as Celsius (the default)
  int t = random(20, 40); //dht.readTemperature();

  if (h < 100) {
    Serial.print("Temp: "); Serial.println(t);
    Serial.print("Hum: "); Serial.println(h);
    char msg[20];
    sprintf(msg, "%d", t);
    client.publish("ByGjpuqh-/user/temp", msg);
    sprintf(msg, "%d", h);
    client.publish("ByGjpuqh-/user/hum", msg);
    delay(2000);
  }

}
