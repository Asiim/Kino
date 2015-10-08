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
  uint8_t currentMovie;
} MOVIE;

MOVIE* movies;
MOVIE* currentMovies;

MOVIE* initMovie();
int8_t insertName(char*);
int8_t insertTermin(char*);
int8_t insertHall(int8_t);
void freeMovie();
MOVIE* initMoreMovies(int8_t);
void listMovies();
void nextMovie();
void prevMovie();
int8_t takeMovie(char*);
int8_t takeTermin(char*);

#endif
