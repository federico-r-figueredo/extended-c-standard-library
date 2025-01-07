#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

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

/**
 * @fn `static_assert`
 * 
 * @name Example #1
 * @brief Ensuring Size of a Data Type
 * 
 * @details This program checks if the size of `int` is 4 bytes. If not, the compilation
 * fails with a message "int must be 4 bytes".
 */
int test_ensuring_size_of_data_type() {
    static_assert(sizeof(int) == 4, "int must be 4 bytes");

    return EXIT_SUCCESS;
}

/**
 * @fn `static_assert`
 * 
 * @name Example #2
 * @brief Checking Structure Alignment
 * 
 * @details This program uses the `offsetof` macro to ensure that the `name` member of
 * `MyStruct` struct is aligned to a 4-byte boundary. If not, the compilation fails.
 */
struct MyStruct {
    char first_member;
    int second_member;
};

int test_checking_structure_alignment() {
    static_assert(
        offsetof(struct MyStruct, second_member) % 4 == 0, 
        "int second_member must be aligned to 4 bytes."
    );

    return EXIT_SUCCESS;
}