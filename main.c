#include <stdio.h>
#include <stdlib.h>

#include "x-assert.h"
#include "x-assert-examples.h"

int main(int argument_count, char** argument_values) {
    test_checking_single_expression();
    test_checking_logical_expression();
    return EXIT_SUCCESS;
}