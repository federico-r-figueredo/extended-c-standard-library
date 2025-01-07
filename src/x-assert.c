#include <stdio.h>
#include <stdlib.h>

#include "x-assert.h"

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_RESET "\x1b[0m"

void __assert(bool expression, const char *expression_str, const char *file, int line) {
    if (!expression) {
        fprintf(stderr, ANSI_COLOR_RED "Assertion failed: (%s), file %s, line %d\n" ANSI_COLOR_RESET,
                expression_str, file, line);
        exit(EXIT_FAILURE);
    }
}