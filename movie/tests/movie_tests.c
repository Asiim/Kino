#include "../../unity/unity.h"
#include "../../unity/unity_fixture.h"
#include "../src/movie.h"

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
  RUN_TEST_CASE (movieAdminTest, TestFreeMovie);
  RUN_TEST_CASE (movieAdminTest, TestAllocateMoreMovies);
  RUN_TEST_CASE (movieAdminTest, TestTakeMovie);
  RUN_TEST_CASE (movieAdminTest, TestTakeWrongMovie);
  RUN_TEST_CASE (movieAdminTest, TestTakeTermin);
  RUN_TEST_CASE (movieAdminTest, TestTakeWrongTermin);
}

TEST_SETUP(movieAdminTest)
{
  initMovie();
}

TEST_TEAR_DOWN(movieAdminTest)
{
  freeMovie();
}

TEST(movieAdminTest, TestAllocateMovie)
{
  TEST_ASSERT_TRUE(movies != NULL);
}

TEST(movieAdminTest,TestInsertName)
{
  TEST_ASSERT_EQUAL_INT(0, insertName("film 1"));
}

TEST(movieAdminTest,TestInsertEmptyName)
{
  TEST_ASSERT_EQUAL_INT(1,insertName(""));
}

TEST(movieAdminTest,TestInsertLongName)
{
  TEST_ASSERT_EQUAL_INT(0,insertName("asimasimaimsiamsiams1234321234"));
}

TEST(movieAdminTest,TestInsertTermin)
{
  TEST_ASSERT_EQUAL_INT(0,insertTermin("12:10"));
}

TEST(movieAdminTest,TestInsertEmptyTermin)
{
  TEST_ASSERT_EQUAL_INT(1,insertTermin(""));
}

TEST(movieAdminTest,TestInsertTerminAfterClose)
{
  TEST_ASSERT_EQUAL_INT(2,insertTermin("00:15"));
}

TEST(movieAdminTest,TestInsertTerminBeforeOpen)
{
  TEST_ASSERT_EQUAL_INT(2,insertTermin("10:15"));
}

TEST(movieAdminTest,TestInsertTerminOnClose)
{
  TEST_ASSERT_EQUAL_INT(0,insertTermin("12:00"));
}

TEST(movieAdminTest,TestInsertTerminOnOpen)
{
  TEST_ASSERT_EQUAL_INT(0,insertTermin("12:00"));
}

TEST(movieAdminTest,TestInsertTerminIrregular)
{
  TEST_ASSERT_EQUAL_INT(3,insertTermin("2a:12"));
}

TEST(movieAdminTest,TestInsertHall)
{
  TEST_ASSERT_EQUAL_INT(0,insertHall(3));
}

TEST(movieAdminTest,TestInsertHallOutOfBounds)
{
  TEST_ASSERT_EQUAL_INT(1,insertHall(5));
}


TEST(movieAdminTest,TestFreeMovie)
{
  TEST_ASSERT_TRUE(movies);
}

TEST(movieAdminTest,TestAllocateMoreMovies)
{
  freeMovie();
  initMoreMovies(5);
  TEST_ASSERT_EQUAL_INT(sizeof(movies)*5,sizeof(movies)*movies->numberOfMovies);
}

TEST(movieAdminTest,TestTakeMovie)
{
    insertName("film1");
    TEST_ASSERT_EQUAL_INT8(0,takeMovie("film1"));
}

TEST(movieAdminTest,TestTakeWrongMovie)
{
    insertName("film1");
    TEST_ASSERT_EQUAL_INT8(1,takeMovie("film3"));
}

TEST(movieAdminTest,TestTakeTermin)
{
    insertName("film1");
    takeMovie("film1");
    insertTermin("12:00");
    TEST_ASSERT_EQUAL_INT8(0,takeTermin("12:00"));
}

TEST(movieAdminTest,TestTakeWrongTermin)
{
    insertName("film1");
    takeMovie("film1");
    insertTermin("12:00");
    TEST_ASSERT_EQUAL_INT8(1,takeTermin("12:12"));
}
