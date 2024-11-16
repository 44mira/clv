#ifndef CLV_INTERNALS
#define CLV_INTERNALS

/* Helpers ----------------------------------------------------------------- */

enum __CLV_BOOL { FALSE, TRUE }; /* simple boolean type */
#define CLV_BOOL enum __CLV_BOOL

typedef unsigned int uint;

#define TEXT_RED(text) "\x1b[31m" text "\x1b[0m"
#define TEXT_GREEN(text) "\x1b[32m" text "\x1b[0m"
#define TEXT_BOLD(text) "\x1b[1m" text "\x1b[0m"
#define LABEL_SIZE 255

/* Declarations ------------------------------------------------------------ */

// generic array comparison macro
#define CLV_ASSERT_ARRAY_EQUAL(type)                                           \
  void ASSERT_##type##_ARRAY_EQUAL(uint size, type *array1, type *array2) {    \
    for (uint i = 0; i < size; i++) {                                          \
      if (array1[i] != array2[i]) {                                            \
        CLV_FAIL(__LINE__);                                                    \
        return;                                                                \
      }                                                                        \
    }                                                                          \
    CLV_PASS(__LINE__);                                                        \
  }

#define CLV_ASSERT_ARRAY_EQUAL_SIG(type)                                       \
  /**                                                                          \
   * Compares two arrays of the same type and size                             \
   *                                                                           \
   * @param size The size of the arrays                                        \
   * @param array1 The first array to be compared                              \
   * @param array2 The second array to be compared                             \
   */                                                                          \
  void ASSERT_##type##_ARRAY_EQUAL(uint size, type *array1, type *array2);

// generic array comparison macro
#define CLV_ASSERT_ARRAY_EACH_EQUAL(type)                                      \
  void ASSERT_##type##_ARRAY_EACH_EQUAL(uint size, type target,                \
                                        type *array2) {                        \
    for (uint i = 0; i < size; i++) {                                          \
      if (target != array2[i]) {                                               \
        CLV_FAIL(__LINE__);                                                    \
        return;                                                                \
      }                                                                        \
    }                                                                          \
    CLV_PASS(__LINE__);                                                        \
  }

#define CLV_ASSERT_ARRAY_EACH_EQUAL_SIG(type)                                  \
  /**                                                                          \
   * Compares all the elements of an array to a single value                   \
   *                                                                           \
   * @param size The size of the arrays                                        \
   * @param target The value to match per element                              \
   * @param array2 The second array to be compared                             \
   */                                                                          \
  void ASSERT_##type##_ARRAY_EACH_EQUAL(uint size, type target, type *array2);

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
void CLV_UPDATE_LABEL(const char *label);

/**
 * Check whether two strings are equal.
 *
 * @param string1 The first string to be compared
 * @param string2 The second string to be compared
 * @param line The line where the assertion was made
 */
void CLV_ASSERT_STRING_EQUAL(const char *string1, const char *string2,
                             uint line);

#endif
