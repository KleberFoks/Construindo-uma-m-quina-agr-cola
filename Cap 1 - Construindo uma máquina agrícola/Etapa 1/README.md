# Sistema de Sensores e Controle com ESP32

## Descrição do Projeto

Este projeto simula um sistema de irrigação inteligente usando um microcontrolador ESP32, sensores agrícolas simulados e um relé para controle da bomba de irrigação. A lógica do sistema é baseada nas leituras dos sensores, acionando a irrigação automaticamente conforme o nível de umidade do solo.

---

## Componentes e Simulações no Wokwi

- **ESP32**: Controlador principal do sistema.
- **Sensor de Fósforo (P)**: Simulado por um botão físico (pressionado = presença).
- **Sensor de Potássio (K)**: Simulado por um botão físico (pressionado = presença).
- **Sensor de pH**: Simulado por um LDR (Light Dependent Resistor), que retorna valores analógicos variáveis conforme a luminosidade.
- **Sensor de Umidade do Solo**: Simulado pelo sensor DHT22, que retorna valores de umidade.
- **Relé**: Controla a bomba de irrigação (acionado conforme a lógica).
- **LED embutido no relé**: Indica o status da irrigação (LED aceso = irrigação ativa).

---

## Lógica de Funcionamento

1. **Leitura dos sensores**:
   - Botões simulam a presença ou ausência de fósforo e potássio no solo.
   - LDR gera uma leitura analógica, convertida para valores entre 0 e 14, simulando o pH do solo.
   - DHT22 fornece a umidade relativa do solo.

2. **Controle da irrigação**:
   - A irrigação é ativada automaticamente se a umidade do solo estiver abaixo de 50%.
   - O relé é acionado para ligar a bomba de irrigação, e o LED do relé acende indicando o sistema ativo.
   - Caso a umidade seja igual ou maior que 50%, a irrigação permanece desligada.

3. **Feedback visual e serial**:
   - Informações dos sensores e status da irrigação são exibidas no monitor serial para acompanhamento.

---
