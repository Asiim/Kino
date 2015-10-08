#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>
#include "../hall/src/hall.h"
#include "../counter/src/counter.h"
#include "../movie/src/movie.h"
#include <unistd.h>
#define ADMIN 1
#define USER 2
#define EXIT 0
#define LISTA_FILMOVA 1
#define GLEDANJE 2

void insertMovie(int8_t brojFilma)
{
  int8_t brojSale=14;
  char imeFilma[20],terminFilma[6];
  do
  {
    printf("Unesite ime %"PRId8". filma: ",brojFilma+1);
    scanf("%s",imeFilma);
    if (insertName(imeFilma)==1)
    {
        printf("Can't put empty name, please try again.\n");
    }
  }while(insertName(imeFilma)!=0);
  do
  {
    printf("Unesite termin %"PRId8". filma: ",brojFilma+1);
    scanf("%s",terminFilma);
    if(insertTermin(terminFilma)==1)
    {
      printf("You didnt enter a termin, please try again.\n");
    }
    else
    if (insertTermin(terminFilma)==2 )
    {
      printf("You can only enter a termin between 12:00 - 00:00, please try again.\n");
    }
    else
    if (insertTermin(terminFilma)==3 )
    {
      printf("Format is incorect, enter hh:mm, please try again.\n");
    }
  }while(insertTermin(terminFilma)!=0);
  do
  {
    printf("Unesite salu za %"PRId8". film: ",brojFilma+1);
    scanf("%"SCNd8,&brojSale);
    if(insertHall(brojSale)==1)
    {
      printf("Hall %"PRId8" doesn't exist,please try again.\n",brojSale);
    }
    else
    if (insertHall(brojSale)==2)
    {
      printf("Was not able to take hall %"PRId8", please try again.\n",brojSale);
    }
  }while(insertHall(brojSale)!=0);
  nextMovie();
}

void takeCardsForMovie()
{
  int8_t brojKarata=0;
  char termin[6],imeFilma[20];
  do
  {
    printf("Unesite ime filma: ");
    scanf("%s",imeFilma);
    if(takeMovie(imeFilma)==1)
      printf("Movie: %s doesn't exist, please try again.\n",imeFilma);
  }while(takeMovie(imeFilma)==1);
  do
  {
    printf("Koliko karata zelite: ");
    scanf("%"SCNd8,&brojKarata);
    if(takeCards(brojKarata)==-12)
      printf("Was not able to take cards, please try again.\n");
  }while(takeCards(brojKarata)==-12);
  do
  {
    printf("Koji termin zelite: ");
    scanf("%s",termin);
    if(takeTermin(termin)==1)
      printf("There is no such termin for this movie, please try again.\n");
  }while(takeTermin(termin)==1);
}

int main()
{
system("clear");
int8_t switcher1=3,switcher2=3,brojFilma,brojFilmova;
while (switcher1!=EXIT)
{
printf("Unesite:\n~~~~ '1' za ADMIN ~~~~\n~~~~ '2' za USER  ~~~~\n~~~~ '0' za EXIT  ~~~~\nUnos: ");
scanf("%"SCNd8,&switcher1);
system("clear");
switch (switcher1)
 {
    case ADMIN:
    printf("Koliko filmova želite unijeti: ");
    scanf("%"SCNd8,&brojFilmova);
    initMoreMovies(brojFilmova);
    printf("\n-------------------------------------------------\n\n");
    for(brojFilma=0;brojFilma<brojFilmova;brojFilma++)
    {
      insertMovie(brojFilma);
      printf("\n-------------------------------------------------\n\n");
    }
    break;

    case USER:
//----------------------------------------------------------------------------------------------
    while (switcher2!=EXIT)
    {
      printf("Unesite:\n~~~~ '1' za LISTU FILMOVA ~~~~\n~~~~ '2' za GLEDANJE      ~~~~\n~~~~ '0' za EXIT          ~~~~\n");
      scanf("%"SCNd8,&switcher2);
      system("clear");
      switch(switcher2)
      {
        case LISTA_FILMOVA:
        listMovies();
        break;

        case GLEDANJE:
          takeCardsForMovie();
        break;

        case EXIT:
        return;
        default:
        printf("Unijeli ste nevažeći broj, pokušajte ponovo.\n\n");
      }
    }
    break;
//--------------------------------------------------------------------------------------
    case EXIT:
    printf("Program se gasi.");
    break;

    default:
    printf("Unijeli ste nevažeći broj, pokušajte ponovo.\n\n");

}
}
return 0;

system("clear");
}
