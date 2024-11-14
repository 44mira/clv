#include "../src/clv.h"

CLV_BOOL myIsOdd(int num) { return num % 2; }

int main() {
  SETUP;

  ASSERT((5 == 5));
  ASSERT_TRUE((5 == 5));

  TEST_LABEL("4 is not equal to 5");
  ASSERT_FALSE((4 != 5));

  TEST_LABEL("4 is an odd number");
  ASSERT(myIsOdd(4));

  TEARDOWN;
}
