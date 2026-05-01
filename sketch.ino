#include <WiFi.h>
#include <PubSubClient.h>

// WiFi
const char* ssid = "Wokwi-GUEST";
const char* password = "";

// MQTT
const char* mqtt_server = "test.mosquitto.org";

WiFiClient espClient;
PubSubClient client(espClient);

// Pinos
const int ldrPin = 34;
const int ledPin = 2;

// Variáveis
int valorLuz = 0;
int limite = 2000;

void setup() {
  Serial.begin(115200);

  pinMode(ledPin, OUTPUT);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi conectado");

  client.setServer(mqtt_server, 1883);
}

void reconnect() {
  while (!client.connected()) {
    if (client.connect("esp32Client")) {
      Serial.println("MQTT conectado!");
    } else {
      delay(2000);
    }
  }
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }

  client.loop();

  valorLuz = analogRead(ldrPin);

  Serial.print("Luminosidade: ");
  Serial.println(valorLuz);

  if (valorLuz < limite) {
    digitalWrite(ledPin, HIGH);
    client.publish("iluminacao/status", "Ligado");
  } else {
    digitalWrite(ledPin, LOW);
    client.publish("iluminacao/status", "Desligado");
  }

  char msg[10];
  sprintf(msg, "%d", valorLuz);
  client.publish("iluminacao/luminosidade", msg);

  delay(2000);
}
