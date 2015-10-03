#include "../../unity/unity.h"
#include "../../unity/unity_fixture.h"
#include "../src/hall.h"

TEST_GROUP(HallTests);

TEST_GROUP_RUNNER(HallTests)
{
  RUN_TEST_CASE(HallTests,TestInitHall);

}

TEST_SETUP(HallTests)
{

}

TEST_TEAR_DOWN(HallTests)
{

}

TEST(HallTests,TestInitHall)
{
  initHall();
  TEST_ASSERT_EQUAL_INT('O',hall[0][5][4]);
}
