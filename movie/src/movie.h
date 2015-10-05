#ifndef _MOVIE_H
#define _MOVIE_H
#include "../../hall/src/hall.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#define MAX_NAME_LENGTH 20
#define MAX_TERMIN_LENGTH 5

typedef struct movie
{
  char name[MAX_NAME_LENGTH];
  char* termin[MAX_TERMIN_LENGTH];
  uint8_t hall;
  uint8_t numberOfMovies;
} MOVIE;

MOVIE* initMovie(MOVIE**);
int8_t insertName(MOVIE*,char*);
int8_t insertTermin(MOVIE*,char*);
int8_t insertHall(MOVIE*,int8_t);
void freeMovie(MOVIE**);
MOVIE* initMoreMovies(MOVIE**,int8_t);

#endif
