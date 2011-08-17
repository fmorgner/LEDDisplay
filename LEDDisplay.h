#ifndef __LEDDISPLAY_H
#define __LEDDISPLAY_H

#include "WProgram.h"

class LEDDisplay
  {
  public:
    LEDDisplay(uint8_t clockPin, uint8_t latchPin, uint8_t dataPins[9]);
    void drawFrame(uint16_t anFrame[9]);

  protected:
    uint8_t m_nClockPin;
    uint8_t m_nLatchPin;
    uint8_t m_anDataPins[9];
    uint16_t m_anPreviousFrame[9];
  };

#endif
