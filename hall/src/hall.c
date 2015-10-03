#include "hall.h"

char initHall()
{
  int i,j,k;
  for(i=0;i<4;i++)
    for(j=0;j<10;j++)
      for(k=0;k<12;k++)
        hall[i][j][k]='O';
    return '0';
}
