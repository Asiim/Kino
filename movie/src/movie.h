#ifndef _MOVIE_H
#define _MOVIE_H
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>


typedef struct movie
{
  char name[20];
  char* termin[6];
  uint8_t hall[4];
} MOVIE;

MOVIE* initMovie();
#endif
