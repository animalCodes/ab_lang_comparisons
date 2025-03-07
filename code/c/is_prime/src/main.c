#include <stdio.h>
#include <stdlib.h>

// C is_prime

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "No number specified, exiting.\n");
        return EXIT_FAILURE;
    }

    char *end;
    float input = strtof(argv[1], &end);

    if (end == argv[1]) {
        fprintf(stderr, "\"%s\" cannot be converted into a number, exiting.\n",
            argv[1]);
        return EXIT_FAILURE;
    }

    int num = input;
    if (num != input) {
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
