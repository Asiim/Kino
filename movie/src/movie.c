#include "movie.h"

static int8_t ifFormatIsRight(char* termin)
{
  if (termin[0]>='0' && termin[0]<='2' && termin[1]>='0' && termin[1]<='9' && termin[2]==':' && termin[3]>='0' && termin[3]<='5' && termin[4]>='0' && termin[4]<='9')
  return 1;
  else
  return 0;
}

static int8_t ifTerminIsOutOfBound(char* termin)
{
  if (strcmp(termin,"00:00")>=0 && strcmp(termin,"12:00")<=0 || strcmp(termin,"24:00")>=0)
  return 1;
  else
  return 0;
}

static int8_t emptyTermin(char* termin)
{
  if(strcmp(termin,""))
  return 0;
  else
  return 1;
}

static int8_t emptyName(char* name)
{
  if(strcmp(name,""))
  return 0;
  else
  return 1;
}

static int8_t nameToLong(char* name)
{
  if (strlen(name)>(MAX_NAME_LENGTH-1))
  return 1;
  else
  return 0;
}

static int8_t hallIsOutOfBound(int8_t hall)
{
  if(hall>=4 || hall<0)
    return 1;
  else
    return 0;
}

static int8_t hallIstaken(MOVIE* movie,int8_t hall)
{
  if(movie->hall == hall)
    return 1;
  else
    return 0;
}

MOVIE* initMovie()
{
  return (MOVIE*)malloc (sizeof(MOVIE));
}

int8_t insertName(MOVIE* movie, char* name)
{
  if (emptyName(name))
  {
    printf("ERROR: Can't put empty name!");
    return 1;
  }
  else
  if (nameToLong(name))
  {
    strncpy(movie->name,name,MAX_NAME_LENGTH-1);
    return 0;
  }
  else
  strcpy(movie->name,name);
  return 0;
}

int8_t insertTermin(MOVIE* movie,char* termin)
{
  if (emptyTermin(termin))
  {
    printf("You didnt enter a termin, please try again.");
    return 1;
  }
  else
  if (ifFormatIsRight(termin))
  {
    if (ifTerminIsOutOfBound(termin))
    {
      return 2;
    }
    else
    {
      strcpy(movie->termin, termin);
      return 0;
    }
  }
  else
  {
    return 3;
  }
}

int8_t insertHall(MOVIE* movie,int8_t hall)
{
  if (hallIsOutOfBound(hall))
  {
    return 1;
  }
  else
  {
    movie->hall=hall;
  }
  if (hallIstaken(movie,hall))
    return 0;
  else
    return 2;
}
