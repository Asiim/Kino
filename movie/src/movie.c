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
