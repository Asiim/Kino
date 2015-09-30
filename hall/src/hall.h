#ifndef _HALL_H
#define _HALL_H
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>

HALL room[4];

typedef struct hall
{
  char** place;
}HALL;

HALL initHall(int i);

#endif
