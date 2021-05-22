#include "unity.h"
#include "unity_fixture.h"

#include "payment.h"


TEST_GROUP(Payment);

TEST_SETUP(Payment)
{
}

TEST_TEAR_DOWN(Payment)
{
}

TEST(Payment, ValueMin)
{
  float value = 0.01;
  char status[] = "estudante";

  TEST_ASSERT_EQUAL(0,payment(value,status));
}

TEST(Payment, ValueMax)
{
  float value = 99999.00;
  char status[] = "vip";

  TEST_ASSERT_EQUAL(0,payment(value,status));
}

TEST(Payment, ValueMiddle)
{
  float value = 1000.52;
  char status[] = "aposentado";

  TEST_ASSERT_EQUAL(0,payment(value,status));
}

TEST(Payment, ValueBelow)
{
  float value = 0.00;
  char status[] = "regular";

  TEST_ASSERT_EQUAL(1,payment(value,status));
}

TEST(Payment, ValueAbove)
{
  float value = 99999.01;
  char status[] = "regular";

  TEST_ASSERT_EQUAL(1,payment(value,status));
}

TEST(Payment, StatusIncorrect)
{
  float value = 5000.63;
  char status[] = "error";

  TEST_ASSERT_EQUAL(2,payment(value,status));
}
