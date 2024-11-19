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

#define ASSERT_INT_ARRAY_EQUAL(size, array1, array2)                           \
  __ASSERT_int_ARRAY_EQUAL(size, array1, array2, __LINE__)
#define ASSERT_FLOAT_ARRAY_EQUAL(size, array1, array2)                         \
  __ASSERT_float_ARRAY_EQUAL(size, array1, array2, __LINE__)
#define ASSERT_DOUBLE_ARRAY_EQUAL(size, array1, array2)                        \
  __ASSERT_double_ARRAY_EQUAL(size, array1, array2, __LINE__)
#define ASSERT_CHAR_ARRAY_EQUAL(size, array1, array2)                          \
  __ASSERT_char_ARRAY_EQUAL(size, array1, array2, __LINE__)
#define ASSERT_SHORT_ARRAY_EQUAL(size, array1, array2)                         \
  __ASSERT_short_ARRAY_EQUAL(size, array1, array2, __LINE__)
#define ASSERT_LONG_ARRAY_EQUAL(size, array1, array2)                          \
  __ASSERT_long_ARRAY_EQUAL(size, array1, array2, __LINE__)
#define ASSERT_UINT_ARRAY_EQUAL(size, array1, array2)                          \
  __ASSERT_uint_ARRAY_EQUAL(size, array1, array2, __LINE__)

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
