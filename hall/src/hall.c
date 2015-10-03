#include "hall.h"

void initHall()
{
  freeAllPlaces();
}

void takeOnePlace(uint8_t room,uint8_t row,uint8_t column)
{
  hall[room][row][column]=TAKEN;
}

void takeAllPlaces()
{
  int hall,row,column;
  for(hall=0;hall<4;hall++)
    for(row=0;row<10;row++)
      for(column=0;column<12;column++)
        takeOnePlace(hall,row,column);
}

void freeOnePlace(uint8_t room,uint8_t row,uint8_t column)
{
  hall[room][row][column]=FREE;
}

void freeAllPlaces()
{
      int hall,row,column;
      for(hall=0;hall<4;hall++)
        for(row=0;row<10;row++)
          for(column=0;column<12;column++)
            freeOnePlace(hall,row,column);
}
