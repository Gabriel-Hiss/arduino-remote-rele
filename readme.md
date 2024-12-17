Conexões do Projeto - Ethernet ENC28J60 e Relé
📋 Tabela de Conexões
Módulo Ethernet ENC28J60

📝 Descrição
Módulo Ethernet ENC28J60: Usado para comunicação via rede Ethernet com IP dinâmico (DHCP) ou estático.
Módulo Relé: Controla dispositivos eletrônicos com sinal digital. Neste projeto, usamos 1 relé para ativação temporizada (30 segundos).

### Módulo Ethernet ENC28J60

| **Pino ENC28J60** | **Pino Arduino UNO** | **Descrição**               |
|--------------------|----------------------|-----------------------------|
| **VCC**           | 3.3V                | Alimentação (3.3V)          |
| **GND**           | GND                 | Terra                       |
| **CS**            | D10                 | Chip Select (SPI)           |
| **SI (MOSI)**     | D11                 | Dados Mestre → Escravo      |
| **SO (MISO)**     | D12                 | Dados Escravo → Mestre      |
| **SCK**           | D13                 | Clock SPI                   |
| **RST**           | RESET               | Reset do módulo Ethernet    |

### Módulo Relé (2 Canais)

| **Pino Relé**     | **Pino Arduino UNO** | **Descrição**               |
|--------------------|----------------------|-----------------------------|
| **VCC**           | 5V                  | Alimentação do Relé         |
| **GND**           | GND                 | Terra                       |
| **IN1**           | D7                  | Controle do Relé 1          |
| **IN2**           | Não utilizado       | Controle do Relé 2 (opcional)|


⚙️ Funcionamento
A conexão Ethernet permite acessar o servidor web hospedado no Arduino.
A página HTML inclui um botão que ativa o relé.
O relé fica ativo por 10 segundos e depois é desligado automaticamente.
