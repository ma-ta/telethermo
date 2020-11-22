const String NAZEV_PRODUKTU = "TeleThermo";

// připojení k síti
const char *WIFI_NAZEV = "";  // SSID Wi-Fi sítě
const char *WIFI_HESLO = "";  // heslo k Wi-Fi síti
const String THINGSPEAK_KEY = "";  // API key pro ThingSpeak

// názvy teploměrů
const String THERMO_0 = "Cidlo 1";  // čidlo 1
const String  THERMO_1 = "Cidlo 2";  // čidlo 2

const String JEDNOTKY = "°C";  // pouze znak k zobrazení
const int CETNOST_MERENI = 9000; // [ms] jak často měřit teplotu
const int CETNOST_UPLOAD = 60000; // [ms] jak často nahrávat na ThingSpeak
