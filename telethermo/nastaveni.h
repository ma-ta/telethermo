/*
 *   ===========================================
 *   |              |                          |
 *   |  Tele        |  Freeware & Open source  |
 *   |      Thermo  |      (CC BY-SA 4.0)      |
 *   |              |                          |
 *   |-----------------------------------------|
 *   |                                         |
 *   |       github.com/ma-ta/telethermo       |
 *   |         © 2020-21  Martin TÁBOR         |
 *   |                                         |
 *   ===========================================
 *   
 *   
 *   =============================================
 *    KONFIGURAČNÍ SOUBOR
 *   ---------------------------------------------
 *    před kompilací je nutné nastavit sekci níže
 *   =============================================
 */


// ============================= NUTNO NASTAVIT =============================

// připojení k síti
const char *WIFI_NAZEV       = "";                  // SSID Wi-Fi sítě
const char *WIFI_HESLO       = "";                  // heslo k Wi-Fi síti
const String THINGSPEAK_KEY  = "0000000000000000";  // API key pro ThingSpeak

// názvy teploměrů
const String THERMO_0        = "Cidlo 1";           // čidlo 1
const String THERMO_1        = "Cidlo 2";           // čidlo 2

// ==========================================================================


// VÝCHOZÍ KONSTANTY (může být ponecháno)

// zobrazovaný název zařízení
const String NAZEV_PRODUKTU = "TeleThermo";
// URL serveru ThingSpeak
#define API_THINGSPEAK "api.thingspeak.com"
// zobrazované jednotky
const String JEDNOTKY = "°C";  // pouze popis pro uživatele (nezmění použité jednotky ve výpočtu)
// časový odstup mezi úkony
const int CETNOST_MERENI = (1000) *  9; // [ms] jak často měřit teplotu
const int CETNOST_UPLOAD = (1000) * 60; // [ms] jak často nahrávat na ThingSpeak
// výchozí teplota (není-li k dispozici aktuální hodnota)
const float TEPLOTA_NULL = -999.0;
// baud rate sériové linky
#define SERIAL_BAUD 115200
