int Trigger=2;
int Echo=3;
int alarma=4;
int t,d;

void setup() {
 Serial.begin(9600); 
 pinMode(Trigger,OUTPUT); 
 pinMode(Echo,INPUT);
 pinMode(alarma,OUTPUT);
 digitalWrite(Trigger,LOW);
}

void loop() {
 delay(1000);
 digitalWrite(Trigger, HIGH);
 delayMicroseconds(10);
 digitalWrite(Trigger,LOW);
 t = pulseIn(Echo,HIGH); //es el tiempo que tarda el eco del ultrasónico  
 d = 0.01715*t; // Agregamos la formula
//Agregamos un IF para validar, si se detecta algo o alguien a una distancia menor a 100cm encendemos la alarma.
 if (d < 100 && d > 91){
   tone(alarma, 800);
   delay(200);
   noTone(alarma);
 } else if(d < 90 && d > 81) {
   tone(alarma, 800);
   delay(180);
   noTone(alarma);
 } else if(d < 80 && d > 71) {
   tone(alarma, 800);
   delay(160);
   noTone(alarma);
 } else if(d < 70 && d > 61) {
   tone(alarma, 800);
   delay(140);
   noTone(alarma);
 } else if(d < 60 && d > 51) {
   tone(alarma, 800);
   delay(120);
   noTone(alarma);
 } else if(d < 50 && d > 41) {
   tone(alarma, 800);
   delay(100);
   noTone(alarma);
 } else if(d < 40 && d > 31) {
   tone(alarma, 800);
   delay(80);
   noTone(alarma);
 } else if(d < 30 && d > 21) {
   tone(alarma, 800);
   delay(60);
   noTone(alarma);
 } else if (d < 20 && d > 11){
   tone(alarma, 800);
   delay(40);
   noTone(alarma);
 } else if(d < 10 && d > 1) {
   tone(alarma,800);
   delay(20);
   noTone(alarma);
 }
  //Mostramos en el monitor  la distancia que esta midiendo el sensor.
 Serial.print ("Distancia: ");
 Serial.print (d);
 Serial.print ("cm");
 Serial.println("");
 delay (100);
}
