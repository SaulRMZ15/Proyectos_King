//Prender un motor dc con un push button
const int buttonPin = 2;
const int motorPin  = 9;
int buttonEstado     = 0;

void setup() {
  pinMode ( motorPin,OUTPUT );
  pinMode ( buttonPin,INPUT );
}

void loop() {
  buttonEstado = digitalRead( buttonPin );
  if( buttonEstado == HIGH ) {
    digitalWrite ( motorPin,HIGH );
  } else {
    digitalWrite ( motorPin,LOW );
  }
}
