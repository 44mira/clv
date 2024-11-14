#include "clv.h"

int main() {
  SETUP;

  TEST_LABEL("5 should equal to 5");
  ASSERT((5 == 5));

  TEST_LABEL("4 should not be equal to 5");
  ASSERT_FALSE((4 == 5));

  TEST_LABEL("4 should equal to 5");
  ASSERT((4 == 5));

  TEARDOWN;
}
