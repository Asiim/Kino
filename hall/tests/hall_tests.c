#include "../../unity/unity.h"
#include "../../unity/unity_fixture.h"
#include "../src/hall.h"

static int random2(int i)
{
  time_t t;
  srand((unsigned) time(&t));
  return rand()%i;
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

static uint8_t helpFreeOnePlace(uint8_t room,uint8_t row,uint8_t column)
{
  if (roomOutOfBound(room))
  {
    room=random2(MAX_HALLS);
    printf("room=%" PRIu8,room);
    return 1;
  }
  if(rowOutOfBound(row))
  {
    row=random2(MAX_ROWS);
    printf("row=%" PRIu8,row);
    return 2;
  }
  if(columnOutOfBound(column))
  {
      column=random2(MAX_COLUMNS);
      printf("column=%" PRIu8,column);
      return 3;
  }
  hall[room][row][column]=FREE;
}

static uint8_t helpTakeOnePlace(uint8_t room,uint8_t row,uint8_t column)
{
  if (roomOutOfBound(room))
  {
    room=random2(MAX_HALLS);
    printf("room=%" PRIu8,room);
    return 1;
  }
  if(rowOutOfBound(row))
  {
    row=random2(MAX_ROWS);
    printf("row=%" PRIu8,row);
    return 2;
  }
  if(columnOutOfBound(column))
  {
      column=random2(MAX_COLUMNS);
      printf("column=%" PRIu8,column);
      return 3;
  }
  hall[room][row][column]=TAKEN;
}

static int8_t helpTakeRandomPlace()
{
  takeRandomPlace();
  return 0;
}

static int8_t helpFreeRandomPlace()
{
  freeRandomPlace();
  return 0;
}

TEST_GROUP(HallTestsTake);
TEST_GROUP(HallTestsFree);

TEST_GROUP_RUNNER(HallTestsTake)
{
  RUN_TEST_CASE(HallTestsTake,TestInitHall);
  RUN_TEST_CASE(HallTestsTake,TestTakeOnePlace);
  RUN_TEST_CASE(HallTestsTake,TestTakeAllPlaces);
  RUN_TEST_CASE(HallTestsTake,TestTakeHallOutOfBounds);
  RUN_TEST_CASE(HallTestsTake,TestTakeRowOutOfBounds);
  RUN_TEST_CASE(HallTestsTake,TestTakeColumnOutOfBounds);
  RUN_TEST_CASE(HallTestsTake,TestTakeRandomPlace);
  RUN_TEST_CASE(HallTestsTake,TestPlaceAlreadyTaken);
}
TEST_GROUP_RUNNER(HallTestsFree)
{
  RUN_TEST_CASE(HallTestsFree,TestFreeOnePlace);
  RUN_TEST_CASE(HallTestsFree,TestFreeAllPlaces);
  RUN_TEST_CASE(HallTestsFree,TestFreeHallOutOfBounds);
  RUN_TEST_CASE(HallTestsFree,TestFreeRowOutOfBounds);
  RUN_TEST_CASE(HallTestsFree,TestFreeColumnOutOfBounds);
  RUN_TEST_CASE(HallTestsFree,TestFreeRandomPlace);
  RUN_TEST_CASE(HallTestsFree,TestPlaceAlreadyFree);
}

TEST_SETUP(HallTestsTake)
{
    initHall();
}
TEST_SETUP(HallTestsFree)
{
  takeAllPlaces();
}

TEST_TEAR_DOWN(HallTestsTake)
{
}
TEST_TEAR_DOWN(HallTestsFree)
{
}

TEST(HallTestsTake,TestInitHall)
{
  TEST_ASSERT_EQUAL_INT8(FREE,hall[0][5][4]);
}

TEST(HallTestsTake,TestTakeOnePlace)
{
  takeOnePlace(0,1,2);
  TEST_ASSERT_EQUAL_INT8(TAKEN,hall[0][1][2]);
}

TEST(HallTestsTake,TestTakeAllPlaces)
{
  takeAllPlaces();
  TEST_ASSERT_EQUAL_INT8(TAKEN,hall[3][9][11]);
}

TEST(HallTestsFree,TestFreeOnePlace)
{
  freeOnePlace(3,3,3);
  TEST_ASSERT_EQUAL_INT8(FREE,hall[3][3][3]);
}

TEST(HallTestsFree,TestFreeAllPlaces)
{
  freeAllPlaces();
  TEST_ASSERT_EQUAL_INT8(FREE,hall[0][0][0]);
}

TEST(HallTestsFree,TestFreeHallOutOfBounds)
{
  TEST_ASSERT_EQUAL_INT8(1,helpFreeOnePlace(5,3,3));
}

TEST(HallTestsFree,TestFreeRowOutOfBounds)
{
  TEST_ASSERT_EQUAL_INT8(2,helpFreeOnePlace(3,12,3));
}

TEST(HallTestsFree,TestFreeColumnOutOfBounds)
{
  TEST_ASSERT_EQUAL_INT8(3,helpFreeOnePlace(2,3,-3));
}

TEST(HallTestsTake,TestTakeHallOutOfBounds)
{
  TEST_ASSERT_EQUAL_INT8(1,helpTakeOnePlace(-5,3,3));
}

TEST(HallTestsTake,TestTakeRowOutOfBounds)
{
  TEST_ASSERT_EQUAL_INT8(2,helpTakeOnePlace(3,-12,3));
}

TEST(HallTestsTake,TestTakeColumnOutOfBounds)
{
  TEST_ASSERT_EQUAL_INT8(3,helpTakeOnePlace(2,3,13));
}

TEST(HallTestsTake,TestTakeRandomPlace)
{
  TEST_ASSERT_EQUAL_INT8(0,helpTakeRandomPlace());
}

TEST(HallTestsFree,TestFreeRandomPlace)
{
  TEST_ASSERT_EQUAL_INT8(0,helpFreeRandomPlace());
}

TEST(HallTestsTake,TestPlaceAlreadyTaken)
{
  takeAllPlaces();
  TEST_ASSERT_EQUAL_INT8(1,takeOnePlace(0,0,0));
}

TEST(HallTestsFree,TestPlaceAlreadyFree)
{
  freeAllPlaces();
  TEST_ASSERT_EQUAL_INT8(1,freeOnePlace(0,0,0));
}
