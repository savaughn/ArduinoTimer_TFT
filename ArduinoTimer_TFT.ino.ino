#define LCD_CS A3 // Chip Select goes to Analog 3
#define LCD_CD A2 // Command/Data goes to Analog 2
#define LCD_WR A1 // LCD Write goes to Analog 1
#define LCD_RD A0 // LCD Read goes to Analog 0
#define LCD_RESET A4 // Can alternately just connect to Arduino's reset pin

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
  tft.setTextSize(8);
  tft.setTextWrap(false);
  timeStart = millis();  
  

}

void loop() {
 
  tft.setCursor(45, 95);
  currentTime = millis() - timeStart;
  tft.print(currentTime);

}
