#include <stdio.h>
#include <stdlib.h>

// C is_prime

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "No number specified, exiting.\n");
        return EXIT_FAILURE;
    }

    char *end;
    int num = strtol(argv[1], &end, 10);

    // `end` will be the address of the first nondigit character, if the string
    // (excluding whitespace and optional +/-) doesn't start with a digit
    // this'll be the start of the string.
    if (end == argv[1]) {
        fprintf(stderr, "\"%s\" cannot be converted into a number, exiting.\n",
            argv[1]);
        return EXIT_FAILURE;
    }

    // Crude check for whether number isn't natural (has a decimal point)
    // This'll incorrectly print "False" for values such as 2.0, but it's close
    // enough.
    if (end[0] == '.') {
        printf("False\n");
        return EXIT_SUCCESS;
    }

    if (num < 2
        || num > 2 && num % 2 == 0
        || num > 3 && num % 3 == 0) {
        printf("False\n");
        return EXIT_SUCCESS;
    }

    for (int i = 5; i*i <= num; i += 6) {
        if (num % i == 0 || num % (i+2) == 0) {
            printf("False\n");
            return EXIT_SUCCESS;
        }
    }

    printf("True\n");

    return EXIT_SUCCESS;
}
