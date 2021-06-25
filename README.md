# TeleThermo

> Wi-Fi teploměr se dvěma čidly (interiér/exteriér) a OLED displejem

## Funkce
- dvě teplotní čidla s přesnostní 0,5 °C
- OLED displej s aktuální teplotou a IP adresou zařízení
- vestavěný web-server pro zobrazení aktuálních hodnot
- ukládání hodnot do cloudu na ThingSpeak

## Potřebné součátky
Množství | Název
-------- | -----
1 | NodeMCU s ESP8266
2 | čidlo Dallas DS18B20
1 | rezistor 4k7 ohm
1 | OLED displej SSD1306 (128×64 px)
1 | čidlo Dallas DS18B20
1 | breadboard (nepájivé pole)
… | kabely, zdroj napájení

## Potřebný software a knihovny
Název | Kategorie | Ověřená verze
----- | --------- | -------------
[CH340 driver](http://www.wch-ic.com/products/CH340.html) (skrze Windows Update) | ovladač | 3.5.2019.1
[Arduino IDE](//www.arduino.cc/en/software) | IDE | 1.8.15
[ESP8266 for Arduino](//github.com/esp8266/Arduino) | SDK | 3.0.0
[ESP8266-OLED-SSD1306](//github.com/ThingPulse/esp8266-oled-ssd1306) | knihovna | 4.2.0
[DallasTemperature](//github.com/milesburton/Arduino-Temperature-Control-Library) | knihovna | 3.9.0
[OneWire](//github.com/PaulStoffregen/OneWire) | knihovna | 2.3.5

## Možné zapojení (ilustrativně)

![schema](/schema_zapojeni.png)
