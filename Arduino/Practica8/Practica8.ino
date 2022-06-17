//Declaramos las variables para la lectura de sensor.
int trigPin = 8;
int echoPin = 7;
long duration; 
int cm=0;

// declaramos las variables para representar la distancia.
int led1 = 6;
int led2 = 5;
int led3 = 4;
int led4 = 3;
int led5 = 2;

void setup() {
  //iniciamos el serial para saber la distancia del sensor
  Serial.begin ( 9600 );
  //colocamos los pins
  pinMode ( trigPin, OUTPUT );
  pinMode ( echoPin, INPUT  );
  pinMode ( led1,  OUTPUT );
  pinMode ( led2,  OUTPUT );
  pinMode ( led3,  OUTPUT );
  pinMode ( led4, OUTPUT );
  pinMode ( led5, OUTPUT );
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
//calculamos la distancia
duration = pulseIn(echoPin, HIGH);

duration=duration/2;

cm = duration/ 29;
Serial.print("Distancia:");
Serial.println(cm);
delay(100);
//encendemos los leds deacuerdo a la distancia que nos pide la practica
if ( cm > 20 ) {
  digitalWrite ( led1, LOW ); 
  digitalWrite ( led2, LOW ); 
  digitalWrite ( led3, LOW );
  digitalWrite ( led4, LOW ); 
  digitalWrite ( led5, LOW ); 
}else if ( cm >= 16  ) {
  prenderLed ( led1 ); 
  } else if ( cm >= 12 ){
    prenderLed ( led1 );
    prenderLed ( led2 );
  } else if ( cm >= 8 ) {
    prenderLed ( led1 );
    prenderLed ( led2 );
    prenderLed ( led3 ); 
  } else if ( cm >= 4 ) {
    prenderLed ( led1 );
    prenderLed ( led2 );
    prenderLed ( led3 );
    prenderLed ( led4 );
  } else if ( cm >= 0 ) {
    prenderLed ( led1 );
    prenderLed ( led2 );
    prenderLed ( led3 );
    prenderLed ( led4 );
    prenderLed ( led5 );
  }
}
//metodo prender led
void prenderLed ( int valor ) {
  digitalWrite ( valor, HIGH );
  delay ( 100 );
  digitalWrite ( valor, LOW ); 
}
