// Proměnné a výchozí nastavení
#include "nastaveni.h"
float teplota_0 = TEPLOTA_NULL;
float teplota_1 = TEPLOTA_NULL;
String ipString = NAZEV_PRODUKTU;
bool status_online = false;

// Funkce displeje
#include "displej.h"
// Síťové funkce, server
#include "server.h"
IPAddress ip;
// DS18B20 (teplotní čidla)
#include "cidla.h"


void setup() {
  Serial.begin(SERIAL_BAUD);
  delay(2000);
  Serial.println("Zapnuto\n");

  inicializaceDispleje();
  ui.update();

  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_NAZEV, WIFI_HESLO);
  Serial.print("Pripojuji se k Wi-Fi: " + String(WIFI_NAZEV));
  
  // Čekání na Wi-Fi připojení
  unsigned long cas = millis();
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    if (millis() > cas + WIFI_VYCKEJ) {
      Serial.println("\nNepodarilo se pripojit - pracuji OFF-LINE!");
      break;
    }
  }
  
  if (WiFi.status() == WL_CONNECTED) {
    status_online = true;
    Serial.print("\nIP adresa: ");
    ip = WiFi.localIP();
    Serial.println(ip);
    inicializaceServeru();
  }

  sensors.begin();
  delay(750);
  
  sensors.requestTemperatures();
  teplota_0 = sensors.getTempCByIndex(0);
  teplota_1 = sensors.getTempCByIndex(1);
  if (teplota_0 == -127.0) teplota_0 = TEPLOTA_NULL;
  if (teplota_1 == -127.0) teplota_1 = TEPLOTA_NULL;
  
  Serial.println("\n" + THERMO_0 + ": " + String(teplota_0, 1) + " " + JEDNOTKY);
  Serial.println(THERMO_1 + ": " + String(teplota_1, 1) + " " + JEDNOTKY);

}


void loop() {
  int remainingTimeBudget = ui.update();

  if (remainingTimeBudget > 0) {
    // You can do some work here
    // Don't do stuff if you are below your time budget.

    if ((millis() % CETNOST_MERENI) < 100) {
      sensors.requestTemperatures();
      teplota_0 = sensors.getTempCByIndex(0);
      teplota_1 = sensors.getTempCByIndex(1);
      if (teplota_0 == -127.0) teplota_0 = TEPLOTA_NULL;
      if (teplota_1 == -127.0) teplota_1 = TEPLOTA_NULL;
  
      Serial.println("\n" + THERMO_0 + ": " + String(teplota_0, 1) + " " + JEDNOTKY);
      Serial.println(THERMO_1 + ": " + String(teplota_1, 1) + " " + JEDNOTKY);
    }

    if (status_online) {
    
      if ((millis() % CETNOST_UPLOAD) < 100) {
        thingSpeakUpload();
      }
      
      ip = WiFi.localIP();
      ipString = \
            String(ip[0]) + "." \
          + String(ip[1]) + "." \
          + String(ip[2]) + "." \
          + String(ip[3]);
      
      mdns.update();
      server.handleClient();
      
      delay(remainingTimeBudget);
    }
  }
  
}
