int microfone = 12; // Pino digital ligado ao sensor de som (DO)
int led = 8; // Pino ligado ao LED

int contPalmas = 0; // Contador de Palmas
int palmasRequeridaLigaLed = 2; // Contagem para acender o LED
int palmasRequeridaDesligaLed = 2; // Contagem para apagar o LED

// Tempo máximo entre pulsos 
unsigned long tempMaxSom = 500;
unsigned long tempMinSom = 300;
unsigned long compriSonoro = 100; // Comprimento do som esperado
unsigned long time;
unsigned long startTime = 0;

void setup() {
  Serial.begin(9600);
  pinMode(microfone, INPUT); // Inicia o pino do microfone como entrada
  pinMode(led, OUTPUT); // Inicia os pino do LED como saída
}

void loop() {
  // Inicia a contagem de tempo
  time = millis();
  // Verifica o tempo entre o pulso inicial e o seguinte
  unsigned long tempoAposPalma = time - startTime;
  
  if (tempoAposPalma >= compriSonoro && digitalRead(microfone) == HIGH) {
  
    // Verifica se o pulso recebido está entre um pulso e outro
    if (tempoAposPalma < tempMinSom || tempoAposPalma > tempMaxSom) {
  
      // Reseta intervalo e contagem do tempo
      contPalmas = 0;
      startTime = millis();
    } else {
      
      // Iniciada a contagem de pulso e o tempo (conta palma)
      contPalmas ++;
      startTime = millis();
    }

    // Verifica se a contagem de palma é >= ao número esperado e se o LED esta ligado
    if((contPalmas>=palmasRequeridaDesligaLed-1)&&(digitalRead(led)==HIGH)){
    
      // Desliga o LED e zera a contagem
      digitalWrite(led, LOW);
      Serial.println(digitalRead(led));
      contPalmas = 0;
    }
    
    // Verifica se a contagem de palma é >= ao número esperado e se o LED esta desligado
    if((contPalmas>=palmasRequeridaLigaLed-1)&&(digitalRead(led)==LOW)){
    
      // Acende o LED e zera contagem
      digitalWrite(led, HIGH);
      Serial.println(digitalRead(led));
      contPalmas = 0;
    }
  }
}
