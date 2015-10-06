#include "counter.h"

static int8_t takeOneCard()
{
  return mainCounter.numberOfCards=1;
}

static int8_t nullCards()
{
  return 0;
}

COUNTER initCounter()
{
  return mainCounter;
}

int8_t takeCards(int8_t number)
{
  if (number < 0 || number > MAX_CARDS)
  {
    return -12;
  }
  else
  switch (number)
  {
    case 1:
    return takeOneCard();
    case 0:
    return nullCards();
    default:
    return mainCounter.numberOfCards=number;
  }
}
