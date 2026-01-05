#include <WiFi.h>
#include <WebServer.h>
#include <FastLED.h>

// Setări WiFi
//------------------------------------------------------------
const char* ssid ="Your_WiFi";
const char* password = "Your_Pass";


//------------------------------------------------------------
// Setări pentru WS2812B
#define NUM_LEDS 30  // Numărul de LED-uri per picior

// dispunerea picioarelor 

//    p4-----25(14)  |        | (34) 5  -----p5
//    p3-----26(15)  |        | (27) 17 -----p6
//    p2-----27(16)  |        | (25) 16 -----p7
//    p1-----14(17)  |________| (24) 4  -----p8

// Definim pinii pentru cele 8 picioare
#define pin1 14     
#define pin2 27
#define pin3 26
#define pin4 25
#define pin5 5
#define pin6 17
#define pin7 16
#define pin8 4
//=--------------------------------------------
#define btn1 23 // buton stanga (stins)
#define btn2 22 // buton dreapta ( ciclare moduri aprindere)
//#define mic  21 // microfon

int sound_level=0;

CRGB leds1[NUM_LEDS];
CRGB leds2[NUM_LEDS];
CRGB leds3[NUM_LEDS];
CRGB leds4[NUM_LEDS];
CRGB leds5[NUM_LEDS];
CRGB leds6[NUM_LEDS];
CRGB leds7[NUM_LEDS];
CRGB leds8[NUM_LEDS];

// Variabile pentru efecte
int r = 0, g = 0, b = 0;
int effectNumber = 1;
int autoMode = 0;
bool dataUpdated = false;
int brightness = 100;  // Luminozitatea
long start = 0;
long t = 0;
int delayTime = 80;
int n=3;

int j=0;
int jum=0;
int contor=0;  //numar de apasari pe butonul de aprindere

unsigned long currentMillis=0;
unsigned long previousMillis=0;
int i=0;

bool efect10_activ=false;

//efect 18
uint8_t pas = 1;
unsigned long t0 = 0;
//----------------------

String ip="";

// Obiect WebServer
WebServer server(80);
boolean online=false;

// Culoarea inițială
String color = "FF0000";

//--------------------------------------------------------------------------------------
// variabile afisare ip
// afisare ip
  int octet1 = 0;
  int octet2 = 0;
  int octet3 = 0;
  int octet4 = 0;
  IPAddress localIP="0.0.0.0";
  String localIPString="";
// Matricea cifrelor 0-9 reprezentate pe segmente de 10 LED-uri
// Fiecare cifră este reprezentată de 10 poziții, 1 înseamnă LED aprins, 0 LED stins
byte digits[10][10] = {
  {0,0,0,0,0,0,0,0,0,0}, // 0
  {0,1,0,0,0,0,0,0,0,0}, // 1
  {0,1,1,0,0,0,0,0,0,0}, // 2
  {0,1,1,1,0,0,0,0,0,0}, // 3
  {0,1,1,1,1,0,0,0,0,0}, // 4
  {0,1,1,1,1,1,0,0,0,0}, // 5
  {0,1,1,1,1,1,1,0,0,0}, // 6
  {0,1,1,1,1,1,1,1,0,0}, // 7
  {0,1,1,1,1,1,1,1,1,0}, // 8
  {0,1,1,1,1,1,1,1,1,1}  // 9
};

 int attemptCounter = 0; // Declari un contor pentru numărul de încercări

void setup() 
{
  Serial.begin(9600);
  
  //Setari AP
  //WiFi.softAP(ssid, password);
  //Serial.println("===============================================");
  //Serial.println("AP pornit. Conecteaza-te la: ESP32-LED");
  //Serial.println("IP: 192.168.4.1");
  //Serial.println("=====================");
  //Serial.print("IP Address: ");
  //Serial.println(WiFi.localIP());
  //localIP = WiFi.localIP();
  //Serial.println("===============================================");

  // Așteptăm conectarea la WiFi
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED && attemptCounter < 10) {
    delay(1000);
    Serial.println("Try connecting to WiFi... -> Attempt :  "+String(attemptCounter));
    attemptCounter++; // Incrementezi contorul la fiecare încercare
  }
  Serial.println("Verificarea conecxiunii si afisarea IP-ului");
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("--WiFi----WiFi----WiFi----WiFi----WiFi--");
    Serial.println("Connected to WiFi!");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
    localIP = WiFi.localIP();
    online=true;
  } 
  else {
    Serial.println("Failed to connect to WiFi after 10 attempts.");
    Serial.println("Se va trece la modul de lucru offline, comanda se va face prin butoane");
    localIP="10.0.0.1";
    online=false;
  }

  // Inițializăm fiecare bandă de LED-uri WS2812B pentru fiecare picior
  FastLED.addLeds<WS2812B, pin1, GRB>(leds1, NUM_LEDS);
  FastLED.addLeds<WS2812B, pin2, GRB>(leds2, NUM_LEDS);
  FastLED.addLeds<WS2812B, pin3, GRB>(leds3, NUM_LEDS);
  FastLED.addLeds<WS2812B, pin4, GRB>(leds4, NUM_LEDS);
  FastLED.addLeds<WS2812B, pin5, GRB>(leds5, NUM_LEDS);
  FastLED.addLeds<WS2812B, pin6, GRB>(leds6, NUM_LEDS);
  FastLED.addLeds<WS2812B, pin7, GRB>(leds7, NUM_LEDS);
  FastLED.addLeds<WS2812B, pin8, GRB>(leds8, NUM_LEDS);

  FastLED.setBrightness(brightness);

  // După inițializarea benzilor, afișăm IP-ul
  afis_ip();

  // Definim pagina web
  server.on("/", handleRoot);
  server.on("/stingere", handleStingere);  // Rută pentru stingere

  // Pornim serverul
  server.begin();
  Serial.println("--------------------------------------------------");
  Serial.println("ESP32 Spider LED Controller - Efecte de aprindere");
  Serial.println("Program : esp32-paianjen.ino");
  Serial.println("Tip de placa - ESP32 DEVKIT V1");
  Serial.println("Serial port setat pe : 115200");
  Serial.println("Numar de leduri : 8 x " + String(NUM_LEDS));
  Serial.println("PINI : D13,D12,D14,D27 - pin leduri stanga; D15,D2,D4,D16 - pin leduri dreapta; D23 - buton stingere; D22 - buton aprindere");
  Serial.println("---------------------------------------------------------------------------");
  Serial.println("Revizii ");
  Serial.println("r1 - adaugat butoane fizice");
  Serial.println("r2 - adaugat afisare IP + efect bobo");
  Serial.println("r3 - modificat numarul de incercari la conectarea in retea (10 ori si daca nu se conecteaza - poate sa lucreze offline");
  Serial.println("r4 - Modificat pagina Web");

  pinMode(btn1, INPUT_PULLDOWN);  // Configurare pin pentru butonul 1
  pinMode(btn2, INPUT_PULLDOWN);  // Configurare pin pentru butonul 2
  pinMode(mic,INPUT);
  
  Serial.println("============================");
  if(online)
    {
      Serial.println("Mod online");
      test_on();
    }
  else
    {
      Serial.println("Mod offline");
      test_off();
    }
  Serial.println("============================");

}

void loop() 
{

  buton1();
  buton2();
  server.handleClient();
  if (dataUpdated) {
    updateLEDs();
    dataUpdated = false;
  }

}

void updateLEDs() {
  long number = strtol(color.c_str(), NULL, 16);
  r = (number >> 16) & 255;
  g = (number >> 8) & 255;
  b = number & 255;

  FastLED.setBrightness(brightness);

  Serial.println(color);
  Serial.print("  CRGB(");
  Serial.print(r); Serial.print(",");
  Serial.print(g); Serial.print(",");
  Serial.print(b); Serial.println(")");

  Serial.println("Luminozitate = "+String(brightness));

  Serial.print(" Delay: "); Serial.println(delayTime);
  Serial.print(" Efect: "); Serial.println(effectNumber);
  Serial.print(" n: "); Serial.println(n);
  Serial.println("------------------------------------------------------------");
  fadeOut();
  FastLED.setBrightness(brightness);  // Actualizăm luminozitatea
  aprinde(r, g, b, delayTime, effectNumber,n);
}

// Funcție pentru a seta culoarea LED-urilor și a controla efectul pentru fiecare picior
void aprinde(int r, int g, int b, int delayTime, int effectNumber, int n) 
{
  if (effectNumber == 0)
    { 
      sting();
    }
  else if (effectNumber == 1) 
    {
      efect_nr();
      efect1(delayTime);
    } 
  else if (effectNumber == 2) 
    {
      efect_nr();
      efect2(delayTime);
    }
  else if(effectNumber==3)
    {
      efect_nr();efect3(delayTime);
    }
  else if(effectNumber==4)
    {
      efect_nr();efect4(delayTime);
    }
  else if(effectNumber==5)
    {
      efect_nr();
      for(int i=0;i<n;i++){efect5(delayTime);} 
    }
  else if (effectNumber == 6) 
    {
      efect_nr();
      for(int i=0;i<n;i++){efect6(delayTime);}
    }
  else if (effectNumber == 7) 
    {
      efect_nr();
      for(int i=0;i<n;i++){efect7(delayTime);}
    }
  else if(effectNumber == 8)
    {
      efect_nr();
      for(int i=1;i<=n;i++){efect8(delayTime);}
    }
  else if (effectNumber == 9) 
    {
      efect_nr();
      for(int i=0;i<n;i++){efect9(delayTime);}
    }
  else if (effectNumber == 10)
    {
      efect_nr();
      for(int i=1;i<=n;i++){efect10(delayTime);}
    }
  else if (effectNumber == 11)
    {
      efect_nr();
      for(int i=1;i<=n;i++){efect11(delayTime);}
    }
  else if (effectNumber == 12)
    {
      efect_nr();
      for(int i=1;i<=n;i++){efect12(delayTime);}
    }
  else if (effectNumber == 13)
    {
      efect_nr();
      for(int i=1;i<=n;i++){efect13(delayTime);}
    }
  else if (effectNumber == 14)
    {
      efect_nr();
      for(int i=1;i<=n;i++){efect14(delayTime);}
    }
  else if (effectNumber == 15)
    {
      efect_nr();
      for(int i=1;i<=n;i++){efect15(delayTime);}
    }
  else if (effectNumber == 16)
    {
      efect_nr();
      for(int i=1;i<=n;i++){efect16(delayTime);}
    }
  else if (effectNumber == 17)
    {
      efect_nr();
      for(int i=1;i<=n;i++){efect17(delayTime);}
    }
  else if (effectNumber == 18)
    {
      efect_nr();
      for(int i=1;i<=n;i++){efect18(delayTime);}
    }
  else if (effectNumber == 19)
    {
      efect_nr();
      for(int i=1;i<=n;i++){efect19(delayTime);}
    }
  else if (effectNumber == 20)
    {

    }

  else if (effectNumber==99)
    {
      automat();
    }    
}



void sting() {
    fill_solid(leds1, NUM_LEDS, CRGB::Black);
    fill_solid(leds2, NUM_LEDS, CRGB::Black);
    fill_solid(leds3, NUM_LEDS, CRGB::Black);
    fill_solid(leds4, NUM_LEDS, CRGB::Black);
    fill_solid(leds5, NUM_LEDS, CRGB::Black);
    fill_solid(leds6, NUM_LEDS, CRGB::Black);
    fill_solid(leds7, NUM_LEDS, CRGB::Black);
    fill_solid(leds8, NUM_LEDS, CRGB::Black);
    FastLED.show();
}

void automat() 
{
  efect5();
  delay(3000);
  fadeOut();
  efect6();
  delay(3000);
  fadeOut();
  efect7();
  delay(3000);
  fadeOut();
  efect8();
  delay(3000);
  fadeOut();
  efect9();
  delay(3000);
  fadeOut();
  efect10();
  delay(3000);
  fadeOut();
  efect11();
  delay(3000);
  fadeOut();
  efect12();
  delay(3000);
  fadeOut();
  efect13();
  delay(3000);
  fadeOut();
  efect14();
  delay(3000);
  fadeOut();
  efect15();
  delay(3000);
  fadeOut();
  efect16();
  delay(3000);
  fadeOut();
  efect17();
  delay(3000);
  fadeOut();
  efect18);
  delay(3000);
  fadeOut();
  efect19();
  delay(3000);
  fadeOut();
}

void fadeOut() {
  for (int brightness = 100; brightness >= 0; brightness--) {
    FastLED.setBrightness(brightness);
    FastLED.show();
    delay(20);
  }
  FastLED.setBrightness(255);
  sting();
}

void buton1()
{
  if (digitalRead(btn1) == HIGH)        // Verifică dacă butonul este apăsat
  {  
    effectNumber = 0;   // Stinge efectele
    Serial.println("Buton1 apăsat: effectNumber = 0 (stins)");
    delay(200);  // Delay pentru a evita citirea repetată din cauza zgomotului mecanic
    aprinde(r, g, b, delayTime, effectNumber,n);
  }
}

void buton2()
{
 int ef0=effectNumber;
 if (digitalRead(btn2) == HIGH)        // Verifică dacă butonul este apăsat
 {  
    effectNumber++;  // Treci la următorul efect
    contor++;
    if(effectNumber!=ef0){sting();}
    if(effectNumber > 19) effectNumber = 1;  // Revine la 1 dacă depășește 17
    Serial.print("Buton2 apăsat: effectNumber = ");
    Serial.println(effectNumber);
    delay(200);  // Delay pentru a evita citirea repetată din cauza zgomotului mecanic      
    Serial.println("Numar de apasari pe butonul 2 = "+String(contor));
    aprinde(r, g, b, delayTime, effectNumber,n);
 }
}

