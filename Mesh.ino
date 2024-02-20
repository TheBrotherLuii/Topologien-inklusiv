/*
Busstruktur
*/

#include <Adafruit_NeoPixel.h>

#define PC_ONE 10
#define PC_TWO 11
#define PC_THREE 12 
#define PC_FOUR 13

#define LED_STRIPE_ONE 18
#define LED_STRIPE_TWO 19
#define LED_STRIPE_THREE 20
#define LED_STRIPE_FOUR  21
#define LED_STRIPE_FIVE 22
#define LED_STRIPE_SIX 23

// SW == SWITCH
#define SW_PC_ONE 0  
#define SW_PC_TWO 1
#define SW_PC_THREE 2  
#define SW_PC_FOUR  3

#define SW_LED_STRIPE_ONE 4  
#define SW_LED_STRIPE_TWO 5
#define SW_LED_STRIPE_THREE 6 
#define SW_LED_STRIPE_FOUR  7
#define SW_LED_STRIPE_FIVE 8
#define SW_LED_STRIPE_SIX 9


Adafruit_NeoPixel pixel1 = Adafruit_NeoPixel(7, LED_STRIPE_ONE, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixel2 = Adafruit_NeoPixel(10, LED_STRIPE_TWO, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixel3 = Adafruit_NeoPixel(11, LED_STRIPE_THREE, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixel4 = Adafruit_NeoPixel(7, LED_STRIPE_FOUR, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixel5 = Adafruit_NeoPixel(8, LED_STRIPE_FIVE, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixel6 = Adafruit_NeoPixel(8, LED_STRIPE_SIX, NEO_GRB + NEO_KHZ800);

void setup() {
  //SWITCH
    pinMode(SW_LED_STRIPE_ONE, INPUT_PULLUP);
    pinMode(SW_LED_STRIPE_TWO, INPUT_PULLUP);
    pinMode(SW_LED_STRIPE_THREE, INPUT_PULLUP);
    pinMode(SW_LED_STRIPE_FOUR, INPUT_PULLUP);
    pinMode(SW_LED_STRIPE_FIVE, INPUT_PULLUP);
    pinMode(SW_LED_STRIPE_SIX, INPUT_PULLUP);

    pinMode(SW_PC_ONE, INPUT_PULLUP);
    pinMode(SW_PC_TWO, INPUT_PULLUP);
    pinMode(SW_PC_THREE, INPUT_PULLUP);
    pinMode(SW_PC_FOUR, INPUT_PULLUP);

  //LEDS
    pinMode(LED_STRIPE_ONE,OUTPUT);
    pinMode(LED_STRIPE_TWO,OUTPUT);
    pinMode(LED_STRIPE_THREE,OUTPUT);
    pinMode(LED_STRIPE_FOUR,OUTPUT);
    pinMode(LED_STRIPE_FIVE,OUTPUT);
    pinMode(LED_STRIPE_SIX,OUTPUT);

    pinMode(PC_ONE,OUTPUT);
    pinMode(PC_TWO,OUTPUT);
    pinMode(PC_THREE,OUTPUT);
    pinMode(PC_FOUR,OUTPUT);

    digitalWrite(PC_ONE, LOW);
    digitalWrite(PC_TWO, LOW);
    digitalWrite(PC_THREE, LOW);
    digitalWrite(PC_FOUR, LOW);
}

void loop() {
  int PX1_ON = 0;
  int PX2_ON = 0;
  int PX3_ON = 0;
  int PX4_ON = 0;
  int PX5_ON = 0;
  int PX6_ON = 0;
  int P1_State,P2_State,P3_State,P4_State,L1_State,L2_State,L3_State,L4_State,L5_State,L6_State = 0;
    
  P1_State = digitalRead(SW_PC_ONE);
  P2_State = digitalRead(SW_PC_TWO);
  P3_State = digitalRead(SW_PC_THREE);
  P4_State = digitalRead(SW_PC_FOUR);
  L1_State = digitalRead(SW_LED_STRIPE_ONE);
  L2_State = digitalRead(SW_LED_STRIPE_TWO);
  L3_State = digitalRead(SW_LED_STRIPE_THREE);
  L4_State = digitalRead(SW_LED_STRIPE_FOUR);
  L5_State = digitalRead(SW_LED_STRIPE_FIVE);
  L6_State = digitalRead(SW_LED_STRIPE_SIX);
//print
  //if (P1_State==1)
  //{Serial.println("P1");}
  //if (P2_State==1)
  //{Serial.println("P2");}
  //if (P3_State==1)
  //{Serial.println("P3");}
  //if (P4_State==1)
  //{Serial.println("P4");}
  if (L1_State==1)
  {Serial.println("L1");}
  if (L2_State==1)
  {Serial.println("L2");}
  if (L3_State==1)
  {Serial.println("L3");}
  if (L4_State==1)
  {Serial.println("L4");}
  if (L5_State==1)
  {Serial.println("L5");}
  if (L6_State==1)
  {Serial.println("L6");}

//LED STRIP LOGIC

  if(P1_State==1 && P2_State==1){
    if(L4_State==1)  {
      PX4_ON = 1;
    } else if (L2_State==1 && L5_State==1 && P4_State==1)  {
      PX2_ON = 1;
      PX5_ON = 1;
    } else if (L1_State==1 && L3_State==1 && P3_State==1)  {
      PX1_ON = 1;
      PX3_ON = 1;
    } else if ( L1_State==1 && L6_State==1 && L5_State==1 && P3_State==1 && P4_State==1)  {
      PX1_ON = 1;
      PX5_ON = 1;
      PX6_ON = 1;
    } else if (L2_State==1 && L6_State==1 && L3_State==1 && P4_State==1 && P3_State==1)  {
      PX2_ON = 1;
      PX3_ON = 1;
      PX6_ON = 1;
    } 
  }

  if(P1_State==1 && P3_State==1){
    if(L1_State==1) {
      PX1_ON = 1;
    } else if (L2_State==1 && L6_State==1 && P4_State==1)  {
      PX2_ON = 1;
      PX6_ON = 1;
    } else if (L4_State==1 && L3_State==1 && P2_State==1)  {
      PX4_ON = 1;
      PX3_ON = 1;
    } else if (L4_State==1 && L6_State==1 && L5_State==1 && P2_State==1 && P4_State==1)  {
      PX4_ON = 1;
      PX5_ON = 1;
      PX6_ON = 1;
    } else if (L2_State==1 && L5_State==1 && L3_State==1 && P4_State==1 && P2_State==1){
      PX2_ON = 1;
      PX5_ON = 1;
      PX3_ON = 1;
    }

  }

  if(P1_State==1 && P4_State==1){
    if(L2_State==1)  {
      PX2_ON = 1;
    } else if (L4_State==1 && L5_State==1 && P2_State==1)  {
      PX4_ON = 1;
      PX5_ON = 1;
    } else if (L1_State==1 && L6_State==1 && P3_State==1)  {
      PX1_ON = 1;
      PX6_ON = 1;
    } else if (L1_State==1 && L3_State==1 && L5_State==1 && P3_State==1 && P2_State==1)  {
      PX1_ON = 1;
      PX3_ON = 1;
      PX5_ON = 1;
    } else if (L3_State==1 && L4_State==1 && L6_State==1 && P3_State==1 && P2_State==1){ //TODO
      PX4_ON = 1;
      PX3_ON = 1;
      PX6_ON = 1;
    }
  
  }

  if(P2_State==1 && P3_State==1)  {
      if(L3_State==1){
        PX3_ON = 1;
      } else if (L5_State==1 && L6_State==1 && P4_State==1){
        PX5_ON = 1;
        PX6_ON = 1;
      } else if (L4_State==1 && L1_State==1 && P1_State==1){
        PX4_ON = 1;
        PX1_ON = 1;
      } else if (L4_State==1 && L2_State==1 && L6_State==1 && P1_State==1 && P4_State==1){
        PX4_ON = 1;
        PX2_ON = 1;
        PX6_ON = 1;
      } else if (L5_State==1 && L2_State==1 && L1_State==1 && P4_State==1 && P1_State==1) {
        PX5_ON = 1;
        PX2_ON = 1;
        PX1_ON = 1;
      }
  }

  if(P2_State==1 && P4_State==1)  {
    if(L5_State==1)  {
        PX5_ON = 1;
      } else if (L3_State==1 && L6_State==1 && P3_State==1)  {
        PX3_ON = 1;
        PX6_ON = 1;
      } else if (L4_State==1 && L2_State==1 && P1_State==1)  {
        PX4_ON = 1;
        PX2_ON = 1;
      } else if (L3_State==1 && L1_State==1 && L2_State==1 && P3_State==1 && P1_State==1)  {
        PX3_ON = 1;
        PX1_ON = 1;
        PX2_ON = 1;
      } else if (L4_State==1 && L1_State==1 && L6_State==1 && P1_State==1 && P3_State==1){
        PX4_ON = 1;
        PX1_ON = 1;
        PX6_ON = 1;
      }
  }

  if(P3_State==1 && P4_State==1){
    if(L6_State==1)  {
      PX6_ON = 1;
    } else if (L2_State==1 && L1_State==1 && P1_State==1) {
      PX2_ON = 1;
      PX1_ON = 1;
    } else if (L5_State==1 && L3_State==1 && P4_State==1){
      PX5_ON = 1;
      PX3_ON = 1;
    } else if (L5_State==1 && L4_State==1 && L1_State==1 && P2_State==1 && P1_State==1)  {
      PX5_ON = 1;
      PX4_ON = 1;
      PX1_ON = 1;
    } else if (L2_State==1 && L4_State==1 && L3_State==1 && P1_State==1 && P2_State==1){
      PX2_ON = 1;
      PX4_ON = 1;
      PX3_ON = 1;
    }
  }

//illuminate Pcs
  illuminateLED(PC_ONE,P1_State);
  illuminateLED(PC_TWO,P2_State);
  illuminateLED(PC_THREE,P3_State);
  illuminateLED(PC_FOUR,P4_State);

//illuminate LED STRIPES
  if(PX1_ON==1){
    pixel1On();
    Serial.println("1On");
  }
  else{
    pixel1Off();
  }
  if(PX2_ON==1){
    pixel2On();
    Serial.println("2On");
  }
  else {
    pixel2Off();
  }
  if(PX3_ON==1){
    pixel3On();
    Serial.println("3On");
  }
  else {
    pixel3Off();
  }
  if(PX4_ON==1){
    pixel4On();
    Serial.println("4On");
  }
  else {
    pixel4Off();
  }
  if(PX5_ON==1){
    pixel5On();
    Serial.println("5On");
  }
  else {
    pixel5Off();
  }
  if(PX6_ON==1){
    pixel6On();
    Serial.println("6On");
  }
  else {
    pixel6Off();
  }

delay(100);
}


void pixel1On(){
  //Turn LED Sripe ON
  for (int cntOn = 0; cntOn < 7; cntOn++) {
    pixel1.setPixelColor(cntOn, pixel1.Color(255,255,255));
  }
  pixel1.show();
}

void pixel2On(){
  //Turn LED Sripe ON
  for (int cntOn = 0; cntOn < 10; cntOn++) {
    pixel2.setPixelColor(cntOn, pixel2.Color(255,255,255));
  }
  pixel2.show();
}

void pixel3On(){
  //Turn LED Sripe ON
  for (int cntOn = 0; cntOn < 11; cntOn++) {
    pixel3.setPixelColor(cntOn, pixel3.Color(255,255,255));
  }
  pixel3.show();
}

void pixel4On(){
  //Turn LED Sripe ON
  for (int cntOn = 0; cntOn < 7; cntOn++) {
    pixel4.setPixelColor(cntOn, pixel4.Color(255,255,255));
  }
  pixel4.show();
}

void pixel5On(){
  //Turn LED Sripe ON
  for (int cntOn = 0; cntOn < 8; cntOn++) {
    pixel5.setPixelColor(cntOn, pixel5.Color(255,255,255));
  }
  pixel5.show();
}


void pixel6On(){
  //Turn LED Sripe ON
  for (int cntOn = 0; cntOn < 8; cntOn++) {
    pixel6.setPixelColor(cntOn, pixel6.Color(255,255,255));
  }
  pixel6.show();
}

void pixel1Off(){
//Turn LED Sripe OFF
  for (int cntOff = 0; cntOff < 7; cntOff++) {
    pixel1.setPixelColor(cntOff, pixel1.Color(0,0,0));
  }
  pixel1.show();
}

void pixel2Off(){
//Turn LED Sripe OFF
  for (int cntOff = 0; cntOff < 10; cntOff++) {
    pixel2.setPixelColor(cntOff, pixel2.Color(0,0,0));
  }
  pixel2.show();
}

void pixel3Off(){
//Turn LED Sripe OFF
  for (int cntOff = 0; cntOff < 11; cntOff++) {
    pixel3.setPixelColor(cntOff, pixel3.Color(0,0,0));
  }
  pixel3.show();
}

void pixel4Off(){
//Turn LED Sripe OFF
  for (int cntOff = 0; cntOff < 7; cntOff++) {
    pixel4.setPixelColor(cntOff, pixel4.Color(0,0,0));
  }
  pixel4.show();
}

void pixel5Off(){
//Turn LED Sripe OFF
  for (int cntOff = 0; cntOff < 8; cntOff++) {
    pixel5.setPixelColor(cntOff, pixel5.Color(0,0,0));
  }
  pixel5.show();
}

void pixel6Off(){
//Turn LED Sripe OFF
  for (int cntOff = 0; cntOff < 8; cntOff++) {
    pixel6.setPixelColor(cntOff, pixel6.Color(0,0,0));
  }
  pixel6.show();
}

void illuminateLED(int pin,int state){
//illuminate the PC LED
  if (state==1){
    digitalWrite(pin, HIGH);
  }
  else{
    digitalWrite(pin, LOW);
  }
}
