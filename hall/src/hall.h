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

//char hall[MAX_HALLS][MAX_ROWS][MAX_COLUMNS];

typedef struct room
{
    char chair[MAX_ROWS][MAX_COLUMNS];
    uint8_t hallIsTaken;
} ROOM;

ROOM hall[MAX_HALLS];

void initHall();
int8_t takeOnePlace(uint8_t,uint8_t,uint8_t);
void takeAllPlaces();
int8_t freeOnePlace(uint8_t,uint8_t,uint8_t);
void freeAllPlaces();
void takeRandomPlace();
void freeRandomPlace();
int8_t takeMorePlaces(int8_t);
int8_t freeMorePlaces(int8_t);

#endif
