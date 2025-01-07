#ifndef X_ASSERT_EXAMPLES_H
#define X_ASSERT_EXAMPLES_H

/********************************************************************
 *                x-assert types, macros & functions                *
 ********************************************************************/

/**
 * @fn `assert`
 */
int test_checking_single_expression();
int test_checking_logical_expression();

/**
 * @fn `static_assert`
 */
int test_ensuring_size_of_data_type();
int test_checking_structure_alignment();

#endif // X_ASSERT_EXAMPLES_H