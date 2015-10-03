#include "hall.h"

static int random2()
{
  time_t t;
  srand((unsigned) time(&t));
  return rand();
}

static int8_t roomOutOfBound(uint8_t room)
{
  if(room>=MAX_HALLS || room<0)
  return 1;
  else
  return 0;
}

static int8_t rowOutOfBound(uint8_t row)
{
  if(row>=MAX_ROWS || row<0)
  return 1;
  else
  return 0;
}

static int8_t columnOutOfBound(uint8_t column)
{
  if(column>=MAX_COLUMNS || column<0)
  return 1;
  else
  return 0;
}

void initHall()
{
  freeAllPlaces();
}

void takeOnePlace(uint8_t room,uint8_t row,uint8_t column)
{
  if (roomOutOfBound(room))
  {
    room=random2()%4;
    printf("room=%" PRIu8 "",room);
  }
  if(rowOutOfBound(row))
  {
    row=random2()%10;
    printf("row=%" PRIu8 "",row);
  }
  if(columnOutOfBound(column))
  {
      column=random2()%12;
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
  if (roomOutOfBound(room))
  {
    room=random2()%4;
    printf("room=%" PRIu8 "",room);
  }
  if(rowOutOfBound(row))
  {
    row=random2()%10;
    printf("row=%" PRIu8 "",row);
  }
  if(columnOutOfBound(column))
  {
      column=random2()%12;
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
