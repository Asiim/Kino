#include "../../unity/unity_fixture.h"
#include "../src/counter.h"


TEST_GROUP(counterTests);

TEST_GROUP_RUNNER(counterTests)
{
  RUN_TEST_CASE(counterTests, TestTakeOneCard);
  RUN_TEST_CASE(counterTests, TestTakeNullCards);
  RUN_TEST_CASE(counterTests, TestTakeMoreCards);
  RUN_TEST_CASE(counterTests, TestNumberOfCardsToMuch);
  RUN_TEST_CASE(counterTests, TestNumberOfCardsNegative);
}

TEST_SETUP(counterTests)
{

}

TEST_TEAR_DOWN(counterTests)
{

}

TEST(counterTests,TestTakeOneCard)
{
  TEST_ASSERT_EQUAL_INT8(1,takeCards(1));
}

TEST(counterTests,TestTakeNullCards)
{
  TEST_ASSERT_EQUAL_INT8(0,takeCards(0));
}

TEST(counterTests, TestTakeMoreCards)
{
  TEST_ASSERT_EQUAL_INT8(5,takeCards(5));
}

TEST(counterTests, TestNumberOfCardsToMuch)
{
  TEST_ASSERT_EQUAL_INT8(-12,takeCards(65));
}

TEST(counterTests, TestNumberOfCardsNegative)
{
  TEST_ASSERT_EQUAL_INT8(-12,takeCards(-9));
}
