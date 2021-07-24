# TeleThermo

> Wi-Fi teploměr se dvěma čidly (interiér/exteriér) a OLED displejem

## Funkce
- dvě teplotní čidla s přesnostní 0,5 °C
- OLED displej s aktuální teplotou a IP adresou zařízení
- vestavěný web-server pro zobrazení aktuálních hodnot
- ukládání hodnot do cloudu na ThingSpeak

### Co zbývá vyřešit
- nelze konfigurovat Wi-Fi (SSID a heslo součástí zdrojového kódu)

## How-To

### Potřebné součástky
Množství | Název
-------- | -----
1 | NodeMCU s ESP8266
2 | čidlo Dallas DS18B20
1 | rezistor 4k7 ohm
1 | OLED displej SSD1306 (128×64 px)
1 | čidlo Dallas DS18B20
1 | breadboard (nepájivé pole)
… | kabely, zdroj napájení

### Potřebný software a knihovny
Název | Původ | Kategorie | Ověřená verze
----- | ----- | --------- | -------------
[CH340 driver](http://www.wch-ic.com/products/CH340.html) (na Windows Update) | wch.cn | ovladač | 3.5.2019.1
[Arduino IDE](//www.arduino.cc/en/software) | Arduino | IDE | 1.8.15
[ESP8266 for Arduino](//github.com/esp8266/Arduino) | esp8266 project | SDK | 3.0.1
[ESP8266-OLED-SSD1306](//github.com/ThingPulse/esp8266-oled-ssd1306) | ThingPulse | knihovna | 4.2.0
[Arduino-Temperature-Control-Library](//github.com/milesburton/Arduino-Temperature-Control-Library) | milesburton | knihovna | 3.9.1
[OneWire](//github.com/PaulStoffregen/OneWire) | PaulStoffregen | knihovna | 2.3.5

### Obecný postup
1. stáhněte si konkrétní vydání nebo aktuální obsah repozitáře
2. připojte k PC svou vývojovou desku ESP8266 (vč. instalace ovladače)
3. v aplikaci Arduino IDE otevřete soubor "/telethermo/telethermo.ino"
4. do Arduino IDE doinstalujte potřebné SDK a knihovny
5. v souboru "nastaveni.h" nastavte vše nezbytné (Wi-Fi připojení a ThingSpeak API Key)
6. zkuste projekt sestavit kliknutím na tlačítko Ověřit
7. v nabídce Nástroje nastavte parametry své vývojové desky, port COM a klikněte na tlačítko Nahrát
8. činnost zařízení lze sledovat i přes Seriový monitor v Arduino IDE (115200 baudů)

### Možné zapojení (ilustrativně)

![schema](/schema_zapojeni.png)
