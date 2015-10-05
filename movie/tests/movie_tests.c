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
  RUN_TEST_CASE (movieAdminTest, TestInsertTermin);
  RUN_TEST_CASE (movieAdminTest, TestInsertEmptyTermin);
  RUN_TEST_CASE (movieAdminTest, TestInsertTerminAfterClose);
  RUN_TEST_CASE (movieAdminTest, TestInsertTerminBeforeOpen);
  RUN_TEST_CASE (movieAdminTest, TestInsertTerminOnOpen);
  RUN_TEST_CASE (movieAdminTest, TestInsertTerminOnClose);
  RUN_TEST_CASE (movieAdminTest, TestInsertTerminIrregular);
  RUN_TEST_CASE (movieAdminTest, TestInsertHall);
  RUN_TEST_CASE (movieAdminTest, TestInsertHallOutOfBounds);
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

TEST(movieAdminTest,TestInsertTermin)
{
  TEST_ASSERT_EQUAL_INT(0,insertTermin(film,"12:10"));
}

TEST(movieAdminTest,TestInsertEmptyTermin)
{
  TEST_ASSERT_EQUAL_INT(1,insertTermin(film,""));
}

TEST(movieAdminTest,TestInsertTerminAfterClose)
{
  TEST_ASSERT_EQUAL_INT(2,insertTermin(film,"00:15"));
}

TEST(movieAdminTest,TestInsertTerminBeforeOpen)
{
  TEST_ASSERT_EQUAL_INT(2,insertTermin(film,"10:15"));
}

TEST(movieAdminTest,TestInsertTerminOnClose)
{
  TEST_ASSERT_EQUAL_INT(2,insertTermin(film,"12:00"));
}

TEST(movieAdminTest,TestInsertTerminOnOpen)
{
  TEST_ASSERT_EQUAL_INT(2,insertTermin(film,"12:00"));
}

TEST(movieAdminTest,TestInsertTerminIrregular)
{
  TEST_ASSERT_EQUAL_INT(3,insertTermin(film,"2a:12"));
}

TEST(movieAdminTest,TestInsertHall)
{
  TEST_ASSERT_EQUAL_INT(0,insertHall(film,3));
}

TEST(movieAdminTest,TestInsertHallOutOfBounds)
{
  TEST_ASSERT_EQUAL_INT(1,insertHall(film,5));
}
