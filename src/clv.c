#include "clv.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char clvPass[] = "\x1b[42;30m  OK  \x1b[0m";
static const char clvFail[] = "\x1b[41;30m FAIL \x1b[0m";
static uint testCount = 0;
char *testLabel;

/**
 * Prints out the formatted PASS message using the current testLabel
 *
 * @param line The line where the assertion was made
 */
static void CLV_PASS(uint line) {
  if (strcmp(testLabel, "") == 0) {
    printf("%s | TEST #%02u LINE %-5u\n", clvPass, testCount, line);
  } else {
    printf("%s | TEST #%02u LINE %-5u | %s\n", clvPass, testCount, line,
           testLabel);
  }
}

/**
 * Prints out the formatted FAIL message using the current testLabel
 *
 * @param line The line where the assertion was made
 */
static void CLV_FAIL(uint line) {
  if (strcmp(testLabel, "") == 0) {
    printf("%s | TEST #%02u LINE %-5u\n", clvFail, testCount, line);
  } else {
    printf("%s | TEST #%02u LINE %-5u | " TEXT_RED("%s") "\n", clvFail,
           testCount, line, testLabel);
  }
}

/* Setup Abstraction ------------------------------------------------------- */

void CLV_SETUP() {
  // dynamically allocate testLabel
  testLabel = (char *)malloc(LABEL_SIZE * sizeof testLabel);

  // initialize testLabel
  TEST_LABEL("");
}
void CLV_TEARDOWN() { free(testLabel); }
void CLV_UPDATE_LABEL(const char *label) { strcpy(testLabel, label); }

/* Asserts ----------------------------------------------------------------- */

void CLV_ASSERT(CLV_BOOL condition, uint line) {
  testCount++;

  if (condition) {
    CLV_PASS(line);
  } else {
    CLV_FAIL(line);
  }

  // Invalidate label
  TEST_LABEL("");
}

void CLV_ASSERT_STRING_EQUAL(const char *string1, const char *string2,
                             uint line) {
  testCount++;

  if (strcmp(string1, string2) == 0) {
    CLV_PASS(line);
  } else {
    CLV_FAIL(line);
  }

  TEST_LABEL("");
}

CLV_ASSERT_ARRAY_EQUAL(int)
CLV_ASSERT_ARRAY_EQUAL(float)
CLV_ASSERT_ARRAY_EQUAL(double)
CLV_ASSERT_ARRAY_EQUAL(char)
CLV_ASSERT_ARRAY_EQUAL(short)
CLV_ASSERT_ARRAY_EQUAL(long)
CLV_ASSERT_ARRAY_EQUAL(uint)

CLV_ASSERT_ARRAY_EACH_EQUAL(int)
CLV_ASSERT_ARRAY_EACH_EQUAL(float)
CLV_ASSERT_ARRAY_EACH_EQUAL(double)
CLV_ASSERT_ARRAY_EACH_EQUAL(char)
CLV_ASSERT_ARRAY_EACH_EQUAL(short)
CLV_ASSERT_ARRAY_EACH_EQUAL(long)
CLV_ASSERT_ARRAY_EACH_EQUAL(uint)
