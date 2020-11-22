# TeleThermo

> Wi-Fi teploměr se dvěma čidly (vnitřní/vnější) a OLED displejem

## Funkce
- dvě teplotní čidla s přesnostní 0,5 °C
- OLED displej s aktuální teplotou a IP adresou zařízení
- vestavěný web-server pro zobrazení aktuálních hodnot
- upload do cloudu na ThingSpeak

## Potřebné součátky
Množství | Název
-------- | -----
1 | NodeMCU s ESP8266
2 | čidlo Dallas DS18B20
1 | rezistor 4k7 ohm
1 | OLED displej SSD1306 128x64 px
1 | čidlo Dallas DS18B20
& | kabely, zdroj napájení

## Možné zapojení (ilustrativně)

![schema](/schema_zapojeni.png)
