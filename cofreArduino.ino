int luzinha = 9;
int potenciometro = A0;
int senha = 4;
int valorEscolhido;
int estadoBotao;
int statusLuz = 0;
int valorP = 0;
int botao = 12;
int buzina = 11;

void setup() {
  pinMode(luzinha, OUTPUT);
  pinMode(potenciometro, INPUT);
  pinMode(botao, INPUT);
  pinMode(buzina, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  estadoBotao = digitalRead(botao);
  valorP = analogRead(potenciometro);
  valorP = map(valorP, 0, 1023, 0, 255);
  if (valorP <= 51){
    valorEscolhido = 0;
    compararResultado();
  }
  if (valorP > 51 && valorP <= 102){
    valorEscolhido = 1;
    compararResultado();
  }
  if (valorP > 102 && valorP <= 153){
    valorEscolhido = 2;
    compararResultado();
  }
  if (valorP > 153 && valorP <= 204){
    valorEscolhido = 3;
    compararResultado();
  }
  if (valorP > 204 && valorP <= 255){
    valorEscolhido = 4;
    compararResultado();
  }
  Serial.println(valorEscolhido);
  if (valorEscolhido != senha){
    digitalWrite(luzinha, LOW);
    statusLuz = 0;
  }
}

void compararResultado(){
  if(estadoBotao == HIGH){
    if (valorEscolhido == senha){
      if(statusLuz == 0){
        digitalWrite(luzinha, HIGH);
        statusLuz = 1;
      }
    }
    else{
      digitalWrite(luzinha, LOW);
      statusLuz = 0;
      digitalWrite(buzina, HIGH);
      delay(100);
      digitalWrite(buzina, LOW);
    }
  }
}
