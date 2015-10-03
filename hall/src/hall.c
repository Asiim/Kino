#include "hall.h"

void initHall()
{
  freeAllPlaces();
}

void takeOnePlace(uint8_t room,uint8_t row,uint8_t column)
{
  if (room>=MAX_HALLS || room<0)
  {
    time_t t;
    srand((unsigned) time(&t));
    room=rand()%4;
    printf("room=%" PRIu8 "",room);
  }
  if(row>=MAX_ROWS || room<0)
  {
    time_t t;
    srand((unsigned) time(&t));
    row=rand()%10;
    printf("row=%" PRIu8 "",row);
  }
  if(column>=MAX_COLUMNS || column<0)
  {
      time_t t;
      srand((unsigned) time(&t));
      column=rand()%12;
      printf("column=%" PRIu8 "",column);
  }
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
  if (room>=MAX_HALLS || room<0)
  {
    time_t t;
    srand((unsigned) time(&t));
    room=rand()%4;
    printf("room=%" PRIu8 "",room);
  }
  if(row>=MAX_ROWS || room<0)
  {
    time_t t;
    srand((unsigned) time(&t));
    row=rand()%10;
    printf("row=%" PRIu8 "",row);
  }
  if(column>=MAX_COLUMNS || column<0)
  {
      time_t t;
      srand((unsigned) time(&t));
      column=rand()%12;
      printf("column=%" PRIu8 "",column);
  }
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
