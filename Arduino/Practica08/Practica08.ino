#include <LiquidCrystal.h>

#define echoPin 8 // Echo Pin
#define trigPin 9 // Trigger Pin
#define VELOCIDAD 400 // velocidad a la que se mueve el texto

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int maximumRange = 200; // Rango maximo (variable de tipo entero)
int minimumRange = 0; // Rango minimo (variable de tipo entero)
float duration, distance; // duracion y distancia (variable tipo long)
String texto = "La distancia del objeto es: ";
String textocm = " cm";

void setup() {
 lcd.begin(16, 2);
 Serial.begin (9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
}

void loop() {
  
 digitalWrite(trigPin, LOW);
 delayMicroseconds(2); 

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
  
 //Calculamos la distancia (cm.mm) en base a la velocidad del sonido.
 distance = float (duration*0.017);
 
  int tam = (texto.length()) + (textocm.length()) + 5;
  
  String texto_a_mostrar = texto + distance + textocm;
  
  // Mostramos entrada texto por la izquierda
  for(int i=tam; i>0 ; i--)
  {
    String texto1 = texto_a_mostrar.substring(i-1);
    
 
    // Limpiamos pantalla
    lcd.clear();
 
    //Situamos el cursor
    lcd.setCursor(0, 0);
 
    // Escribimos el texto
    lcd.print(texto1);
 
    // Esperamos
    delay(VELOCIDAD);
  }
 
  // Desplazamos el texto hacia la derecha
  for(int i=1; i<=16;i++)
  {
    // Limpiamos pantalla
    lcd.clear();
 
    //Situamos el cursor
    lcd.setCursor(i, 0);
 
    // Escribimos el texto
    lcd.print(texto_a_mostrar);
 
    // Esperamos
    delay(VELOCIDAD);
  }
 
  // Desplazamos el texto hacia la izquierda en la segunda fila
  for(int i=16;i>=1;i--)
  {
    // Limpiamos pantalla
    lcd.clear();
 
    //Situamos el cursor
    lcd.setCursor(i, 1);
 
    // Escribimos el texto
    lcd.print(texto_a_mostrar);
 
    // Esperamos
    delay(VELOCIDAD);
  }
 
  // Mostramos salida del texto por la izquierda
  for(int i=1; i<=16; i++)
  {
    String texto1 = texto_a_mostrar.substring(i-1);
 
    // Limpiamos pantalla
    lcd.clear();
 
    //Situamos el cursor
    lcd.setCursor(0, 1);
 
    // Escribimos el texto
    lcd.print(texto1);
 
    // Esperamos
    delay(VELOCIDAD);
  }
 
} 
