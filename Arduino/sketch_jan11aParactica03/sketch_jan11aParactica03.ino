#include <ESP8266WiFi.h>
const char* ssid = "Ubee60F0-2.4G";
const char* password = "B5D7F860F0";
WiFiServer server(80);

#define PIN_TRIG D5
#define PIN_ECHO D6

float tiempo;
float distancia;

void setup() {
   Serial.begin(115200);
   pinMode(PIN_TRIG, OUTPUT);
   pinMode(PIN_ECHO, INPUT);
   Serial.println(ssid);WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  // Iniciando el server
  server.begin();
  Serial.println("Server started");
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
}

void loop() {

   digitalWrite(PIN_TRIG, LOW);  //para generar un pulso limpio ponemos a LOW 4us
   delayMicroseconds(4);
   
   digitalWrite(PIN_TRIG, HIGH);  //generamos Trigger (disparo) de 10us
   delayMicroseconds(10);
   digitalWrite(PIN_TRIG, LOW);
   
   tiempo = pulseIn(PIN_ECHO, HIGH);
   distancia = tiempo/58.3;

   Serial.println(distancia);

  WiFiClient client = server.available();
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.print("Distancia del objeto: " );
  client.print(distancia);
  client.println("</html>");

   delay(1000);
}
