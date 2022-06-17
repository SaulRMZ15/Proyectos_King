int valorInicial;

int leds [] = { 12, 11, 10, 9, 8, 7, 6, 5 };
    
void setup() {
  // put your setup code here, to run once:
  pinMode ( leds[1], OUTPUT );
  pinMode ( leds[2], OUTPUT );
  pinMode ( leds[3], OUTPUT );
  pinMode ( leds[4], OUTPUT );
  pinMode ( leds[5], OUTPUT );
  pinMode ( leds[6], OUTPUT );
  pinMode ( leds[7], OUTPUT );
  pinMode ( leds[8], OUTPUT );
  
  Serial.begin ( 9600 );
}

void loop() {
  // put your main code here, to run repeatedly:
  if ( Serial.available() > 0 ) {
    valorInicial = Serial.readString().toInt();
    Serial.print( "Valor inicial: " );
    Serial.println( valorInicial, DEC );
  }
  
  prenderLedsDerIzq( leds, valorInicial);
  prenderLedsIzqDer( leds, valorInicial);
}

//Metodos para la secuencia, con valor de veces que se repite la seceuncia
void prenderLedsDerIzq ( int veces, int ledValor[], int posicion ) {
  for ( int i = 0; i < veces; i++ ) {
     for ( int j = posicion; j < 8; j++ ) { 
      digitalWrite ( ledValor [ j ], HIGH );
      delay ( 100 );
      digitalWrite ( ledValor [ j ], LOW );
    }
  }
}

void prenderLedsIzqDer ( int veces, int ledValor[] , int posicion ) {
  for ( int i = veces; i >= 0; i-- ) {
    for ( int j = posicion; j >= 0; j-- ) { 
      digitalWrite ( ledValor [ j ], HIGH );
      delay ( 100 );
      digitalWrite ( ledValor [ j ], LOW );
    }
  }
}

//Sobrecarga del metodo con solo el valor del puerto serial.
void prenderLedsDerIzq ( int ledValor[], int valor ) {
  for ( int i = 0; i < valor; i++ ) {
     for ( int j = valor; j < 8; j++ ) { 
      digitalWrite ( ledValor [ j ], HIGH );
      delay ( 700 );
      digitalWrite ( ledValor [ j ], LOW );
    }
  }
}

void prenderLedsIzqDer ( int ledValor[] , int valor ) {
  for ( int i = valor; i >= 0; i-- ) {
    for ( int j = valor; j >= 0; j-- ) { 
      digitalWrite ( ledValor [ j ], HIGH );
      delay ( 700 );
      digitalWrite ( ledValor [ j ], LOW );
    }
  }
}
