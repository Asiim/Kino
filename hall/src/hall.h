#ifndef _HALL_H
#define _HALL_H
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>
#define MAX_HALLS 4
#define MAX_ROWS 10
#define MAX_COLUMNS 12
#define TAKEN 'x'
#define FREE 'O'

char hall[MAX_HALLS][MAX_ROWS][MAX_COLUMNS];

void initHall();
void takeOnePlace(uint8_t,uint8_t,uint8_t);
void takeAllPlaces();
void freeOnePlace(uint8_t,uint8_t,uint8_t);
void freeAllPlaces();

#endif
