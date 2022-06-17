const int pinRELE = 7;

void setup(){
  Serial.begin(9600);
  pinMode(pinRELE, OUTPUT); 
}

void on_Off(char x){
  switch(x){
    case 'n': // rele off
      digitalWrite(pinRELE, HIGH);
      break;
    case 'o': // rele on
      digitalWrite(pinRELE, LOW);
      break;
  }
}

void loop(){
  //si existe información pendiente
  if (Serial.available()>0){
    //leeemos la opcion
    char dato = Serial.read();
    on_Off(dato);
  }
}
