/*
 * indicator_7seg.c
 *
 *  Created on: 23 may 2018.
 *      Author: Sergey.S Sklyarov
 *
 *  Saratov, 2018
 */


#include "indicator_7seg.h"

uint8_t g_CurrentIndicator = 0;

Indicators_TypeDef g_ui8Indicators[INDICATORS_COUNT] =
{
  { 0x80, 0x70 }, /** set active digit, structure { PINS_LOW, PINS_HIGH } */
  { 0x40, 0xb0 },
  { 0x20, 0xd0 },
  { 0x10, 0xe0 }
};

uint8_t g_ui8Digits[10] =
{
  DIGIT0, DIGIT1, DIGIT2, DIGIT3, DIGIT4, DIGIT5, DIGIT6, DIGIT7, DIGIT8, DIGIT9
};

uint8_t g_ui8Seg[INDICATORS_COUNT];

inline void Indicator_Set (uint16_t digit)
{
  uint8_t i = 0, n = 0, tmp;

  for (i = 0; i < INDICATORS_COUNT; i++)
  {
    g_ui8Seg[i] = digit % 10;
    digit /= 10;
    n++;
  }

  for (i = 0; i < INDICATORS_COUNT; i++)
  {
    tmp = g_ui8Seg[n - i - 1];
    g_ui8Seg[n - i - 1] = g_ui8Seg[i];
    g_ui8Seg[i] = tmp;
  }
}

inline void Indicator_TimerHandler ( void )
{
  if (g_CurrentIndicator < INDICATORS_COUNT)
  {
    P2OUT &= ~g_ui8Indicators[g_CurrentIndicator].reset_bits;
    P2OUT |= g_ui8Indicators[g_CurrentIndicator].set_bits;

    P1OUT = g_ui8Digits[g_ui8Seg[g_CurrentIndicator]];

    g_CurrentIndicator++;
  }
  else
    g_CurrentIndicator = 0;
}
