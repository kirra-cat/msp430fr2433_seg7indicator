/*
 * indicator_7seg.h
 *
 *  Created on: 23 may 2018.
 *      Author: Sergey.S Sklyarov
 *
 *  Saratov, 2018
 */

#ifndef INDICATOR_7SEG_H_
#define INDICATOR_7SEG_H_

#include <stdint.h>
#include <math.h>

#include <msp430fr2433.h>

#define INDICATORS_COUNT                       4

/**                    A
 *                   =====
 * P1.0 - "A"      ||     ||
 * P1.1 - "B"    F ||     || B
 * P1.2 - "C"      ||  G  ||
 * P1.3 - "D"        =====
 * P1.4 - "E"      ||     ||
 * P1.5 - "F"    E ||     || C
 * P1.6 - "G"      ||  D  ||
 * P1.7 - "DP"       =====    * DP
 */

#define DIGIT0                                 0x3f
#define DIGIT1                                 0x06
#define DIGIT2                                 0x5b
#define DIGIT3                                 0x4f
#define DIGIT4                                 0x66
#define DIGIT5                                 0x6d
#define DIGIT6                                 0x7d
#define DIGIT7                                 0x07
#define DIGIT8                                 0x7f
#define DIGIT9                                 0x6f

typedef struct
{
  uint8_t reset_bits;
  uint8_t set_bits;
} Indicators_TypeDef;

void Indicator_Set ( uint16_t digit );

void Indicator_TimerHandler ( void );

#endif /* INDICATOR_7SEG_H_ */
