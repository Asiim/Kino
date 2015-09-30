#ifndef _COUNTER_H
#define _COUNTER_H
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>

COUNTER mainCounter;

typedef struct counter
{
  MOVIE *array;
  uint8_t numberOfCards;
  uint8_t* places;
}COUNTER;

COUNTER initCounter();

#endif
