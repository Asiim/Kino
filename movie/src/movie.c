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
  if (strcmp(termin,"00:00")>0 && strcmp(termin,"12:00")<0 || strcmp(termin,"24:00")>=0)
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

static int8_t hallIstaken(int8_t hall)
{
  if((movies+movies->currentMovie)->hall == hall)
    return 1;
  else
    return 0;
}

static int8_t noMovie()
{
  if(movies==NULL || movies->numberOfMovies==0)
  return 1;
  else
  return 0;
}


MOVIE* initMovie()
{
  if (noMovie())
  {
    movies=(MOVIE*)malloc(sizeof(MOVIE));
    movies->numberOfMovies=1;
    movies->currentMovie=0;
  }
  else
  if (!noMovie())
  {
      movies->numberOfMovies++;
      movies=(MOVIE*)realloc(movies,movies->numberOfMovies*sizeof(MOVIE));
  }
  if (movies!=NULL)
  {
      return movies;
  }
  else
  {
      return -123;
  }
}

int8_t insertName(char* name)
{
  if (emptyName(name))
  {
    return 1;
  }
  else
  if (nameToLong(name))
  {
    strncpy((movies+movies->currentMovie)->name,name,MAX_NAME_LENGTH-1);
    return 0;
  }
  else
  strcpy((movies+movies->currentMovie)->name,name);
  return 0;
}

int8_t insertTermin(char* termin)
{
  if (emptyTermin(termin))
  {
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
      strcpy((movies+movies->currentMovie)->termin, termin);
      return 0;
    }
  }
  else
  {
    return 3;
  }
}

int8_t insertHall(int8_t hall)
{
  if (hallIsOutOfBound(hall))
  {
    return 1;
  }
  else
  {
    (movies+movies->currentMovie)->hall=hall;
  }
  if (hallIstaken(hall))
    return 0;
  else
    return 2;
}

void freeMovie()
{
  movies->numberOfMovies=0;
  movies->currentMovie=0;
  free (movies);
}

MOVIE* initMoreMovies(int8_t number)
{
  int i;
  for(i=0;i<number;i++)
  {
    initMovie();
  }
}

void listMovies()
{
  int8_t i;
  for (i=0;i<movies->numberOfMovies;i++)
    printf("Movie %"PRId8":  %s\n",i+1,(movies+i)->name);
}

void nextMovie()
{
  movies->currentMovie++;
}

void prevMovie()
{
  if (movies->currentMovie>0)
  movies->currentMovie--;
}

int8_t takeMovie(char* name)
{
  int8_t numberOfMovie;
  for (numberOfMovie=0;numberOfMovie<movies->numberOfMovies;numberOfMovie++)
    if (strcmp(name,(movies+numberOfMovie)->name)==0)
    {
      currentMovies=movies+numberOfMovie;
      return 0;
    }
  return 1;
}

int8_t takeTermin(char* termin)
{
  int8_t numberOfTermin;
  for (numberOfTermin=0;numberOfTermin<1;numberOfTermin++)
    if (strcmp(termin,currentMovies->termin)==0)
      return 0;
  return 1;
}
