#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "No argument specified, exiting.");
        return 1;
    }

    int num = atoi(argv[1]);
    if (!num && *argv[1] != '0') {
        fprintf(stderr, "Unable to convert \"%s\" to an integer, exiting.\n", argv[1]);
        return 2;
    }

    int printed = 0; // If we have printed a value.

    if (num) { // If num is any none-zero number
        if (num % 3 == 0) {
            printf("Fizz");
            printed = 1;
        }
        if (num % 5 == 0) {
            printf("Buzz");
            printed = 1;
        }
    }

    if (!printed) 
        // Wasn't divisible by 3 or 5, so just print the number.
        printf("%i", num);

    printf("\n");

    return 0;
}
