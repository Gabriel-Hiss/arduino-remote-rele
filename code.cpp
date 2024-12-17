#include <UIPEthernet.h>  // Biblioteca ENC28J60

// Configuração de rede
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };  // Endereço MAC
IPAddress ip(192, 168, 1, 177);                      // IP do Arduino (ajuste conforme sua rede)

EthernetServer server(80);  // Porta do servidor web

const int relayPin = 7;  // Pino do relé
bool relayState = false;

void setup() {
  Ethernet.begin(mac, ip);  // Inicializa a rede com IP estático
  server.begin();           // Inicia o servidor
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH);  // Relé desligado no início
  Serial.begin(9600);
  Serial.println("Servidor iniciado...");
}

void loop() {
  EthernetClient client = server.available();  // Aguarda conexão de um cliente
  if (client) {
    String request = "";
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        request += c;

        // Requisição HTTP concluída
        if (c == '\n') {
          if (request.indexOf("GET /RELAY=ON") >= 0) {
            // Ativa o relé por 30 segundos
            relayState = true;
            digitalWrite(relayPin, LOW);
            delay(30000);
            digitalWrite(relayPin, HIGH);
            relayState = false;

            // Redireciona de volta para a página principal
            client.println("HTTP/1.1 303 See Other");
            client.println("Location: /");
            client.println("Content-Type: text/html; charset=utf-8");
            client.println();
            break;
          }

          // Resposta HTML (Página Principal)
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html; charset=utf-8");
          client.println();
          client.println("<html>");
          client.println("<head><meta charset='utf-8'><title>Controle de Relé</title></head>");
          client.println("<body>");
          client.println("<h1>Controle de Relé</h1>");
          client.println("<p>Relé: " + String(relayState ? "Ligado" : "Desligado") + "</p>");
          client.println("<a href='/RELAY=ON'><button>Ativar Relé</button></a>");
          client.println("</body>");
          client.println("</html>");
          break;
        }
      }
    }
    delay(1);
    client.stop();  // Finaliza a conexão com o cliente
  }
}
