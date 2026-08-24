int luzinha = 9;
int potenciometro = A0;
int senha[] = {1, 2, 3, 4};
int valorEscolhido;
int estadoBotao;
int statusLuz = 0;
int valorP = 0;
int botao = 12;
int buzina = 11;

int posicaoSenha = 0;
int senhaDigitada[4];

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

  if (valorP <= 51) valorEscolhido = 0;
  else if (valorP <= 102) valorEscolhido = 1;
  else if (valorP <= 153) valorEscolhido = 2;
  else if (valorP <= 204) valorEscolhido = 3;
  else valorEscolhido = 4;

  if (estadoBotao == HIGH) {
    compararResultado();
    delay(100);
  }

  Serial.print("Selecionado: ");
  Serial.println(valorEscolhido);
  delay(300);
}

void compararResultado() {
  if (posicaoSenha < 4) {
    senhaDigitada[posicaoSenha] = valorEscolhido;
    posicaoSenha++;
    
    digitalWrite(buzina, HIGH);
    delay(50);
    digitalWrite(buzina, LOW);
  }

  if (posicaoSenha == 4) {
    bool senhaCorreta = true;

    for (int i = 0; i < 4; i++) {
      if (senhaDigitada[i] != senha[i]) {
        senhaCorreta = false;
      }
    }

    if (senhaCorreta) {
      digitalWrite(luzinha, HIGH);
      statusLuz = 1;
    } else {
      digitalWrite(luzinha, LOW);
      digitalWrite(buzina, HIGH);
      delay(1000);
      digitalWrite(buzina, LOW);
    }

    posicaoSenha = 0;
  }
}
