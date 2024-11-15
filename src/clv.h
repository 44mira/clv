#ifndef CLV_HEADER
#define CLV_HEADER

#include "clv_internals.h"

/* Macros ------------------------------------------------------------------ */
#define ASSERT(condition) CLV_ASSERT(condition, __LINE__)
#define ASSERT_TRUE(condition) ASSERT(condition)
#define ASSERT_FALSE(condition) ASSERT(!condition)
#define TEST_LABEL(label) CLV_UPDATE_LABEL(label)

#define SETUP CLV_SETUP()
#define TEARDOWN                                                               \
  CLV_TEARDOWN();                                                              \
  return 0

#endif
