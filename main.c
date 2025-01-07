#include <stdio.h>
#include <stdlib.h>

#include "x-assert.h"
#include "x-assert-examples.h"

int main(int argument_count, char** argument_values) {
    test_ensuring_size_of_data_type();
    test_checking_structure_alignment();
    
    return EXIT_SUCCESS;
}