#include <SoftwareSerial.h>  // libreria que permite establecer pines digitales
        // para comunicacion serie

SoftwareSerial mBT(10, 11);  // pin 10 como RX, pin 11 como TX

const int EchoPin = 8;
const int TriggerPin = 9;
 
void setup() {
   Serial.begin(9600);
   pinMode(TriggerPin, OUTPUT);
   pinMode(EchoPin, INPUT);
   mBT.begin(9600);
}
 
void loop() {
  //si existe información pendiente
  int cm = _tiempo(TriggerPin, EchoPin);
  if(cm != 20){
    mBT.println("Deteccion de movimiento");
  }
  Serial.print("Distancia: ");
  Serial.println(cm);
  delay(1000);
}
 
int _tiempo(int TriggerPin, int EchoPin) {
   long duration, distanceCm;
   
   digitalWrite(TriggerPin, LOW);  //para generar un pulso limpio ponemos a LOW 4us
   delayMicroseconds(4);
   digitalWrite(TriggerPin, HIGH);  //generamos Trigger (disparo) de 10us
   delayMicroseconds(10);
   digitalWrite(TriggerPin, LOW);
   
   duration = pulseIn(EchoPin, HIGH);  //medimos el tiempo entre pulsos, en microsegundos
   
   distanceCm = duration * 10 / 292/ 2;   //convertimos a distancia, en cm
   return distanceCm;
}
