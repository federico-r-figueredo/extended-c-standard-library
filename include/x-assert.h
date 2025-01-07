#ifndef X_ASSERT_H
#define X_ASSERT_H

/**
 * @headerfile assert.h
 * 
 * @details The assert.h header file of the Extended C Standard Library provides
 * a macro called `assert` which can be used to verify assumptions made by the
 * program and print a diagnostic message if this assumption is false.
 * 
 * The defined macro `assert` refers to another macro `NDEBUG` which is not part
 * of <assert.h>. If `NDEBUG` is defined as a macro name in the source file, at 
 * the point where <assert.h> is included, the `assert` macro is defined as
 * follows
 * 
 *      #define assert(ignore) ((void) 0)
 * 
 * Macros:
 *      - void assert(int expression)
 *        This is actually a macro and not a function, which can be used to add 
 *        diagnostics in your C program.
 */

#include <stdbool.h>

void __assert(bool expression, const char *expression_str, const char *file, int line);

#ifdef NDEBUG
    #define assert(expression) ((void)0)
#else
    /**
     * @brief Used in error handling to check if any assumptions made in the program
     * during execution-time are correct or not. It is used to catch logical errors
     * in the program in the development stage itself.
     * 
     * @param expression It is a boolean expression that evaluates to either true
     * or false. If the expression evaluates to false (`0`), the assert function 
     * triggers an assertion failure, leading to program termination.
     * 
     * @returns This macro does not return any value. If the assertion fails 
     * (i.e. expression evaluates to false), it triggers an error message and aborts
     * program execution.
     */
    #define assert(expression) __assert((expression), #expression, __FILE__, __LINE__)
#endif

#endif // ASSERT_H