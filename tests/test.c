#include "../src/clv.h"

CLV_BOOL myIsOdd(int num) { return num % 2; }

int main() {
  SETUP;

  ASSERT((5 == 5)); /* Pass a condition to `ASSERT` and it will document the
                       test result. */
  ASSERT_TRUE((5 == 5)); /* ASSERT can also be called as `ASSERT_TRUE` if you
                            prefer a more explicit naming scheme. */

  TEST_LABEL("4 is not equal to 5"); /* You can attach an optional test label to
                                        your tests by calling this macro before
                                        the assert! */
  ASSERT_FALSE((4 != 5)); /* You can also use `ASSERT_FALSE` if you prefer it
                             over ASSERT((!condition)) */

  TEST_LABEL("4 is an odd number");
  ASSERT(myIsOdd(4));

  TEARDOWN;
}
