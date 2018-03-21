
#include <Adafruit_NeoPixel.h>

const int pixelLength=14;
const int pin=6;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(pixelLength, pin, NEO_GRB + NEO_KHZ800);
void setup() {
  // put your setup code here, to run once:
  strip.begin();
  strip.show();

}

void loop() {
  // put your main code here, to run repeatedly:
  
  cascadeBlue();
  cascadeGreen();
}

void  red(){
  for (int i=0;i<pixelLength;i++){
    strip.setPixelColor(i,144,0,0);
  }
  strip.show();
}

void green(){
  for (int i=0;i<pixelLength;i++){
    strip.setPixelColor(i,0,144,0);
  }
  strip.show();
}
void blue(){
  for (int i=0;i<pixelLength;i++){
    strip.setPixelColor(i,0,0,144);
  }
  strip.show();
  
}

void cascadeRed(){//do not use; idk where this came from
  for  (int i=0;i<pixelLength;i++){
    strip.setPixelColor(i,255,0,0);
    if(i > 5){
      strip.setPixelColor(i - 5, 255, 0, 0);
    }
    strip.show();
    delay(25);
  }
}

void cascadeGreen(){
  for  (int i=0;i<100;i++){//runs for 5 seconds
    strip.setPixelColor((i+2)%pixelLength,0,100,0);
    strip.setPixelColor((i+1)%pixelLength,0,100,0);
    strip.setPixelColor(i,0,100,0);
    strip.setPixelColor((i-1)%pixelLength,100,0,0);
    strip.show();
    delay(50);
  }
}

void cascadeBlue(){
  for  (int i=0;i<100;i++){//runs for 5 seconds
    strip.setPixelColor((i+2)%pixelLength,0,0,100);
    strip.setPixelColor((i+1)%pixelLength,0,0,100);
    strip.setPixelColor(i,0,0,100);
    strip.setPixelColor((i-1)%pixelLength,100,0,0);
    strip.show();
    delay(50);
  }
}

/*void cascadeRGB(int cycles){ //never tested seems bad 
  for  (int i=0;i<(pixelLength)*cycles;i++){
    strip.setPixelColor(i%pixelLength,255,0,0);
    if(i > 5){
      strip.setPixelColor((i - 5)%pixelLength, 255, 0, 0);
    }
    strip.setPixelColor((i + 20)%pixelLength,255,0,0);
      strip.setPixelColor((i - 5)%pixelLength, 255, 0, 0);
    strip.setPixelColor(i%pixelLength,255,0,0);
    if(i > 5){
      strip.setPixelColor((i - 5)%pixelLength, 255, 0, 0);
    }
    
    strip.show();
    delay(25);
  }
  
}*/
void cascadeGeneral(unit32_t primaryColor, unit32_t backgroundColor){
  for  (int i=0;i<100;i++){//runs for 5 seconds
    strip.setPixelColor((i+2)%pixelLength,primaryColor);
    strip.setPixelColor((i+1)%pixelLength,primaryColor);
    strip.setPixelColor(i,primaryColor);
    strip.setPixelColor((i-1)%pixelLength,backgroundColor);
    strip.show();
    delay(50);
  }
}

void off(){
  for (int i=0;i<pixelLength;i++){
    strip.setPixelColor(i,0,0,0);
  }
  strip.show();
}

