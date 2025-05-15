# Armazenamento de Dados em Banco SQL com Python

## Descrição do Projeto

Nesta segunda etapa do projeto de Irrigação Inteligente da FarmTech Solutions, desenvolvemos um script em Python para simular o armazenamento dos dados coletados pelo ESP32 em um banco de dados SQL Oracle.

O objetivo é registrar manualmente os dados do monitor serial do ESP32 em uma tabela que representa as leituras dos sensores agrícolas simulados, além de implementar as operações básicas de CRUD (Create, Read, Update e Delete).

## Metas da Entrega

- Capturar dados simulados dos sensores (fósforo, potássio, pH, umidade e status da irrigação);
- Criar uma tabela SQL para armazenar essas informações, caso ainda não exista;
- Desenvolver um script Python para realizar as operações CRUD na tabela;
- Justificar a escolha da estrutura de dados em relação ao Modelo Entidade-Relacionamento (MER) definido na Fase 2.

## Estrutura da Tabela SQL

A tabela `sensores_irrigacao` possui os seguintes campos:

| Coluna           | Tipo               | Descrição                             |
|------------------|--------------------|-------------------------------------|
| id               | NUMBER (PK)        | Identificador único (auto-increment)|
| fosforo_presente  | NUMBER(1)          | Indica presença (1) ou ausência (0) de fósforo no solo |
| potassio_presente | NUMBER(1)          | Indica presença (1) ou ausência (0) de potássio no solo |
| ph_simulado      | NUMBER(5,2)         | Valor analógico simulado do pH (0 a 14) |
| umidade          | NUMBER(5,2)         | Umidade do solo (%) medida pelo DHT22 |
| irrigacao_ativa  | NUMBER(1)           | Status da irrigação (1 = ligada, 0 = desligada) |
| data_insercao    | TIMESTAMP           | Data e hora da inserção do registro |

## Justificativa da Estrutura e Relacionamento com o MER

A tabela foi criada para refletir as entidades e atributos mapeados no Modelo Entidade-Relacionamento da fase anterior. Cada linha da tabela representa uma leitura integrada dos sensores e o estado da irrigação em um momento específico.

A escolha de um modelo tabular relacional com campos bem definidos para cada atributo facilita consultas, atualizações e manutenção da integridade dos dados.

## Funcionalidades do Script Python

O script implementa as seguintes operações via menu interativo:

1. **Inserir novo dado (manual):** Permite inserir registros simulando dados coletados do monitor serial do ESP32.
2. **Consultar dados:** Exibe todos os registros ordenados pela data de inserção.
3. **Atualizar umidade:** Permite atualizar o valor da umidade para um registro específico.
4. **Deletar registro:** Remove um registro pelo seu ID.
5. **Exportar dados para CSV:** Exporta os dados atuais da tabela para um arquivo `dados_irrigacao.csv`.
6. **Sair:** Encerra o programa.

## Como executar

1. Configure os parâmetros de conexão com o banco Oracle no início do script.
2. Execute o script em um ambiente Python com a biblioteca `oracledb` instalada.
3. Use o menu para inserir e manipular dados conforme necessário.

## Exemplo de uso

```plaintext
--- SISTEMA DE IRRIGAÇÃO INTELIGENTE ---
1. Inserir novo dado (manual)
2. Consultar dados
3. Atualizar umidade
4. Deletar registro
5. Exportar dados para CSV
6. Sair
Escolha uma opção: 1

Fósforo presente (1 = Sim, 0 = Não): 1
Potássio presente (1 = Sim, 0 = Não): 0
pH simulado (0 a 14): 6.5
Umidade (%): 45.0
Irrigação ativa (1 = Sim, 0 = Não): 1
✅ Dados inseridos com sucesso.
