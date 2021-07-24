#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
MDNSResponder mdns;
ESP8266WebServer server(80);
WiFiClient client;


void thingSpeakUpload() {
  float hodnoty[2] = { teplota_0, teplota_1 };
  String server = API_THINGSPEAK;
  String zprava = THINGSPEAK_KEY;

  if (client.connect(server,80)) {
    Serial.println("\nThingSpeak Upload...\n--------------------");
    for (byte i = 0; i <= 1; i++) {
      zprava += "&field" + String(i + 1) + "=" + String(hodnoty[i], 1);
    }
    Serial.println(server + "/update?api_key=" + zprava);
    zprava += "\r\n\r\n";
    client.print("POST /update HTTP/1.1\n");
    client.print("Host: api.thingspeak.com\n");
    client.print("Connection: close\n");
    client.print("X-THINGSPEAKAPIKEY: " + THINGSPEAK_KEY + "\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: ");
    client.print(zprava.length());
    client.print("\n\n");
    client.print(zprava);
    }
    // ukončení spojení se serverem Thingspeak
    client.stop();
  }

void handleRoot()
{
  String t0 = String(teplota_0, 1);
  String t1 = String(teplota_1, 1);
  
  char temp[1000];
  int sec = millis() / 1000;
  int min = sec / 60;
  int hr = min / 60;
  uint8 index = t0.indexOf('.');
  int restOUT = t0.substring(index+1).toInt();
  int temperatureOUT = t0.toInt();
  index = t1.indexOf('.');
  int restIN = t1.substring(index + 1).toInt();
  int temperatureIN = t1.toInt();

  // konverze typu String do char[] kvůli použití ve funkci snprintf() níže
  char thermo_0[THERMO_0.length() + 1];
  char thermo_1[THERMO_1.length() + 1];
  strcpy(thermo_0, THERMO_0.c_str());
  strcpy(thermo_1, THERMO_1.c_str());


  snprintf(temp, 1000,

   "<!DOCTYPE html>\
    <html lang='cs'>\
    <head>\
      <meta http-equiv='refresh' content='15'>\
      <meta charset='utf-8'>\
      <meta name='viewport' content='width=device-width, initial-scale=1'>\
      <title>TeleThermo</title>\
      <style>\
        body { margin: auto; text-align: center; background-color: #cccccc; font-family: Arial, Helvetica, Sans-Serif; Color: #000088; }\
        table { margin-left: auto; margin-right: auto; }\
        td { padding: 5px; }\
      </style>\
    </head>\
    <body>\
      <h1>TeleThermo</h1>\
      <p>Doba od spuštění:<br>%02d:%02d:%02d</p>\
      <table border='1' style='text-align: center;'>\
        <tr>\
          <td>Čidlo</td><td>Teplota</td>\
        </tr>\
        <tr>\
          <td>%s</td><td>%02d.%01d &deg;C</td>\
        </tr>\
        <tr>\
          <td>%s</td><td>%02d.%01d &deg;C</td>\
        </tr>\
      </table>\
    </body>\
    </html>",

hr, min % 60, sec % 60, thermo_0, temperatureOUT,restOUT, thermo_1, temperatureIN,restIN);
  server.send(200, "text/html", temp);
}

void handleNotFound() {
  String message = "Soubor nenalezen\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";

  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }

  server.send(404, "text/plain", message);
}

void handleJson()
{
  String t0 = String(teplota_0, 1);
  String t1 = String(teplota_1, 1);
  // konverze typu String do char[] kvůli použití ve funkci snprintf() níže
  char jednotky[JEDNOTKY.length() + 1];
  strcpy(jednotky, JEDNOTKY.c_str());
  
  char temp[1000];
  uint8 index = t0.indexOf('.');
  int restOUT = t0.substring(index+1).toInt();
  int temperatureOUT = t0.toInt();
  index = t1.indexOf('.');
  int restIN = t1.substring(index + 1).toInt();
  int temperatureIN = t1.toInt();


  snprintf(temp, 1000,

    "{ \"velicina\": \"teplota\", \"jednotky\": \"%s\", \"cidla\": { \"t0\": %02d.%01d, \"t1\": %02d.%01d } }",
    jednotky, temperatureOUT, restOUT, temperatureIN, restIN
  );
  
  server.send(200, "application/json", temp);
}


void inicializaceServeru() {
  if (mdns.begin(NAZEV_PRODUKTU, WiFi.localIP())) {
    Serial.println("MDNS responder spusten");
  }

  server.on("/", handleRoot);
  server.on("/inline", []() {
    server.send(200, "text/plain", "OK");
  });
  server.on("/json", handleJson);
  server.onNotFound(handleNotFound);
  server.begin();
  Serial.println("HTTP server spusten");
  
}
