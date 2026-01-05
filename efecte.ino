void efect1(int d)
{
  delayTime=d;
  Serial.println("Incepe Efect 1 -> aprindere 0 la N");
  for(int i=0;i<NUM_LEDS;i++){
    leds1[i] = CRGB(r, g, b);
    leds2[i] = CRGB(r, g, b);
    leds3[i] = CRGB(r, g, b);
    leds4[i] = CRGB(r, g, b);
    leds5[i] = CRGB(r, g, b);
    leds6[i] = CRGB(r, g, b);  
    leds7[i] = CRGB(r, g, b);
    leds8[i] = CRGB(r, g, b);
    FastLED.show();
    delay(delayTime);
  }
  /*
  // - varianta fara delay()
  unsigned long previousMillis1=0;
  if (currentMillis - previousMillis1 < (unsigned long)delayTime) return;
  previousMillis1 = currentMillis;

    leds1[i] = CRGB(r, g, b);
    leds2[i] = CRGB(r, g, b);
    leds3[i] = CRGB(r, g, b);
    leds4[i] = CRGB(r, g, b);
    leds5[i] = CRGB(r, g, b);
    leds6[i] = CRGB(r, g, b);  
    leds7[i] = CRGB(r, g, b);
    leds8[i] = CRGB(r, g, b);

  FastLED.show();

  i++;
  if (i >= NUM_LEDS) i = 0;
  */
  Serial.println("Final efect1");
}


void efect2(int d)
{
  delayTime=d;
  Serial.println("Incepe Efect 2 -> aprindere N la 0");
  for(int i=NUM_LEDS;i>=0;i--){
  leds1[i] = CRGB(r, g, b);
  leds2[i] = CRGB(r, g, b);
  leds3[i] = CRGB(r, g, b);
  leds4[i] = CRGB(r, g, b);
  leds5[i] = CRGB(r, g, b);
  leds6[i] = CRGB(r, g, b);  
  leds7[i] = CRGB(r, g, b);
  leds8[i] = CRGB(r, g, b);
  delay(delayTime);
  FastLED.show();
  }
  /*
  if (currentMillis - previousMillis < (unsigned long)delayTime) return;
  previousMillis = currentMillis;

  int pos = (NUM_LEDS - 1) - i;

  leds1[pos] = CRGB(r, g, b);
  leds2[pos] = CRGB(r, g, b);
  leds3[pos] = CRGB(r, g, b);
  leds4[pos] = CRGB(r, g, b);
  leds5[pos] = CRGB(r, g, b);
  leds6[pos] = CRGB(r, g, b);  
  leds7[pos] = CRGB(r, g, b);
  leds8[pos] = CRGB(r, g, b);

  FastLED.show();

  i++;
  if (i >= NUM_LEDS) i = 0;*/
  Serial.println("Final efect2");
}


void efect3(int d)
{
  delayTime=d;
  Serial.println("Incepe Efect 3 -> aprindere 0 la N - step 3");
  for(int i=0;i<NUM_LEDS;i+=3){
    leds1[i] = CRGB(r, g, b);
    leds2[i] = CRGB(r, g, b);
    leds3[i] = CRGB(r, g, b);
    leds4[i] = CRGB(r, g, b);
    leds5[i] = CRGB(r, g, b);
    leds6[i] = CRGB(r, g, b);  
    leds7[i] = CRGB(r, g, b);
    leds8[i] = CRGB(r, g, b);
    delay(delayTime);
    FastLED.show();
  }
  Serial.println("Final efect3");
}


void efect4(int d)
{
  delayTime=d;
  Serial.println("Incepe Efect 4 -> aprindere N la 0 - step 3");
  for(int i=NUM_LEDS;i>0;i-=3){
    leds1[i] = CRGB(r, g, b);
    leds2[i] = CRGB(r, g, b);
    leds3[i] = CRGB(r, g, b);
    leds4[i] = CRGB(r, g, b);
    leds5[i] = CRGB(r, g, b);
    leds6[i] = CRGB(r, g, b);  
    leds7[i] = CRGB(r, g, b);
    leds8[i] = CRGB(r, g, b);
    delay(delayTime);
    FastLED.show();
  }
  Serial.println("Final efect4");
}

void efect5(int d)
{   
  delayTime=d;
  Serial.println("Incepe Efect 5 -> Aprindere catre jumate de la 0 si N");
  jum=NUM_LEDS/2;
  for (int i = 0;i < jum; i++)
  {
    j=NUM_LEDS-i;
    leds1[i] = CRGB(r, g, b);
    leds1[j]=leds1[i];

    leds2[i] = CRGB(r, g, b);
    leds2[j]=leds2[i];
    
    leds3[i] = CRGB(r, g, b);
    leds3[j]=leds3[i];

    leds4[i] = CRGB(r, g, b);
    leds4[j]=leds4[i];

    leds5[i] = CRGB(r, g, b);
    leds5[j]=leds5[i];
    
    leds6[i] = CRGB(r, g, b);
    leds6[j]=leds6[i];

    leds7[i] = CRGB(r, g, b);
    leds7[j]=leds7[i];

    leds8[i] = CRGB(r, g, b);
    leds8[j]=leds8[i];

    delay(delayTime);
    FastLED.show();
  }
  Serial.println("Final efect5");
}


void efect6(int d)
{
  delayTime=d;
  Serial.println("Incepe Efect 6 -> Aprindere cate un picior");
  // Aprindem întreg piciorul curent
    for (int i = 0; i < NUM_LEDS; i++) 
    {
      leds1[i] = CRGB(r, g, b);
      FastLED.show();  // Actualizăm LED-urile pentru piciorul curent
      delay(delayTime);
    }
    for (int i = 0; i < NUM_LEDS; i++) 
    {
      leds2[i] = CRGB(r, g, b);
      FastLED.show();  // Actualizăm LED-urile pentru piciorul curent
      delay(delayTime);
    }
    for (int i = 0; i < NUM_LEDS; i++) 
    {
      leds3[i] = CRGB(r, g, b);
      FastLED.show();  // Actualizăm LED-urile pentru piciorul curent
      delay(delayTime);
    }
    for (int i = 0; i < NUM_LEDS; i++) 
    {
      leds4[i] = CRGB(r, g, b);
      FastLED.show();  // Actualizăm LED-urile pentru piciorul curent
      delay(delayTime);
    }
    for (int i = 0; i < NUM_LEDS; i++) 
    {
      leds5[i] = CRGB(r, g, b);
      FastLED.show();  // Actualizăm LED-urile pentru piciorul curent
      delay(delayTime);
    }
    for (int i = 0; i < NUM_LEDS; i++) 
    {
      leds6[i] = CRGB(r, g, b);
      FastLED.show();  // Actualizăm LED-urile pentru piciorul curent
      delay(delayTime);
    }
    for (int i = 0; i < NUM_LEDS; i++) 
    {
      leds7[i] = CRGB(r, g, b);
      FastLED.show();  // Actualizăm LED-urile pentru piciorul curent
      delay(delayTime);
    }
    for (int i = 0; i < NUM_LEDS; i++) 
    {
      leds8[i] = CRGB(r, g, b);
      FastLED.show();  // Actualizăm LED-urile pentru piciorul curent
      delay(delayTime);
    }
    Serial.println("Final Efect6");    
}

void efect7(int d)
{
  delayTime=d;
  Serial.println("Incepe Efect 7 -> Aprindere prin umplere");
  int u=0;
  while(u<NUM_LEDS)
  {
    for(int i=NUM_LEDS-1;i>u;i--)
    {
    leds1[i] = CRGB(r, g, b);
    leds2[i] = CRGB(r, g, b);
    leds3[i] = CRGB(r, g, b);
    leds4[i] = CRGB(r, g, b);
    leds5[i] = CRGB(r, g, b);
    leds6[i] = CRGB(r, g, b);  
    leds7[i] = CRGB(r, g, b);
    leds8[i] = CRGB(r, g, b);
    delay(delayTime);      
    FastLED.show();
    leds1[i+1] = CRGB(0, 0, 0);
    leds2[i+1] = CRGB(0, 0, 0);
    leds3[i+1] = CRGB(0, 0, 0);
    leds4[i+1] = CRGB(0, 0, 0);
    leds5[i+1] = CRGB(0, 0, 0);
    leds6[i+1] = CRGB(0, 0, 0);  
    leds7[i+1] = CRGB(0, 0, 0);
    leds8[i+1] = CRGB(0, 0, 0);
    }    
  u++;
  }
  Serial.println("Final Efect7");  
}

void efect8(int d)
{
  delayTime=d;
  Serial.println("Incep Efect 8 - raze");
    for(int i=1;i<NUM_LEDS;i++)
    {
      leds1[i] = CRGB(r, g, b);
      leds2[i] = CRGB(r, g, b);
      leds3[i] = CRGB(r, g, b);
      leds4[i] = CRGB(r, g, b);
      leds5[i] = CRGB(r, g, b);
      leds6[i] = CRGB(r, g, b);  
      leds7[i] = CRGB(r, g, b);
      leds8[i] = CRGB(r, g, b);
      delay(delayTime);      
      FastLED.show();
      leds1[i-1] = CRGB(0, 0, 0);
      leds2[i-1] = CRGB(0, 0, 0);
      leds3[i-1] = CRGB(0, 0, 0);
      leds4[i-1] = CRGB(0, 0, 0);
      leds5[i-1] = CRGB(0, 0, 0);
      leds6[i-1] = CRGB(0, 0, 0);  
      leds7[i-1] = CRGB(0, 0, 0);
      leds8[i-1] = CRGB(0, 0, 0);
      delay(delayTime);      
      FastLED.show();
    }
  Serial.println("Final Efect8");  
}

void efect9(int d)
{
  delayTime=d;
  Serial.println("Incepe Efect 9 -> Aprindere picior cu picior");
  for(int t=0; t<3;t++)
  {
    for (int picior = 1; picior <= 8; picior++) // Iterăm prin fiecare picior
    {
      CRGB* currentLeds;  // Pointer pentru banda de LED-uri curentă

      // Selectăm piciorul curent pe baza numărului
      switch (picior) 
      {
          case 1: currentLeds = leds1; break;
          case 2: currentLeds = leds2; break;
          case 3: currentLeds = leds3; break;
          case 4: currentLeds = leds4; break;
          case 5: currentLeds = leds5; break;
          case 6: currentLeds = leds6; break;
          case 7: currentLeds = leds7; break;
          case 8: currentLeds = leds8; break;
      }
        // Aprindem piciorul curent
        
      for (int i = 0; i < NUM_LEDS; i++) 
        {
            currentLeds[i] = CRGB(r, g, b); // Aprindem fiecare LED
        }
        FastLED.show();  // Afișăm starea LED-urilor
        delay(delayTime);  // Pauză pentru a vedea piciorul aprins

        // Stingem piciorul curent
      for (int i = 0; i < NUM_LEDS; i++) 
        {
          currentLeds[i] = CRGB::Black; // Stingem fiecare LED
        }
        FastLED.show();  // Afișăm LED-urile stinse
        delay(delayTime);  // Pauză între picioare
    }
  }
  Serial.println("Final Efect9");    
}

void efect10(int d)
{
  delayTime=d;
  int deltahue=255/NUM_LEDS;
  for(int i=0;i<NUM_LEDS*5;i++)
    {
    fill_rainbow(leds1, NUM_LEDS, i, deltahue);
    fill_rainbow(leds2, NUM_LEDS, i, deltahue);
    fill_rainbow(leds3, NUM_LEDS, i, deltahue);
    fill_rainbow(leds4, NUM_LEDS, i, deltahue);
    fill_rainbow(leds5, NUM_LEDS, i, deltahue);
    fill_rainbow(leds6, NUM_LEDS, i, deltahue);
    fill_rainbow(leds7, NUM_LEDS, i, deltahue);
    fill_rainbow(leds8, NUM_LEDS, i, deltahue);
    FastLED.show();
    delay(delayTime);
    }
}

void efect11(int d)
{
  delayTime=d;
  int r[6]={200,  0,  0,200,200,  0};
  int g[6]={  0,200,  0,200,  0,200};
  int b[6]={  0,  0,200,  0,200,200};
  int j=0;
  int k=0;
  int c=0;
  for (int i=0;i<=50;i++)
    {
      j=random(0,NUM_LEDS);
      c=random(0,5);
      leds1[j]=CRGB(r[c],g[c],b[c]);
      leds2[j]=CRGB(r[c],g[c],b[c]);
      leds3[j]=CRGB(r[c],g[c],b[c]);
      leds4[j]=CRGB(r[c],g[c],b[c]);
      leds5[j]=CRGB(r[c],g[c],b[c]);
      leds6[j]=CRGB(r[c],g[c],b[c]);
      leds7[j]=CRGB(r[c],g[c],b[c]);
      leds8[j]=CRGB(r[c],g[c],b[c]);
      FastLED.show();
      delay(delayTime);
    }
    
  delay(delayTime*4);   
  fadeOut();
  FastLED.setBrightness(255);
}

void efect12(int d)
{
  delayTime=d;
  Serial.println("Efect de bomboana 5 (bobo - NOBLEND)"); 
  //pagina+="<p>"+ formattedTime +" --> Efect de bomboana 5 (bobo - NOBLEND)</p>";
  int i=0;
  int val=2;
  
  // culoare 1
  int rd[6]= {250,  0,  0,250,  0,250};
  int gd[6]= {  0,250,  0,250,250,  0};
  int bd[6]= {  0,  0,250,  0,250,250};

  //culoare 2 
  int ri[6]= {  0,250,  0,  0,250,  0};
  int gi[6]= {  0,  0,250,  0,  0,250};
  int bi[6]= {250,  0,  0,250,  0,  0};

  int bobomax=6;

  while(i<bobomax)
  {
    CRGBPalette16 boboPalette = CRGBPalette16 (
      CRGB(rd[i],gd[i],bd[i]),
      CRGB(rd[i],gd[i],bd[i]),
      CRGB(ri[i],gi[i],bi[i]),
      CRGB(ri[i],gi[i],bi[i]),
    
      CRGB(rd[i],gd[i],bd[i]),
      CRGB(rd[i],gd[i],bd[i]),
      CRGB(ri[i],gi[i],bi[i]),
      CRGB(ri[i],gi[i],bi[i]),
    
      CRGB(rd[i],gd[i],bd[i]),
      CRGB(rd[i],gd[i],bd[i]),
      CRGB(ri[i],gi[i],bi[i]),
      CRGB(ri[i],gi[i],bi[i]),

      CRGB(rd[i],gd[i],bd[i]),
      CRGB(rd[i],gd[i],bd[i]),
      CRGB(ri[i],gi[i],bi[i]),
      CRGB(ri[i],gi[i],bi[i])
    );
    while(val<8)
    {
      for(int j=0;j<255;j++)
      {
        fill_palette(leds1, NUM_LEDS, j, val, boboPalette, 255,NOBLEND);
        fill_palette(leds2, NUM_LEDS, j, val, boboPalette, 255,NOBLEND);
        fill_palette(leds3, NUM_LEDS, j, val, boboPalette, 255,NOBLEND);
        fill_palette(leds4, NUM_LEDS, j, val, boboPalette, 255,NOBLEND);
        fill_palette(leds5, NUM_LEDS, j, val, boboPalette, 255,NOBLEND);
        fill_palette(leds6, NUM_LEDS, j, val, boboPalette, 255,NOBLEND);
        fill_palette(leds7, NUM_LEDS, j, val, boboPalette, 255,NOBLEND);
        fill_palette(leds8, NUM_LEDS, j, val, boboPalette, 255,NOBLEND);
        delay(delayTime);    
        FastLED.show();
      }
      val=val+2;
      //Serial.print("Valoare factor : ");Serial.print(val);Serial.print("  --- Pereche culori : ");Serial.println(i);
    }
    i++;
    val=2;
  }
}

void efect13(int d)
{
  delayTime=d;
  Serial.println("Efect cometa cu coada aprinsa"); 
  for (int h=0;h<255;h+=20)
  {
    for(int i=0;i<NUM_LEDS;i++)
    {
      leds1[i] = CHSV(h,250,250);
      leds2[i] = CHSV(h,250,250);
      leds3[i] = CHSV(h,250,250);
      leds4[i] = CHSV(h,250,250);
      leds5[i] = CHSV(h,250,250);
      leds6[i] = CHSV(h,250,250);
      leds7[i] = CHSV(h,250,250);
      leds8[i] = CHSV(h,250,250);
      delay(50);
      FastLED.show();
      fadeLightBy(leds1,NUM_LEDS,50);
      fadeLightBy(leds2,NUM_LEDS,50);
      fadeLightBy(leds3,NUM_LEDS,50);
      fadeLightBy(leds4,NUM_LEDS,50);
      fadeLightBy(leds5,NUM_LEDS,50);
      fadeLightBy(leds6,NUM_LEDS,50);
      fadeLightBy(leds7,NUM_LEDS,50);
      fadeLightBy(leds8,NUM_LEDS,50);
    }
  }   
}

void efect14(int d)
{
  delayTime=d;
  Serial.println("Efect cometa cu coada stinsa"); 
  for (int h=0;h<255;h+=20)
  {
    for(int i=0;i<NUM_LEDS;i++)
    {
      leds1[i] = CHSV(h,250,250);
      leds2[i] = CHSV(h,250,250);
      leds3[i] = CHSV(h,250,250);
      leds4[i] = CHSV(h,250,250);
      leds5[i] = CHSV(h,250,250);
      leds6[i] = CHSV(h,250,250);
      leds7[i] = CHSV(h,250,250);
      leds8[i] = CHSV(h,250,250);
      delay(50);
      FastLED.show();
      fadeToBlackBy(leds1,NUM_LEDS,50);
      fadeToBlackBy(leds2,NUM_LEDS,50);
      fadeToBlackBy(leds3,NUM_LEDS,50);
      fadeToBlackBy(leds4,NUM_LEDS,50);
      fadeToBlackBy(leds5,NUM_LEDS,50);
      fadeToBlackBy(leds6,NUM_LEDS,50);
      fadeToBlackBy(leds7,NUM_LEDS,50);
      fadeToBlackBy(leds8,NUM_LEDS,50);
    }
  }   
}


void efect15(int d)
{
  delayTime=d;
  for(int i=0;i<NUM_LEDS;i++){
  
  fadeToBlackBy(leds1, NUM_LEDS, 50);
  fadeToBlackBy(leds2, NUM_LEDS, 50);
  fadeToBlackBy(leds3, NUM_LEDS, 50);
  fadeToBlackBy(leds4, NUM_LEDS, 50);
  fadeToBlackBy(leds5, NUM_LEDS, 50);
  fadeToBlackBy(leds6, NUM_LEDS, 50);
  fadeToBlackBy(leds7, NUM_LEDS, 50);
  fadeToBlackBy(leds8, NUM_LEDS, 50);
  
  leds1[i] = CRGB::White;  
  leds2[i] = CRGB::White; 
  leds3[i] = CRGB::White; 
  leds4[i] = CRGB::White; 
  leds5[i] = CRGB::White;
  leds6[i] = CRGB::White;
  leds7[i] = CRGB::White;
  leds8[i] = CRGB::White;
  FastLED.show();
  delay(delayTime);}
}


// -------------------- EF_COMETA ----------------------
void efect16(int d) {

delayTime=d;
byte hue=0;
for(int i=0;i<NUM_LEDS;i++){

  fadeToBlackBy(leds8, NUM_LEDS, 30);
  fadeToBlackBy(leds1, NUM_LEDS, 30);
  fadeToBlackBy(leds2, NUM_LEDS, 30);
  fadeToBlackBy(leds3, NUM_LEDS, 30);
  fadeToBlackBy(leds4, NUM_LEDS, 30);
  fadeToBlackBy(leds5, NUM_LEDS, 30);
  fadeToBlackBy(leds6, NUM_LEDS, 30);
  fadeToBlackBy(leds7, NUM_LEDS, 30);

  leds1[i] = CHSV(hue, 255, 255);
  leds2[i] = CHSV(hue, 255, 255);
  leds3[i] = CHSV(hue, 255, 255);
  leds4[i] = CHSV(hue, 255, 255);
  leds5[i] = CHSV(hue, 255, 255);
  leds6[i] = CHSV(hue, 255, 255);
  leds7[i] = CHSV(hue, 255, 255);
  leds8[i] = CHSV(hue, 255, 255);
  FastLED.show();
  delay(delayTime);
  hue=hue+255/NUM_LEDS;
  }
}

// -------------------- EF_PRIDE -----------------------
void efect17(int d) {
  delayTime=d;
  for(int hue=0;hue<256;hue+=5)
  {
  fill_solid(leds1, NUM_LEDS, CHSV(hue,250,250));
  fill_solid(leds2, NUM_LEDS, CHSV(hue,250,250));
  fill_solid(leds3, NUM_LEDS, CHSV(hue,250,250));
  fill_solid(leds4, NUM_LEDS, CHSV(hue,250,250));
  fill_solid(leds5, NUM_LEDS, CHSV(hue,250,250));
  fill_solid(leds6, NUM_LEDS, CHSV(hue,250,250));
  fill_solid(leds7, NUM_LEDS, CHSV(hue,250,250));
  fill_solid(leds8, NUM_LEDS, CHSV(hue,250,250));
  FastLED.show();
  delay(delayTime);
  }
}

void efect18(int d)
{
  delayTime=d;
const CRGB culori[8][8] = {
  {CRGB::Red,     CRGB::Green,   CRGB::Blue,    CRGB::Yellow, CRGB::Aqua,    CRGB::Purple, CRGB::Orange,  CRGB::Magenta},
  {CRGB::Magenta, CRGB::Red,     CRGB::Green,   CRGB::Blue,   CRGB::Yellow,  CRGB::Aqua,   CRGB::Purple,  CRGB::Orange},
  {CRGB::Orange,  CRGB::Magenta, CRGB::Red,     CRGB::Green,  CRGB::Blue,    CRGB::Yellow, CRGB::Aqua,    CRGB::Purple},
  {CRGB::Purple,  CRGB::Orange,  CRGB::Magenta, CRGB::Red,    CRGB::Green,   CRGB::Blue,   CRGB::Yellow,  CRGB::Aqua},
  {CRGB::Aqua,    CRGB::Purple,  CRGB::Orange,  CRGB::Magenta,CRGB::Red,     CRGB::Green,  CRGB::Blue,    CRGB::Yellow},
  {CRGB::Yellow,  CRGB::Aqua,    CRGB::Purple,  CRGB::Orange, CRGB::Magenta, CRGB::Red,     CRGB::Green,   CRGB::Blue},
  {CRGB::Blue,    CRGB::Yellow,  CRGB::Aqua,    CRGB::Purple, CRGB::Orange,  CRGB::Magenta,CRGB::Red,     CRGB::Green},
  {CRGB::Green,   CRGB::Blue,    CRGB::Yellow,  CRGB::Aqua,   CRGB::Purple,  CRGB::Orange, CRGB::Magenta, CRGB::Red}
};


  for(int j=0;j<8;j++)
  {
    for (int i = 0; i < NUM_LEDS; i++) {
    leds1[i]=culori[j][0];
    leds2[i]=culori[j][1];
    leds3[i]=culori[j][2];
    leds4[i]=culori[j][3];
    leds5[i]=culori[j][4];
    leds6[i]=culori[j][5];
    leds7[i]=culori[j][6];
    leds8[i]=culori[j][7];
    }
    FastLED.show();
    delay(1000);
  }
}

void efect19(int d)
{
  delayTime=d;
const CRGB culori[4][4] = {
  {CRGB::Red,     CRGB::Green,   CRGB::Blue,    CRGB::Yellow},
  {CRGB::Yellow,  CRGB::Red,     CRGB::Green,   CRGB::Blue},
  {CRGB::Blue,    CRGB::Yellow,  CRGB::Red,     CRGB::Green},
  {CRGB::Green,   CRGB::Blue,    CRGB::Yellow,  CRGB::Red}
};

  for(int j=0;j<4;j++)
  {
    for (int i = 0; i < NUM_LEDS; i++) {
    leds1[i]=leds8[i]=culori[j][0];
    leds2[i]=leds7[i]=culori[j][1];
    leds3[i]=leds6[i]=culori[j][2];
    leds4[i]=leds5[i]=culori[j][3];
    }
    FastLED.show();
    delay(1000);
  }
}

void vumetru()
{
  Serial.println("Incep Vumetru");
  sound_level=analogRead(sound_pin);
  int nled=map(sound_level,0,4095,0,NUM_LEDS);
  Serial.println("Nr. leduri : "+String(nled));
  for(int i=1;i<nled;i++)
    {
      leds1[i] = CRGB::Green;
      leds1[i-1]=CRGB::Black;
      FastLED.show();
      delay(10);
    }
  Serial.println("Final vumetru");  
}



void test_on()
{
  delay(5000);
  fadeOut();
  Serial.println("Test leduri online");
  Serial.println("==================");
  r=250;
  g=0;
  b=0;
  efect1(10);
  delay(500);
  r=0;
  g=250;
  b=0;
  efect1(10);
  delay(500);
  r=0;
  g=0;
  b=250;
  efect1(10);
  delay(500);
  fadeOut() ;
  Serial.println("==================");
  Serial.println("Final test leduri");
}

void test_off()
{
  delay(5000);
  fadeOut();
  Serial.println("Test leduri offline");
  Serial.println("-------------------");
  r=250;
  g=125;
  b=0;
  efect1(20);
  delay(500);
  r=0;
  g=250;
  b=125;
  efect1(20);
  delay(500);
  r=125;
  g=0;
  b=250;
  efect1(20);
  delay(500);
  fadeOut() ;
  Serial.println("-----------------");
  Serial.println("Final test leduri");
}

void efect_nr()
{
  for(int i=0;i<effectNumber;i++)
  {
    leds1[i] = CRGB(0, 255, 0);
    leds2[i] = CRGB(0, 255, 0);
    leds3[i] = CRGB(0, 255, 0);
    leds4[i] = CRGB(0, 255, 0);
    leds5[i] = CRGB(0, 255, 0);
    leds6[i] = CRGB(0, 255, 0);  
    leds7[i] = CRGB(0, 255, 0);
    leds8[i] = CRGB(0, 255, 0);
  }
  FastLED.show();
  delay(1000);
  FastLED.clear();
}