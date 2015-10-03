#include "hall.h"

static int random2(int i)
{
  time_t t;
  srand((unsigned) time(&t));
  return rand()%i;
}

static void randomPlace(char a)
{
  hall[random2(MAX_HALLS)][random2(MAX_ROWS)][random2(MAX_COLUMNS)]=a;
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

int8_t takeOnePlace(uint8_t room,uint8_t row,uint8_t column)
{
  if (roomOutOfBound(room))
  {
    room=random2(MAX_HALLS);
    printf("room=%" PRIu8,room);
  }
  if(rowOutOfBound(row))
  {
    row=random2(MAX_ROWS);
    printf("row=%" PRIu8,row);
  }
  if(columnOutOfBound(column))
  {
      column=random2(MAX_COLUMNS);
      printf("column=%" PRIu8,column);
  }
  if (hall[room][row][column]==TAKEN)
  {
    return 1;
  }
  else
  {
    hall[room][row][column]=TAKEN;
    return 0;
  }
}

void takeAllPlaces()
{
  int hall,row,column;
  for(hall=0;hall<MAX_HALLS;hall++)
    for(row=0;row<MAX_ROWS;row++)
      for(column=0;column<MAX_COLUMNS;column++)
        takeOnePlace(hall,row,column);
}

int8_t freeOnePlace(uint8_t room,uint8_t row,uint8_t column)
{
  if (roomOutOfBound(room))
  {
    room=random2(MAX_HALLS);
    printf("room=%" PRIu8,room);
  }
  if(rowOutOfBound(row))
  {
    row=random2(MAX_ROWS);
    printf("row=%" PRIu8,row);
  }
  if(columnOutOfBound(column))
  {
      column=random2(MAX_COLUMNS);
      printf("column=%" PRIu8,column);
  }
  if (hall[room][row][column]==FREE)
  {
    return 1;
  }
  else
  {
    hall[room][row][column]=FREE;
    return 0;
  }
}

void freeAllPlaces()
{
      int hall,row,column;
      for(hall=0;hall<MAX_HALLS;hall++)
        for(row=0;row<MAX_ROWS;row++)
          for(column=0;column<MAX_COLUMNS;column++)
            freeOnePlace(hall,row,column);
}


void takeRandomPlace()
{
  randomPlace(TAKEN);
}
void freeRandomPlace()
{
    randomPlace(FREE);
}
