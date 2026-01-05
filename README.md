-------------------------------------------------------------------- EN

# WS2812B Spider Control 🕷️

Arduino project for controlling multiple WS2812B LED strips ("spider legs")
using a web interface.

## Features
- Web UI (color, brightness, effects)
- Multiple LED effects (rainbow, comets, disco, etc.)
- Parameter `n` for effect repetitions
- Works without delay() for most effects

## Hardware
- Arduino (ESP8266 / ESP32 / GIGA R1 WiFi)
- WS2812B LED strips
- External power supply

## Setup
1. Edit WiFi credentials in the code
2. Upload to board
3. Open browser at device IP

## License
MIT

------------------------------------------------------------------- RO

# WS2812B Spider Control 🕷️

Proiect Arduino pentru controlul mai multor benzi LED WS2812B („picioarele păianjenului”)
folosind o interfață web accesibilă din browser.

Interfața permite control în timp real al culorii, luminozității, efectelor și
al parametrilor acestora (delay, număr de repetări etc.).

---

## 🔧 Funcționalități

- Interfață web (HTML + CSS + JavaScript)
- Control culoare (RGB / Color Picker)
- Control luminozitate
- Selectare efecte LED
- Parametru `n` – număr de repetări pentru anumite efecte
- Efecte multiple (rainbow, cometă, disco, blink, auto mode etc.)
- Actualizare parametrilor din web (GET requests)
- Debug prin Serial Monitor
- Compatibil cu mai multe „picioare” (benzi LED)

---

## 🧰 Hardware necesar

- Placă Arduino cu WiFi  
- Benzi LED **WS2812B**
- Sursă de alimentare adecvată pentru LED-uri
- Rezistență pe linia de date (recomandat 330–470Ω)
- Condensator pe alimentare (recomandat)

---

## 📦 Biblioteci utilizate

- `FastLED`
- bibliotecile WiFi specifice plăcii (ESP 32 DEV KIT 1)

Asigură-te că ai instalate bibliotecile înainte de compilare.

---

## ⚙️ Configurare

1. Clonează repository-ul sau descarcă proiectul
2. Deschide fișierul `.ino` în Arduino IDE
3. Completează datele WiFi în cod:

const char* ssid = "YOUR_WIFI";
const char* password = "YOUR_PASSWORD";

Selectează placa corectă din Arduino IDE

Încarcă sketch-ul

Deschide Serial Monitor pentru a vedea adresa IP

Accesează IP-ul din browser

🌐 Interfața Web

Interfața permite:

alegerea culorii

ajustarea delay-ului

reglarea luminozității

selectarea efectului

setarea numărului de repetări (n)

mod automat (Auto Mode)

buton de stingere LED-uri

Design-ul este optimizat pentru:

desktop

telefon

tabletă

🧠 Structura logică

Web UI → trimite parametri către Arduino

Arduino → actualizează variabilele globale

Efectele LED rulează în funcție de parametrii primiți

Parametrul n controlează numărul de repetări pentru anumite efecte

🛑 Atenționări

Nu folosi alimentarea USB pentru benzi mari de LED-uri

Verifică masa comună între Arduino și sursa LED

Ajustează luminozitatea pentru a evita consum excesiv


## 🔧 Funcționalități

- Interfață web (HTML + CSS + JavaScript)
- Control culoare (Color Picker)
- Control luminozitate
- Selectare efecte LED
- Parametru `n` – număr de repetări pentru anumite efecte
- Mod automat (ciclare efecte)
- Butoane fizice pentru control local
- Debug prin Serial Monitor
- Control a 8 benzi LED WS2812B (8 „picioare”)

---

## 🧰 Hardware utilizat

- **ESP32**
- 8 benzi LED **WS2812B**
- Sursă de alimentare externă pentru LED-uri
- Rezistențe pe liniile de date (recomandat 330–470Ω)
- Condensator pe alimentare (recomandat ≥ 1000µF)
- 2 butoane fizice

---

## 🔌 Conectare pini ESP32

### 📍 Picioare LED (WS2812B)

// Definim pinii pentru cele 8 picioare
#define pin1 14     //p4	
#define pin2 27		//p3	
#define pin3 26		//p2	
#define pin4 25    	//p1
#define pin5 5		//p5
#define pin6 17		//p6
#define pin7 16		//p7
#define pin8 4		//p8

#define btn1 23 // buton stanga (stins)
#define btn2 22 // buton dreapta (ciclare moduri)
Buton	Pin ESP32	Funcție
BTN1	GPIO 23	Stingere LED-uri
BTN2	GPIO 22	Ciclare moduri / efecte


