#ifndef _COUNTER_H
#define _COUNTER_H
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>
#include "../../movie/src/movie.h"
#include "../../hall/src/hall.h"
#define MAX_CARDS 50

typedef struct counter
{
  MOVIE *array;
  uint8_t numberOfCards;
  uint8_t* places;
}COUNTER;

COUNTER mainCounter;

COUNTER initCounter();
int8_t takeCards(int8_t);

#endif
