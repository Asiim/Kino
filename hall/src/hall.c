#include "hall.h"

void initHall()
{
  freeAllPlaces();
}

void takeOnePlace(uint8_t room,uint8_t row,uint8_t column)
{
  hall[room][row][column]='x';
}

void takeAllPlaces()
{
    int i,j,k;
    for(i=0;i<4;i++)
      for(j=0;j<10;j++)
        for(k=0;k<12;k++)
          takeOnePlace(i,j,k);
}

void freeOnePlace(uint8_t room,uint8_t row,uint8_t column)
{
  hall[room][row][column]='O';
}

void freeAllPlaces()
{
      int i,j,k;
      for(i=0;i<4;i++)
        for(j=0;j<10;j++)
          for(k=0;k<12;k++)
            freeOnePlace(i,j,k);
}
