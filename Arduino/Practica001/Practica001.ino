#include <SoftwareSerial.h>  // libreria que permite establecer pines digitales
        // para comunicacion serie

SoftwareSerial mBT(10, 11);  // pin 10 como RX, pin 11 como TX

void setup(){
  Serial.begin(9600);   // comunicacion de monitor serial a 9600 bps
  Serial.println("Listo para conectar...");  // escribe Listo en el monitor
  mBT.begin(9600);    // comunicacion serie entre Arduino y el modulo a 38400 bps
}

void loop(){
if (mBT.available())       // si hay informacion disponible desde modulo
   Serial.write(mBT.read());   // lee Bluetooth y envia a monitor serial de Arduino

if (Serial.available())     // si hay informacion disponible desde el monitor serial
   mBT.write(Serial.read());   // lee monitor serial y envia a Bluetooth

}
