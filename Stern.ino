/*
Sternstruktur
*/

#include <Adafruit_NeoPixel.h>

#define PC_ONE 7  
#define PC_TWO 8
#define PC_THREE 9  
#define PC_FOUR 10

#define LED_STRIPE_ONE 18  
#define LED_STRIPE_TWO 19
#define LED_STRIPE_THREE 20


// SW = SWITCH
#define SW_PC_ONE 0  
#define SW_PC_TWO 1
#define SW_PC_THREE 2 
#define SW_PC_FOUR  3

#define SW_LED_STRIPE_ONE 4
#define SW_LED_STRIPE_TWO 5
#define SW_LED_STRIPE_THREE 6


#define NUMPIXELS 5

Adafruit_NeoPixel pixel1 = Adafruit_NeoPixel(NUMPIXELS, LED_STRIPE_ONE, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixel2 = Adafruit_NeoPixel(NUMPIXELS, LED_STRIPE_TWO, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixel3 = Adafruit_NeoPixel(NUMPIXELS, LED_STRIPE_THREE, NEO_GRB + NEO_KHZ800);


void setup() {
//SWITCH
  pinMode(SW_LED_STRIPE_ONE, INPUT_PULLUP);
  pinMode(SW_LED_STRIPE_TWO, INPUT_PULLUP);
  pinMode(SW_LED_STRIPE_THREE, INPUT_PULLUP);

  pinMode(SW_PC_ONE, INPUT_PULLUP);
  pinMode(SW_PC_TWO, INPUT_PULLUP);
  pinMode(SW_PC_THREE, INPUT_PULLUP);
  pinMode(SW_PC_FOUR, INPUT_PULLUP);

//LEDS
  pinMode(LED_STRIPE_ONE,OUTPUT);
  pinMode(LED_STRIPE_TWO,OUTPUT);
  pinMode(LED_STRIPE_THREE,OUTPUT);

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
  int P1_State,P2_State,P3_State,P4_State,L1_State,L2_State,L3_State = 0;
  P1_State = digitalRead(SW_PC_ONE);
  P2_State = digitalRead(SW_PC_TWO);
  P3_State = digitalRead(SW_PC_THREE);
  P4_State = digitalRead(SW_PC_FOUR);
  L1_State = digitalRead(SW_LED_STRIPE_ONE);
  L2_State = digitalRead(SW_LED_STRIPE_TWO);
  L3_State = digitalRead(SW_LED_STRIPE_THREE);

// illuminate PCs
  illuminateLED(PC_ONE,P1_State);
  illuminateLED(PC_TWO,P2_State);
  illuminateLED(PC_THREE,P3_State);
  illuminateLED(PC_FOUR,P4_State);
  
// LED STIPE illuminate Logic
  if (P4_State==1 && P1_State==1 && L1_State==1) {
    pixel1On();
  }
  else{
    pixel1Off();
  }

  if (P4_State==1 && P2_State==1 && L2_State==1){
    pixel2On();
  }
  else{
    pixel2Off();
  }
    
  if (P4_State==1 && P3_State==1 && L3_State==1){
   pixel3On();
  }
  else{
    pixel3Off();
  }

  delay(100);
}

void pixel1On(){
  //Turn LED Sripe ON
  for (int cntOn = 0; cntOn < NUMPIXELS; cntOn++) {
    pixel1.setPixelColor(cntOn, pixel1.Color(255,255,255));
  }
  pixel1.show();
}

void pixel2On(){
  //Turn LED Sripe ON
  for (int cntOn = 0; cntOn < NUMPIXELS; cntOn++) {
    pixel2.setPixelColor(cntOn, pixel2.Color(255,255,255));
  }
  pixel2.show();
}

void pixel3On(){
  //Turn LED Sripe ON
  for (int cntOn = 0; cntOn < NUMPIXELS; cntOn++) {
    pixel3.setPixelColor(cntOn, pixel3.Color(255,255,255));
  }
  pixel3.show();
}



void pixel1Off(){
//Turn LED Sripe OFF
  for (int cntOff = 0; cntOff < NUMPIXELS; cntOff++) {
    pixel1.setPixelColor(cntOff, pixel1.Color(0,0,0));
  }
  pixel1.show();
}

void pixel2Off(){
//Turn LED Sripe OFF
  for (int cntOff = 0; cntOff < NUMPIXELS; cntOff++) {
    pixel2.setPixelColor(cntOff, pixel2.Color(0,0,0));
  }
  pixel2.show();
}

void pixel3Off(){
//Turn LED Sripe OFF
  for (int cntOff = 0; cntOff < NUMPIXELS; cntOff++) {
    pixel3.setPixelColor(cntOff, pixel3.Color(0,0,0));
  }
  pixel3.show();
}


void illuminateLED(int pin,int state){
//illuminate the PC LED
  if (state==1){
    digitalWrite(pin, HIGH);
  }  else{
    digitalWrite(pin, LOW);
  }
}
