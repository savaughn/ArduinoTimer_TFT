#define tft_CS A3 // Chip Select goes to Analog 3
#define tft_CD A2 // Command/Data goes to Analog 2
#define tft_WR A1 // tft Write goes to Analog 1
#define tft_RD A0 // tft Read goes to Analog 0
#define tft_RESET A4 // Can alternately just connect to Arduino's reset pin

#include <SPI.h>          // f.k. for Arduino-1.5.2
#include "Adafruit_GFX.h"// Hardware-specific library
#include <MCUFRIEND_kbv.h>

MCUFRIEND_kbv tft;
// Assign human-readable names to some common 16-bit color values:
#define    BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

int width = tft.width();
  int height = tft.height(); 
  
  unsigned long currentTime;
  unsigned long timeStart;

void setup() {
  int ID = tft.readID();
  tft.begin(ID);
  tft.setRotation(3);
  tft.fillScreen(BLUE);
  tft.setTextColor(GREEN, BLUE);  
  tft.setTextSize(5);
  tft.setTextWrap(false);
  timeStart = millis(); 
}

void printTimer(unsigned long printTime){

  unsigned long ms = printTime%1000;
  int s = (printTime/1000)%60;
  int m = (printTime/60000)%60;

  tft.setCursor(210, 95);
  tft.print( ms );
  if (s < 10){
    tft.setCursor(126, 95);
    tft.print(0);
  }
  else
    tft.setCursor(126, 95);
  tft.print( s );
  tft.setCursor(180, 95);
  tft.print(":");

  if(m < 10){
    tft.setCursor(40, 95);
    tft.print(0);      
  }
  else
    tft.setCursor(81, 95);
  tft.print(m);
  tft.setCursor(96, 95);
  tft.print(":");

}

void loop() {
 
  tft.setCursor(45, 95);
  currentTime = millis() - timeStart;
  printTimer(currentTime);

}
