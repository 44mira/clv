#ifndef CLV_INTERNALS
#define CLV_INTERNALS

/* Helpers ----------------------------------------------------------------- */

enum __CLV_BOOL { FALSE, TRUE }; /* simple boolean type */
#define CLV_BOOL enum __CLV_BOOL

typedef unsigned int uint;

#define TEXT_RED(text) "\x1b[31m" text "\x1b[0m"
#define LABEL_SIZE 255

/* Declarations ------------------------------------------------------------ */

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
