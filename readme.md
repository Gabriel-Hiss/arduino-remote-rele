# pt-br
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

# en-us

# Project: Ethernet ENC28J60 and Relay Connections

## 📋 Connection Table

### Ethernet ENC28J60 Module

📝 **Description**  
- **Ethernet ENC28J60 Module**: Used for communication via Ethernet network with dynamic IP (DHCP) or static IP.  
- **Relay Module**: Controls electronic devices using a digital signal. In this project, we use 1 relay for timed activation (30 seconds).

---

### Ethernet ENC28J60 Module Connections

| **ENC28J60 Pin**   | **Arduino UNO Pin** | **Description**              |
|---------------------|---------------------|------------------------------|
| **VCC**            | 3.3V               | Power supply (3.3V)          |
| **GND**            | GND                | Ground                       |
| **CS**             | D10                | Chip Select (SPI)            |
| **SI (MOSI)**      | D11                | Master → Slave Data          |
| **SO (MISO)**      | D12                | Slave → Master Data          |
| **SCK**            | D13                | SPI Clock                    |
| **RST**            | RESET              | Ethernet module reset        |

---

### Relay Module (2 Channels) Connections

| **Relay Pin**      | **Arduino UNO Pin** | **Description**              |
|---------------------|---------------------|------------------------------|
| **VCC**            | 5V                 | Relay power supply           |
| **GND**            | GND                | Ground                       |
| **IN1**            | D7                 | Relay 1 control              |
| **IN2**            | Not used           | Relay 2 control (optional)   |

---

## ⚙️ Operation

The Ethernet connection allows access to the web server hosted on the Arduino.  
The HTML page includes a button that activates the relay.  
The relay stays active for **10 seconds** and then automatically turns off.
