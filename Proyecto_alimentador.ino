#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>
#include <WiFi.h>


// Credenciales de acceso a tu red WiFi
const char* ssid = "FRANCY";
const char* password = "Juanfra2330";

// Configura los parametros de tu bot de Telegram
#define BOTtoken "6092578415:AAHFwK96yZM5kMep7RR2obJJtwQS7Xp2MlE"  // your Bot Token (Get from Botfather)

WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

const int buttonPin = 4;
int buttonState = 0;

void setup() {
  Serial.begin(115200);
  pinMode(buttonPin, INPUT);
  client.setTrustAnchors(&cert); // Add root certificate for api.telegram.org

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("");
  Serial.println("WiFi conectado");

  // El bot mandará un mensaje cuando esté listo para usarse
  bot.sendMessage(BOT_ID, "Bot preparado", "");
}

void loop() {
  buttonState = digitalRead(buttonPin);

  // Cuando se pulsa el botón, se le pide al bot que mande un mensaje diciendo "Boton presionado"
  if (buttonState == HIGH) {
    bot.sendMessage(BOT_ID, "Boton presionado", "");
    delay(300);
  } else {
    // No hace nada si no se pulsa el botón
  }
}
