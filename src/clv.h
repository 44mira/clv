#ifndef CLV_HEADER
#define CLV_HEADER

#include <string.h>

/* Helper declarations ----------------------------------------------------- */
#define LABEL_SIZE 255

enum __CLV_BOOL { FALSE, TRUE }; /* simple boolean type */
#define CLV_BOOL enum __CLV_BOOL

typedef unsigned int uint;

#define TEXT_RED(text) "\x1b[31m" text "\x1b[0m"

/* Macros ------------------------------------------------------------------ */
#define ASSERT(condition) CLV_ASSERT(condition, __LINE__)
#define ASSERT_TRUE(condition) ASSERT(condition)
#define ASSERT_FALSE(condition) ASSERT(!condition)
#define TEST_LABEL(label) CLV_UPDATE_LABEL(label)

#define SETUP CLV_SETUP()
#define TEARDOWN                                                               \
  CLV_TEARDOWN();                                                              \
  return 0

/* Function declarations --------------------------------------------------- */

/**
 * Check whether a condition is true.
 *
 * Consumes the current testLabel, if it exists.
 *
 * @param condition The condition to be checked
 * @param line The line where the assertion was made
 */
void CLV_ASSERT(CLV_BOOL condition, uint line);

/**
 * Prints out the formatted PASS message using the current testLabel
 *
 * @param line The line where the assertion was made
 */
void CLV_PASS(uint line);

/**
 * Prints out the formatted FAIL message using the current testLabel
 *
 * @param line The line where the assertion was made
 */
void CLV_FAIL(uint line);

/**
 * Setup code for testing suite, does memory allocations.
 */
void CLV_SETUP();

/**
 * Teardown code for testing suite, does memory deallocations.
 */
void CLV_TEARDOWN();

/**
 * Updates the global state of testLabel to label
 *
 * @param label The new label to be set
 */
void CLV_UPDATE_LABEL(char *label);

#endif
