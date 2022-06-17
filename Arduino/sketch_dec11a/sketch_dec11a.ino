int rojo = 9;       
int amarillo = 8;     
int verde = 7;      
int p_rojo = 10;    
int p_verde = 11;   
int PIR1 = 6;     
int PIR2 = 5;     
int Buzzer = 3;     

void setup() {
  pinMode(rojo, OUTPUT);
  pinMode(amarillo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(p_rojo, OUTPUT);
  pinMode(p_verde, OUTPUT);
  pinMode(PIR1, INPUT);
  pinMode(PIR2, INPUT); 
  pinMode(Buzzer, OUTPUT);
}

void loop() {
// Variables que usar en los ciclos  
  int i, j;   
// Si se detecta la presencia de un peatón en alguno de los lados
  if ((digitalRead(PIR1)) || (digitalRead(PIR2))) { 
// Se avisa de la presencia de peatones con un cambio de color del semáforo
    digitalWrite(verde, LOW);   
// Se cambian los semáforos de verde
    digitalWrite(amarillo, HIGH); 
// a amarillo,
    delay(10000);
// que se mantendrá durante 10 segundos.

// Se permite el paso de los peatones
    digitalWrite(amarillo, LOW);            
// Se cambian los semáforos de amarillo
    digitalWrite(rojo, HIGH);               
// a verde.
    digitalWrite(p_rojo, LOW);
    digitalWrite(p_verde, HIGH);
                            
// Se inicia una señal sonora con un ritmo que indique el tiempo restante.
    for (i=1;i<11;i++) {
      for (j=1;j<5;j++) {
       digitalWrite(Buzzer, HIGH);
       delay(2000/i);
       digitalWrite(Buzzer, LOW);
       delay(2000/i);
      }  
    }
                                  
// Se vuelve a permitir la circulación de vehículos
  digitalWrite(rojo, LOW);                  
// Se apaga la luz roja
  digitalWrite(verde, HIGH);                
// y se enciende la luz verde
  digitalWrite(p_rojo, HIGH);
  digitalWrite(p_verde, LOW);
  delay(60000);                             
// Se espera al menos 1 minutos a volver a habilitar el paso de peatones
  }   
// Se permite la circulación de vehículos
  digitalWrite(rojo, LOW);                
// Se apaga la luz roja
  digitalWrite(verde, HIGH);                
// y se enciende la luz verde para vehículos
  digitalWrite(p_rojo, HIGH);               
// Al revés para peatones
  digitalWrite(p_verde, LOW);
}
