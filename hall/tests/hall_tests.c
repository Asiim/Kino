#include "../../unity/unity.h"
#include "../../unity/unity_fixture.h"
#include "../src/hall.h"

TEST_GROUP(HallTests);

TEST_GROUP_RUNNER(HallTests)
{
  RUN_TEST_CASE(HallTests,TestInitHall);
  RUN_TEST_CASE(HallTests,TestTakeOnePlace);
  RUN_TEST_CASE(HallTests,TestTakeAllPlaces);
  RUN_TEST_CASE(HallTests,TestFreeOnePlace);
  RUN_TEST_CASE(HallTests,TestFreeAllPlaces);
}

TEST_SETUP(HallTests)
{
    initHall();
}

TEST_TEAR_DOWN(HallTests)
{

}

TEST(HallTests,TestInitHall)
{
  TEST_ASSERT_EQUAL_INT8('O',hall[0][5][4]);
}

TEST(HallTests,TestTakeOnePlace)
{
  takeOnePlace(0,1,2);
  TEST_ASSERT_EQUAL_INT8('x',hall[0][1][2]);
}

TEST(HallTests,TestTakeAllPlaces)
{
  takeAllPlaces();
  TEST_ASSERT_EQUAL_INT8('x',hall[3][9][11]);
}

TEST(HallTests,TestFreeOnePlace)
{
  freeOnePlace(3,3,3);
  TEST_ASSERT_EQUAL_INT8('O',hall[3][3][3]);
}

TEST(HallTests,TestFreeAllPlaces)
{
  freeAllPlaces();
  TEST_ASSERT_EQUAL_INT8('O',hall[0][0][0]);
}
