
// Funcția pentru afișarea unei cifre pe un segment de 10 LED-uri
void displayDigit(CRGB* leds, int digit, int startPos, CRGB color) 
{
  Serial.println("Afisare o cifra");
  for (int i = 0; i < 10; i++) 
  {
    if (digits[digit][i] == 1) {
      leds[startPos + i] = color;  // Aprinde LED-ul cu culoarea specificată
    } else {
      leds[startPos + i] = CRGB::Black;  // Stinge LED-ul
    }
  }
  Serial.println("Final afisare o cifra");
}

// Funcția pentru afișarea unui număr de până la 3 cifre pe un segment de 30 LED-uri
void displayNumber1(CRGB* leds, int number) 
  {
  Serial.println("Afisare octet");  
  // Afișează prima cifră (sutele) în roșu
  displayDigit(leds, number / 100, 20, CRGB::Red);

  // Afișează a doua cifră (zecile) în verde
  displayDigit(leds, (number / 10) % 10, 10, CRGB::Green);

  // Afișează a treia cifră (unitățile) în albastru
  displayDigit(leds, number % 10, 0, CRGB::Blue);
  Serial.println("Final afisare octet");
}

void afis_ip() 
{
  Serial.println("Incepe afisarea IP");
  localIPString = WiFi.localIP().toString();

  // Extrage fiecare octet din adresa IP
  octet1 = localIP[0];
  octet2 = localIP[1];
  octet3 = localIP[2];
  octet4 = localIP[3];

  if(octet1 == 192 && octet2 == 168 && octet4>0)
    {
     Serial.println("S-a facut conexiunea la reteau a locala IP este :");
     Serial.println("IP-ul : " + localIPString + ";   octet1 =  " + String(octet1) + ";    octet2 =  " + String(octet2) + ";   octet3 = " + String(octet3) + ";   octet4 = " + String(octet4));
    // Afișează fiecare octet pe câte o bandă de LED-uri
    Serial.println("Va incepe afisarea IP-ului de la stanga la dreapta pe piciorele din stanga ");
    afisare_ip();
    }
  else
  {
    Serial.println("NU s-a facut conexiunea la reteau a locala IP este : octet1 =  " + String(octet1) + ";    octet2 =  " + String(octet2) + ";   octet3 = " + String(octet3) + ";   octet4 = " + String(octet4));
    Serial.println("Se va afisa lipsa IP-ului -  adica picioarele din stanga vor fi rosii");
    afisare_non_ip();
  }    
}


void afisare_non_ip()
{
  for (int i=0; i<NUM_LEDS;i++)
  {
  leds1[i] = CRGB(250,  0,  0);
  leds2[i] = CRGB(250,  0,  0);
  leds3[i] = CRGB(250,  0,  0);
  leds4[i] = CRGB(250,  0,  0);
  delay(delayTime*2);
  FastLED.show();
  }
}

void afisare_ip()
{
  // Afișează primul octet pe prima bandă de LED-uri
  displayNumber1(leds1, octet1);    // Primul octet pe banda 1
  FastLED.show();
  delay(100);  // Pauză între afișări
  // Afișează al doilea octet pe a doua bandă de LED-uri
  displayNumber1(leds2, octet2);    // Al doilea octet pe banda 2
  FastLED.show();
  delay(100);  // Pauză între afișări
  // Afișează al treilea octet pe a treia bandă de LED-uri
  displayNumber1(leds3, octet3);    // Al treilea octet pe banda 3
  FastLED.show();
  delay(100);  // Pauză între afișări
  // Afișează al patrulea octet pe a patra bandă de LED-uri
  displayNumber1(leds4, octet4);    // Al patrulea octet pe banda 4
  FastLED.show();
  delay(100);  // Pauză între afișări
}
