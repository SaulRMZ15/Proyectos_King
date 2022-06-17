#include <Servo.h>

Servo myservo;

int pin0 = 7, pin30 = 6, pin60 = 5, pin90 = 4;

void setup(){
  myservo.attach(8);
  pinMode(pin0, OUTPUT);
  pinMode(pin30, OUTPUT);
  pinMode(pin60, OUTPUT);
  pinMode(pin90, OUTPUT);
}

void loop(){
  servo0_90();
  delay(500);
  servo90_0 ();
}

void servo0_90 () {
  int i;
  for( i = 0; i < 91; i++){
    if ( i <= 90 ) {
      myservo.write( i );
      delay(10);
    }
    
    if( i == 0 ) {
      digitalWrite ( pin0, HIGH );
      delay(1000);
      digitalWrite ( pin0, LOW );
    } else if ( i == 30 ) {
        digitalWrite ( pin30, HIGH );
        delay(1000);
        digitalWrite ( pin30, LOW );
    } else if ( i == 60 ) {
        digitalWrite ( pin60, HIGH );
        delay(1000);
        digitalWrite ( pin60, LOW );
    } else if ( i == 90 ) {
        digitalWrite ( pin90, HIGH );
        delay(1000);
        digitalWrite ( pin90, LOW );
    }
  }
}

void servo90_0 () {
  for( int i = 91; i >= 0; i--){
    if ( i <= 90 ) {
      myservo.write( i );
      delay(10);
    }
    
    if( i == 90 ) {
      digitalWrite ( pin90, HIGH );
      delay(50);
      digitalWrite ( pin90, LOW );
    } else if ( i == 60 ) {
        digitalWrite ( pin60, HIGH );
        delay(50);
        digitalWrite ( pin60, LOW );
    } else if ( i == 30 ) {
        digitalWrite ( pin30, HIGH );
        delay(50);
        digitalWrite ( pin30, LOW );
    } else if ( i == 0 ) {
        digitalWrite ( pin0, HIGH );
        delay(50);
        digitalWrite ( pin0, LOW );
    }
  }  
}
