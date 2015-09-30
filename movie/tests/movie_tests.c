#include "../../unity/unity.h"
#include "../../unity/unity_fixture.h"
#include "../src/movie.h"

MOVIE* film;

TEST_GROUP(movieAdminTest);

TEST_GROUP_RUNNER(movieAdminTest)
{
  RUN_TEST_CASE (movieAdminTest, TestAllocateMovie);
  RUN_TEST_CASE (movieAdminTest, TestInsertName);
  RUN_TEST_CASE (movieAdminTest, TestInsertEmptyName);
  RUN_TEST_CASE (movieAdminTest, TestInsertLongName);

}

TEST_SETUP(movieAdminTest)
{
  film = initMovie();
}

TEST_TEAR_DOWN(movieAdminTest)
{
}

TEST(movieAdminTest, TestAllocateMovie)
{
  TEST_ASSERT_TRUE(film != NULL);
}

TEST(movieAdminTest,TestInsertName)
{

  TEST_ASSERT_EQUAL_INT(0, insertName(film,"film 1"));
}

TEST(movieAdminTest,TestInsertEmptyName)
{
  TEST_ASSERT_EQUAL_INT(1,insertName(film,""));
}

TEST(movieAdminTest,TestInsertLongName)
{
  TEST_ASSERT_EQUAL_INT(0,insertName(film,"asimasimaimsiamsiams1234321234"));
}
