#ifndef CLV_HEADER
#define CLV_HEADER

#ifdef __cplusplus
extern "C" {
#endif

#include "clv_internals.h"

/* Macros ------------------------------------------------------------------ */
#define ASSERT(condition) CLV_ASSERT(condition, __LINE__)
#define ASSERT_TRUE(condition) ASSERT(condition)
#define ASSERT_FALSE(condition) ASSERT(!condition)
#define ASSERT_STRING_EQUAL(string1, string2)                                  \
  CLV_ASSERT_STRING_EQUAL(string1, string2, __LINE__)
#define TEST_LABEL(label) CLV_UPDATE_LABEL(label)

CLV_ASSERT_ARRAY_EQUAL_SIG(int)
CLV_ASSERT_ARRAY_EQUAL_SIG(float)
CLV_ASSERT_ARRAY_EQUAL_SIG(double)
CLV_ASSERT_ARRAY_EQUAL_SIG(char)
CLV_ASSERT_ARRAY_EQUAL_SIG(short)
CLV_ASSERT_ARRAY_EQUAL_SIG(long)
CLV_ASSERT_ARRAY_EQUAL_SIG(uint)

CLV_ASSERT_ARRAY_EACH_EQUAL_SIG(int)
CLV_ASSERT_ARRAY_EACH_EQUAL_SIG(float)
CLV_ASSERT_ARRAY_EACH_EQUAL_SIG(double)
CLV_ASSERT_ARRAY_EACH_EQUAL_SIG(char)
CLV_ASSERT_ARRAY_EACH_EQUAL_SIG(short)
CLV_ASSERT_ARRAY_EACH_EQUAL_SIG(long)
CLV_ASSERT_ARRAY_EACH_EQUAL_SIG(uint)

#define SETUP CLV_SETUP()
#define TEARDOWN                                                               \
  CLV_TEARDOWN();                                                              \
  return 0

#ifdef __cplusplus
}
#endif
#endif
