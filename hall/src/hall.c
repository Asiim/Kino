#include "hall.h"

static int random2(int i)
{
  time_t t;
  srand((unsigned) time(&t));
  return rand()%i;
}

static void randomPlace(char a)
{
  hall[random2(MAX_HALLS)].chair[random2(MAX_ROWS)][random2(MAX_COLUMNS)]=a;
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

static void takePlaces(int8_t n,int8_t row, int8_t column,int8_t room)
{
  int8_t checkedplace=0,place;
  for(place=0;place<n;place++)
  {
    takeOnePlace(room,row,column+place-checkedplace);
    if (column+place==MAX_COLUMNS)
    {
      column=0;
      row++;
      checkedplace+=place;
    }
  }
}

static void freePlaces(int8_t n,int8_t row, int8_t column,int8_t room)
{
  int8_t checkedplace=0,place;
  for(place=0;place<n;place++)
  {
    freeOnePlace(room,row,column+place-checkedplace);
    if (column+place==MAX_COLUMNS)
    {
      column=0;
      row++;
      checkedplace+=place;
    }
  }
}

static int8_t placesAreFree(int8_t n,int8_t row, int8_t column,int8_t room)
{
  int8_t suma,checkedplace,place;
  for(suma=0,checkedplace=0,place=0;place<n;place++)
  {
    if (column+place==MAX_COLUMNS && suma==0)
    {
      column=0;
      row++;
      checkedplace+=place;
    }
    if (column+place-checkedplace<MAX_COLUMNS)
    {
      if(hall[room].chair[row][column+place-checkedplace]==FREE)
      suma+=0;
      else
      suma+=1;
    }
  }
  if(suma==0 && place==n)
  return 1;
  else
  return 0;
}

static int8_t placesAreTaken(int8_t n,int8_t row, int8_t column,int8_t room)
{
  int8_t suma,checkedplace,place;
  for(suma=0,checkedplace=0,place=0;place<n;place++)
  {
    if (column+place==MAX_COLUMNS && suma==0)
    {
      column=0;
      row++;
      checkedplace+=place;
    }
    if (column+place-checkedplace<MAX_COLUMNS)
    {
      if(hall[room].chair[row][column+place-checkedplace]==TAKEN)
      suma+=0;
      else
      suma+=1;
    }
  }
  if(suma==0 && place==n)
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
  if (hall[room].chair[row][column]==TAKEN)
  {
    return 1;
  }
  else
  {
    hall[room].chair[row][column]=TAKEN;
    return 0;
  }
}

void takeAllPlaces()
{
  int room,row,column;
  for(room=0;room<MAX_HALLS;room++)
    for(row=0;row<MAX_ROWS;row++)
      for(column=0;column<MAX_COLUMNS;column++)
        takeOnePlace(room,row,column);
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
  if (hall[room].chair[row][column]==FREE)
  {
    return 1;
  }
  else
  {
    hall[room].chair[row][column]=FREE;
    return 0;
  }
}

void freeAllPlaces()
{
      int room,row,column;
      for(room=0;room<MAX_HALLS;room++)
        for(row=0;row<MAX_ROWS;row++)
          for(column=0;column<MAX_COLUMNS;column++)
            freeOnePlace(room,row,column);
}

void takeRandomPlace()
{
  randomPlace(TAKEN);
}

void freeRandomPlace()
{
    randomPlace(FREE);
}

int8_t takeMorePlaces(int8_t n)
{
      int8_t room,row,column;
      for(room=0;room<MAX_HALLS;room++)
        for(row=0;row<MAX_ROWS;row++)
          for(column=0;column<MAX_COLUMNS;column++)
          {
            if (placesAreFree(n,row,column,room))
            {
              takePlaces(n,row,column,room);
              return 0;
            }
          }
      return 1;
}

int8_t freeMorePlaces(int8_t n)
{
      int8_t room,row,column,place,suma,checkedplace,row1,column1;
      for(room=0;room<MAX_HALLS;room++)
        for(row=0;row<MAX_ROWS;row++)
          for(column=0;column<MAX_COLUMNS;column++)
          {
            if (placesAreTaken(n,row,column,room))
            {
              takePlaces(n,row,column,room);
              return 0;
            }
          }
      return 1;
}
