#include <LEDDisplay.h>

uint8_t latchPin = 8;
uint8_t dataPin = 9;
uint8_t clockPin = 10;

uint16_t frame[9] = {1, 0, 0, 0, 0, 0, 0, 0, 0};

LEDDisplay* ledDisplay;

void* operator new(size_t size) { return malloc(size); }
void operator delete(void* ptr) { free(ptr); } 

void setup()
  {
  uint8_t dataPins[9] = {9, 1, 2, 3, 4, 5, 6, 7, 11};
  ledDisplay = new LEDDisplay(clockPin, latchPin, dataPins);
  }

void loop()
  {
  ledDisplay->drawFrame(frame);
  }

