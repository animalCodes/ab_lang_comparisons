#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// C fizzbzz

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "No number specified, exiting.\n");
        return EXIT_FAILURE;
    }

    char *end;
    int num = strtol(argv[1], &end, 10);

    if (end == argv[1]) {
        fprintf(stderr, "%s cannot be converted into a number, exiting.\n",
                argv[1]);
        return EXIT_FAILURE;
    }

    if (num % 3 == 0 && num % 5 == 0) {
        printf("FizzBuzz\n");
        return EXIT_SUCCESS;
    }

    if (num % 3 == 0)
        printf("Fizz");
    else if (num % 5 == 0)
        printf("Buzz");
    else
        printf("%i", num);

    printf("\n");

    return EXIT_SUCCESS;
}
