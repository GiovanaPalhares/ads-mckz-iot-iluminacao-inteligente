#include <WiFi.h>
#include <PubSubClient.h>

// WiFi (Wokwi)
const char* ssid = "Wokwi-GUEST";
const char* password = "";

// MQTT Broker público
const char* mqtt_server = "broker.hivemq.com";

WiFiClient espClient;
PubSubClient client(espClient);

// Pinos
const int ldrPin = 34;
const int ledPin = 4;

// Variáveis
int valorLuz = 0;
int limite = 2000;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);

  // WiFi
  WiFi.begin(ssid, password);
  Serial.print("Conectando ao WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi conectado!");

  // MQTT
  client.setServer(mqtt_server, 1883);
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Conectando ao MQTT...");

    String clientId = "esp32Client_";
    clientId += String(random(1000));

    if (client.connect(clientId.c_str())) {
      Serial.println("Conectado!");
    } else {
      Serial.print("Erro, rc=");
      Serial.print(client.state());
      Serial.println(" tentando novamente...");
      delay(2000);
    }
  }
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }

  client.loop();

  // Leitura do sensor
  valorLuz = analogRead(ldrPin);

  Serial.print("Luminosidade: ");
  Serial.println(valorLuz);

  // Lógica (invertida por causa do módulo)
  bool escuro = valorLuz > limite;

  if (escuro) {
    digitalWrite(ledPin, HIGH);
    client.publish("iluminacao/status", "Ligado");
  } else {
    digitalWrite(ledPin, LOW);
    client.publish("iluminacao/status", "Desligado");
  }

  // Enviar valor da luminosidade
  char msg[20];
  sprintf(msg, "%d", valorLuz);
  client.publish("iluminacao/luminosidade", msg);

  delay(2000);
}
