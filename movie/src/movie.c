#include "movie.h"

MOVIE* initMovie()
{
  return (MOVIE*)malloc (sizeof(MOVIE));
}

int insertName(MOVIE* movie, char* name)
{
  if (!strcmp(name,""))
  {
    printf("ERROR: Can't put empty name!");
    return 1;
  }
  else
  if (strlen(name)>19)
  {
    strncpy(movie->name,name,19);
    return 0;
  }
  else
  strcpy(movie->name,name);
  return 0;
}

int insertTermin(MOVIE* movie,char* termin)
{
  if (!strcmp(termin,""))
  {
    printf("You didnt enter a termin, please try again.");
    return 1;
  }
  else
  if (termin[0]>='0' && termin[0]<='2' && termin[1]>='0' && termin[1]<='9' && termin[2]==':' && termin[3]>='0' && termin[3]<='5' && termin[4]>='0' && termin[4]<='9')
  {
    if (strcmp(termin,"00:00")>=0 && strcmp(termin,"12:00")<=0 || strcmp(termin,"24:00")>=0)
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
