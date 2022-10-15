#include <FastLED.h>
#define NUM_LEDS 23
#define DATA_PIN 5
#define sw_pin 0
#define BRIGHTNESS  255

CRGB leds[NUM_LEDS];
int flag=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("resetting");
  FastLED.addLeds<WS2812,DATA_PIN,RGB>(leds,NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  pinMode(sw_pin, INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  //Serial.println(digitalRead(sw_pin));
  if(digitalRead(sw_pin)!=1){
    while(digitalRead(sw_pin)!=1){
      //Serial.println("222");
      delay(10);
    }
    //Serial.println("333");
    if(flag>=6)flag=0;
    else flag++;
    Serial.println(flag);
  }
  
  while(digitalRead(sw_pin)!=0){
    //Serial.println("111");
    switch(flag){
      case 1:
        cylon();
      break;
      case 2:
        leftright(2);
        midout(2);
        //clear_led();
      break;
      case 3:
        leftright2(2);
        midout2(2);
        //clear_led();
      break;
      case 4:
        for(int i = 0; i < NUM_LEDS; i++) {
          leds[i] = CRGB(200, 255, 0);
          FastLED.show(); 
        }
        delay(50);
      break;
      case 5:
        for(int i = 0; i < NUM_LEDS; i++) {
          leds[i] = CRGB(255, 230, 255);
          FastLED.show(); 
        }
        delay(50);
      break;
      case 6:
        for(int i = 0; i < NUM_LEDS; i++) {
          leds[i] = CRGB(255, 230, 255);
          FastLED.show(); 
        }
        for(int i = NUM_LEDS/4; i < NUM_LEDS/4*2; i++) {
          leds[i] = CRGB(0, 0, 0);
          FastLED.show(); 
        }
        for(int i = NUM_LEDS/4*3; i < NUM_LEDS/4*4; i++) {
          leds[i] = CRGB(0, 0, 0);
          FastLED.show(); 
        }
        delay(50);
        
        for(int i = 0; i < NUM_LEDS; i++) {
          leds[i] = CRGB(0, 0, 0);
          FastLED.show(); 
        }
        for(int i = NUM_LEDS/4; i < NUM_LEDS/4*2; i++) {
          leds[i] = CRGB(200, 255, 0);
          FastLED.show(); 
        }
        for(int i = NUM_LEDS/4*3; i < NUM_LEDS/4*4; i++) {
          leds[i] = CRGB(200, 255, 0);
          FastLED.show(); 
        }
        delay(50);
      break;
      default:
        clear_led();
      break;
        
    }
  }

}

void clear_led(){
  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(0 , 0, 0);
    FastLED.show(); 
  }
  delay(50);
}
void cylon(){
  static uint8_t hue = 0;
  // First slide the led in one direction
  for(int i = 0; i < NUM_LEDS; i++) {
    // Set the i'th led to red 
    leds[i] = CHSV(hue++, 255, 255);
    // Show the leds
    FastLED.show(); 
    // now that we've shown the leds, reset the i'th led to black
    // leds[i] = CRGB::Black;
    for(int i = 0; i < NUM_LEDS; i++) { leds[i].nscale8(250); }
    // Wait a little bit before we loop around and do it again
    if(digitalRead(sw_pin)==0)break;
    delay(15);
  }
  //Serial.print("x");

  // Now go in the other direction.  
  for(int i = (NUM_LEDS)-1; i >= 0; i--) {
    // Set the i'th led to red 
    leds[i] = CHSV(hue++, 255, 255);
    // Show the leds
    FastLED.show();
    // now that we've shown the leds, reset the i'th led to black
    // leds[i] = CRGB::Black;
    for(int i = 0; i < NUM_LEDS; i++) { leds[i].nscale8(250); }
    // Wait a little bit before we loop around and do it again
    if(digitalRead(sw_pin)==0)break;
    delay(15);
  }
}
void leftright(int times){
  for(int k=0;k<times;k++){
    for(int j=0;j<5;j++){
      for(int i = 0; i < NUM_LEDS/2; i++) {
        leds[i] = CRGB(200, 255, 0);
        FastLED.show(); 
      }
      for(int i = 0; i < NUM_LEDS; i++) {
        leds[i] = CRGB(0 , 0, 0);
        FastLED.show(); 
      }
      if(digitalRead(sw_pin)==0)break;
      delay(20);
    }
    if(digitalRead(sw_pin)==0)break;
    for(int j=0;j<5;j++){
      for(int i = NUM_LEDS/2; i < NUM_LEDS; i++) {
      leds[i] = CRGB(255, 230, 255);
      FastLED.show(); 
    }
      for(int i = 0; i < NUM_LEDS; i++) {
        leds[i] = CRGB(0 , 0, 0);
        FastLED.show(); 
      }
      if(digitalRead(sw_pin)==0)break;
      delay(20);
    }
    if(digitalRead(sw_pin)==0)break;
    for(int j=0;j<5;j++){
      for(int i = 0; i < NUM_LEDS/2; i++) {
      leds[i] = CRGB(255, 230, 255);
      FastLED.show(); 
    }
      for(int i = 0; i < NUM_LEDS; i++) {
        leds[i] = CRGB(0 , 0, 0);
        FastLED.show(); 
      }
      if(digitalRead(sw_pin)==0)break;
      delay(20);
    }
    if(digitalRead(sw_pin)==0)break;
    for(int j=0;j<5;j++){
      for(int i = NUM_LEDS/2; i < NUM_LEDS; i++) {
        leds[i] = CRGB(200, 255, 0);
        FastLED.show(); 
      }
      for(int i = 0; i < NUM_LEDS; i++) {
        leds[i] = CRGB(0 , 0, 0);
        FastLED.show(); 
      }
      if(digitalRead(sw_pin)==0)break;
      delay(20);
    }
    if(digitalRead(sw_pin)==0)break;
  }
}
void midout(int times){
  for(int k=0;k<times;k++){
   for(int j=0;j<5;j++){
      for(int i = 0; i < NUM_LEDS/3; i++) {
        leds[i] = CRGB(200, 255, 0);
        FastLED.show(); 
      }
      for(int i = NUM_LEDS/3*2; i < NUM_LEDS; i++) {
        leds[i] = CRGB(200, 255, 0);
        FastLED.show(); 
      }
      for(int i = 0; i < NUM_LEDS; i++) {
        leds[i] = CRGB(0 , 0, 0);
        FastLED.show(); 
      }
      if(digitalRead(sw_pin)==0)break;
      delay(20);
    }
    if(digitalRead(sw_pin)==0)break;
    for(int j=0;j<5;j++){
      for(int i = NUM_LEDS/3; i < NUM_LEDS/3*2; i++) {
      leds[i] = CRGB(255, 230, 255);
      FastLED.show(); 
    }
      for(int i = 0; i < NUM_LEDS; i++) {
        leds[i] = CRGB(0 , 0, 0);
        FastLED.show(); 
      }
      if(digitalRead(sw_pin)==0)break;
      delay(20);
    }
    if(digitalRead(sw_pin)==0)break;
    for(int j=0;j<5;j++){
      for(int i = 0; i < NUM_LEDS/3; i++) {
        leds[i] = CRGB(255, 230, 255);
        FastLED.show(); 
      }
      for(int i = NUM_LEDS/3*2; i < NUM_LEDS; i++) {
        leds[i] = CRGB(255, 230, 255);
        FastLED.show(); 
      }
      for(int i = 0; i < NUM_LEDS; i++) {
        leds[i] = CRGB(0 , 0, 0);
        FastLED.show(); 
      }
      if(digitalRead(sw_pin)==0)break;
      delay(20);
    }
    if(digitalRead(sw_pin)==0)break;
    for(int j=0;j<5;j++){
      for(int i = NUM_LEDS/3; i < NUM_LEDS/3*2; i++) {
      leds[i] = CRGB(200, 255, 0);
      FastLED.show(); 
    }
      for(int i = 0; i < NUM_LEDS; i++) {
        leds[i] = CRGB(0 , 0, 0);
        FastLED.show(); 
      }
      if(digitalRead(sw_pin)==0)break;
      delay(20);
    }
    if(digitalRead(sw_pin)==0)break;
  }
}
void leftright2(int times){
  for(int k=0;k<times;k++){
    for(int j=0;j<5;j++){
      for(int i = 0; i < NUM_LEDS/2; i++) {
        leds[i] = CRGB(200, 255, 0);
        FastLED.show(); 
      }
      for(int i = 0; i < NUM_LEDS; i++) {
        leds[i] = CRGB(0 , 0, 0);
        FastLED.show(); 
      }
      if(digitalRead(sw_pin)==0)break;
      delay(20);
    }
    if(digitalRead(sw_pin)==0)break;
    for(int j=0;j<5;j++){
      for(int i = NUM_LEDS/2; i < NUM_LEDS; i++) {
      leds[i] = CRGB(200, 255, 0);
      FastLED.show(); 
    }
      for(int i = 0; i < NUM_LEDS; i++) {
        leds[i] = CRGB(0 , 0, 0);
        FastLED.show(); 
      }
      if(digitalRead(sw_pin)==0)break;
      delay(20);
    }
    if(digitalRead(sw_pin)==0)break;
    for(int j=0;j<5;j++){
      for(int i = 0; i < NUM_LEDS/2; i++) {
      leds[i] = CRGB(200, 255, 0);
      FastLED.show(); 
    }
      for(int i = 0; i < NUM_LEDS; i++) {
        leds[i] = CRGB(0 , 0, 0);
        FastLED.show(); 
      }
      if(digitalRead(sw_pin)==0)break;
      delay(20);
    }
    if(digitalRead(sw_pin)==0)break;
    for(int j=0;j<5;j++){
      for(int i = NUM_LEDS/2; i < NUM_LEDS; i++) {
        leds[i] = CRGB(200, 255, 0);
        FastLED.show(); 
      }
      for(int i = 0; i < NUM_LEDS; i++) {
        leds[i] = CRGB(0 , 0, 0);
        FastLED.show(); 
      }
      if(digitalRead(sw_pin)==0)break;
      delay(20);
    }
    if(digitalRead(sw_pin)==0)break;
  }
}
void midout2(int times){
  for(int k=0;k<times;k++){
   for(int j=0;j<5;j++){
      for(int i = 0; i < NUM_LEDS/3; i++) {
        leds[i] = CRGB(200, 255, 0);
        FastLED.show(); 
      }
      for(int i = NUM_LEDS/3*2; i < NUM_LEDS; i++) {
        leds[i] = CRGB(200, 255, 0);
        FastLED.show(); 
      }
      for(int i = 0; i < NUM_LEDS; i++) {
        leds[i] = CRGB(0 , 0, 0);
        FastLED.show(); 
      }
      if(digitalRead(sw_pin)==0)break;
      delay(20);
    }
    if(digitalRead(sw_pin)==0)break;
    for(int j=0;j<5;j++){
      for(int i = NUM_LEDS/3; i < NUM_LEDS/3*2; i++) {
      leds[i] = CRGB(200, 255, 0);
      FastLED.show(); 
    }
      for(int i = 0; i < NUM_LEDS; i++) {
        leds[i] = CRGB(0 , 0, 0);
        FastLED.show(); 
      }
      if(digitalRead(sw_pin)==0)break;
      delay(20);
    }
    if(digitalRead(sw_pin)==0)break;
    for(int j=0;j<5;j++){
      for(int i = 0; i < NUM_LEDS/3; i++) {
        leds[i] = CRGB(200, 255, 0);
        FastLED.show(); 
      }
      for(int i = NUM_LEDS/3*2; i < NUM_LEDS; i++) {
        leds[i] = CRGB(200, 255, 0);
        FastLED.show(); 
      }
      for(int i = 0; i < NUM_LEDS; i++) {
        leds[i] = CRGB(0 , 0, 0);
        FastLED.show(); 
      }
      if(digitalRead(sw_pin)==0)break;
      delay(20);
    }
    if(digitalRead(sw_pin)==0)break;
    for(int j=0;j<5;j++){
      for(int i = NUM_LEDS/3; i < NUM_LEDS/3*2; i++) {
      leds[i] = CRGB(200, 255, 0);
      FastLED.show(); 
    }
      for(int i = 0; i < NUM_LEDS; i++) {
        leds[i] = CRGB(0 , 0, 0);
        FastLED.show(); 
      }
      if(digitalRead(sw_pin)==0)break;
      delay(20);
    }
    if(digitalRead(sw_pin)==0)break;
  }
}
