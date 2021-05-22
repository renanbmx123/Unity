#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(Payment)
{
  RUN_TEST_CASE(Payment, ValueMin);
  RUN_TEST_CASE(Payment, ValueMax);
  RUN_TEST_CASE(Payment, ValueMiddle);
  RUN_TEST_CASE(Payment, ValueBelow);
  RUN_TEST_CASE(Payment, ValueAbove);
  RUN_TEST_CASE(Payment, StatusIncorrect);
}
