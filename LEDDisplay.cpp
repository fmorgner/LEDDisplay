#include "LEDDisplay.h"

LEDDisplay::LEDDisplay(uint8_t clockPin, uint8_t latchPin, uint8_t dataPins[9])
  {
  m_nClockPin = clockPin;
  m_nLatchPin = latchPin;
  memcpy(m_anDataPins, dataPins, 9);
  
  pinMode(m_nClockPin, OUTPUT);
  pinMode(m_nLatchPin, OUTPUT);  

  for(int i = 0; i < 9; i++)
    {
    pinMode(m_anDataPins[i], OUTPUT);
    }
  }
  
void LEDDisplay::drawFrame(uint16_t anFrame[9])
  {
  if(!memcmp(m_anPreviousFrame, anFrame, 9 * sizeof(uint16_t)))
    {
    return;
    }
  
  digitalWrite(m_nLatchPin, LOW);
  
  for(int i = 0; i < 16; i++)
    {
    for(int j = 0; j < 9; j++)
      {
      digitalWrite(m_anDataPins[j], !!(anFrame[j] & (1 << (15 - i))));
      }
    digitalWrite(m_nClockPin, HIGH);
    digitalWrite(m_nClockPin, LOW);
    }
  
  digitalWrite(m_nLatchPin, HIGH);
  
  memcpy(m_anPreviousFrame, anFrame, 9 * sizeof(uint16_t));
  }

