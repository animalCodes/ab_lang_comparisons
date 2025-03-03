#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// C fizzbuzz

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "No number specified, exiting.\n");
        return EXIT_FAILURE;
    }

    char *end;
    double n = strtof(argv[1], &end);

    if (end == argv[1]) {
        fprintf(stderr, "\"%s\" cannot be converted into a number, exiting.\n",
                argv[1]);
        return EXIT_FAILURE;
    }

    if (floor(n) != n) {
        printf("%s\n", argv[1]);
        return EXIT_SUCCESS;
    }

    int m = n;

    if (m % 3 == 0 && m % 5 == 0) {
        printf("FizzBuzz\n");
        return EXIT_SUCCESS;
    }

    if (m % 3 == 0)
        printf("Fizz");
    else if (m % 5 == 0)
        printf("Buzz");
    else
        printf("%i", m);

    printf("\n");

    return EXIT_SUCCESS;
}
