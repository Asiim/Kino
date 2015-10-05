#ifndef _MOVIE_H
#define _MOVIE_H
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#define MAX_NAME_LENGTH 20
#define MAX_TERMIN_LENGTH 5
#define NUMBER_OF_HALLS 4

typedef struct movie
{
  char name[MAX_NAME_LENGTH];
  char* termin[MAX_TERMIN_LENGTH];
  uint8_t hall[NUMBER_OF_HALLS];
} MOVIE;

MOVIE* initMovie();
int insertName(MOVIE*,char*);
int insertTermin(MOVIE*,char*);
#endif
