
#include <DHT.h>

// === DEFINIÇÕES DE PINOS ===
#define BUTTON_K_PIN 4     // Potássio (K)
#define BUTTON_P_PIN 15    // Fósforo (P)
#define LDR_PIN 34         // Sensor de pH (LDR)
#define DHT_PIN 16         // Sensor DHT22 (umidade)
#define RELAY_PIN 17       // Relé (bomba de irrigação)

#define DHTTYPE DHT22
DHT dht(DHT_PIN, DHTTYPE);

// === CONFIGURAÇÃO INICIAL ===
void setup() {
  Serial.begin(115200);

  pinMode(BUTTON_K_PIN, INPUT_PULLUP);
  pinMode(BUTTON_P_PIN, INPUT_PULLUP);
  pinMode(RELAY_PIN, OUTPUT);

  dht.begin();

  Serial.println("Sistema de Irrigação Inteligente - FarmTech Solutions");
}

// === FUNÇÃO PRINCIPAL ===
void loop() {
  // === Leitura dos botões ===
  bool potassioPresente = digitalRead(BUTTON_K_PIN) == LOW;
  bool fosforoPresente = digitalRead(BUTTON_P_PIN) == LOW;

  // === Leitura do pH (simulado com LDR) ===
  int ldrValue = analogRead(LDR_PIN);
  float phSimulado = ((float)ldrValue / 4095.0) * 14.0; // pH simulado com decimal

  // === Leitura da umidade (DHT22) ===
  float umidade = dht.readHumidity();

  // Verificação de falha na leitura do DHT22
  if (isnan(umidade)) {
    Serial.println("Erro ao ler DHT22!");
    umidade = -1;
  }

  // === Lógica de irrigação ===
  bool ligarIrrigacao = false;

  if (umidade >= 0 && umidade < 50) {  // exemplo: umidade abaixo de 50% liga irrigação
    ligarIrrigacao = true;
  }

  digitalWrite(RELAY_PIN, ligarIrrigacao ? HIGH : LOW); // HIGH aciona relé

  // === Impressão no monitor serial ===
  Serial.println("=====================================");
  Serial.print("Potássio presente: "); Serial.println(potassioPresente ? "Sim" : "Não");
  Serial.print("Fósforo presente: "); Serial.println(fosforoPresente ? "Sim" : "Não");
  Serial.print("pH (simulado): "); Serial.println(phSimulado, 2);
  Serial.print("Umidade do solo: "); Serial.print(umidade); Serial.println(" %");
  Serial.print("Irrigação ativa: "); Serial.println(ligarIrrigacao ? "SIM" : "NÃO");
  Serial.println("=====================================
");

  delay(2000); // Espera 2 segundos antes de repetir
}
