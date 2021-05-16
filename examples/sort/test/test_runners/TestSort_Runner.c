#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(Sort)
{
  RUN_TEST_CASE(Sort, testCheckIfValuesWereChanged);
  RUN_TEST_CASE(Sort, testArrayOrder);
  RUN_TEST_CASE(Sort, testSingleValue);
  RUN_TEST_CASE(Sort, testOnlyZerosValues);
}
