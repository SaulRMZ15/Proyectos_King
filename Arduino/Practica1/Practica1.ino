
int led1 = 12, led2 = 11, led3 = 10, led4 = 9, 
    led5 =  8, led6 =  7, led7 =  6, led8 = 5;

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
  parpadeo ( 5 );
  prenderDos ( led8, led7 );
  prenderDos ( led6, led5 );
  prenderDos ( led4, led3 );
  prenderDos ( led2, led1 );
  parpadeo ( 5 );
  prenderDos ( led2, led1 );
  prenderDos ( led4, led3 );
  prenderDos ( led6, led5 );
  prenderDos ( led8, led7 );
  
}

void prenderDos ( int valor1, int valor2 ) {

  digitalWrite ( valor1, HIGH );
  digitalWrite ( valor2, HIGH );
  delay ( 300 );
  digitalWrite ( valor1, LOW );
  digitalWrite ( valor2, LOW );
}
void parpadeo ( int veces ) {
  for ( int i = 0; i < veces; i++) {
     digitalWrite ( led1, HIGH );
     digitalWrite ( led2, HIGH );
     digitalWrite ( led3, HIGH );
     digitalWrite ( led4, HIGH );
     digitalWrite ( led5, HIGH );
     digitalWrite ( led6, HIGH );
     digitalWrite ( led7, HIGH );
     digitalWrite ( led8, HIGH );
     delay ( 100 );
     digitalWrite ( led1, LOW );
     digitalWrite ( led2, LOW );
     digitalWrite ( led3, LOW );
     digitalWrite ( led4, LOW );
     digitalWrite ( led5, LOW );
     digitalWrite ( led6, LOW );
     digitalWrite ( led7, LOW );
     digitalWrite ( led8, LOW );
     delay(100);
  }
}
