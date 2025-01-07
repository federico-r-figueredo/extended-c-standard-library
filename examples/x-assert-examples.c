#include <stdio.h>
#include <stdlib.h>

#include "x-assert.h"
#include "x-assert-examples.h"

/********************************************************************
 *                x-assert types, macros & functions                *
 ********************************************************************/

/**
 * @fn `assert`
 * 
 * @name Example #1
 * @brief Checking Simple Expression
 * 
 * @details This program checks if the variable `x` is equal to `5`. If the condition
 * is `true`, the program executes successfully and prints "Assertion passed!". If
 * it is not `true`, then the program gets aborted and a diagnostic message is 
 * printed.
 */
int test_checking_single_expression() {
    int x = 5;
    assert(x == 5);
    printf("Assertion passed!\n");

    return EXIT_SUCCESS;
}

/**
 * @fn `assert`
 * 
 * @name Example #2
 * @brief Checking Logical Expression
 * 
 * @details This program checks if the sum of variables `a` and `b` is greater than `5`.
 * Since the sum is equal to 8, which is greater than 5, the condition is `true`. However,
 * if the condition evaluates to `false`, the error message will be displayed.
 */
int test_checking_logical_expression() {
    int first_number = 5;
    int second_number = 3;

    assert((first_number + second_number) > 5 && "Sum is not greater than 5");
    printf("Assertion passed!\n");

    return EXIT_SUCCESS;
}