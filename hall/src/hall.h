#ifndef _HALL_H
#define _HALL_H
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>

char hall[4][10][12];

void initHall();
void takeOnePlace(uint8_t,uint8_t,uint8_t);
void takeAllPlaces();
void freeOnePlace(uint8_t,uint8_t,uint8_t);
void freeAllPlaces();
#endif
