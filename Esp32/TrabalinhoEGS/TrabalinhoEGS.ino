#include <ArduinoJson.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <PubSubClient.h>
long lastMsg = 0;


#define QTD 25


int sensor[QTD]; 


// -------- seu wifi -----------
const  char * ssid =  "REDE_WIFI";
const  char * password =  "SENHA_WIFI";


#define ORG "zyrp8o"
#define DEVICE_TYPE "ESP32device"
#define DEVICE_ID "001"
#define TOKEN "12031203"



// -------- informações do Bluemix para criar a mensagem MQTT --- ----

char server[] = ORG ".messaging.internetofthings.ibmcloud.com";
char pubTopic[] = "iot-2/evt/status/fmt/json";
char authMethod[] = "use-token-auth";
char token[] = TOKEN;
char clientId[] = "d:" ORG ":" DEVICE_TYPE ":" DEVICE_ID;


WiFiClient wifiClient;
PubSubClient client(server, 1883, NULL, wifiClient);




void Envia_por_request ()
{
  long now = millis();
  //  if (now - lastMsg > 1000) {
  lastMsg = now;


  String payload = "{\"Barco\":{";

  for(int i = 0; i<QTD; i++){
    payload += "\"S";
    payload += i;
    payload += "\":";
    payload += random(2, 19);
    if(i != (QTD-1)){
      payload += ",";
    }
    
  }
  payload += "}}";

 

  if (client.publish(pubTopic, payload.c_str())) {
    Serial.println("Publish ok");
    Serial.println(payload);
    Serial.println(payload.c_str());
  }
  else {
    Serial.println("Publish failed");
    client.disconnect();
    Serial.print("Reconnecting client to ");
    Serial.println(server);
    while (!client.connect(clientId, authMethod, token)) {
      Serial.print(".");
      delay(500);
    }

  }
  // }
}



//---------------------------------------------------------------------------------------------



void setup() {

  for(int i = 0; i<QTD; i++){
    sensor[i] = 0;
  }

  Serial.begin(115200);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.print(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");

  Serial.print("WiFi connected, IP address: ");
  Serial.println(WiFi.localIP());

  if (!client.connected()) {
    Serial.print("Reconnecting client to ");
    Serial.println(server);
    while (!client.connect(clientId, authMethod, token)) {
      Serial.print(".");
      delay(1000);
    }

    //inscrve nos topicos
    Serial.println("Bluemix connected");
    Envia_por_request ();
  }
}



void loop() {
  Envia_por_request ();
  client.loop();
  delay(250);
}
