int leds [8] = { 6, 7, 8, 9, 10, 11, 12, 13 };
int led1 = 12, led2 = 11, led3 = 10, led4 = 9, led5 = 8,
    led6 = 7, led7 = 6, led8 = 5;
//int ledprendido [8];
void setup() {

  // put your setup code here, to run once:
  pinMode ( led1, OUTPUT );
  pinMode ( led2, OUTPUT );
  pinMode ( led3, OUTPUT );
  pinMode ( led4, OUTPUT );
  pinMode ( led5, OUTPUT );
  pinMode ( led6, OUTPUT );
  pinMode ( led7, OUTPUT );
  pinMode ( led8, OUTPUT );
}

void loop() {
  // put your main code here, to run repeatedly:
  prenderDos( led8, led7);
  prenderDos( led6, led5);
  prenderDos( led4, led3);
  prenderDos( led2, led1);
}

void prenderDos ( int valor1, int valor2 ) {

  digitalWrite ( valor1, HIGH );
  digitalWrite ( valor2, HIGH );
  delay ( 3000 );
  digitalWrite ( valor1, LOW );
  digitalWrite ( valor2, LOW );
}
