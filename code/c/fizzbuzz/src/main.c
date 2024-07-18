#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "No argument specified, exiting.");
        return EXIT_FAILURE;
    }

    int num = atoi(argv[1]);
    if (!num && *argv[1] != '0') {
        fprintf(stderr, "Unable to convert \"%s\" to an integer, exiting.\n",
                argv[1]);
        return EXIT_FAILURE;
    }

    bool printed = false;

    if (num) { // num is any none-zero number
        if (num % 3 == 0) {
            printf("Fizz");
            printed = true;
        }
        if (num % 5 == 0) {
            printf("Buzz");
            printed = true;
        }
    }

    if (!printed) 
        printf("%i", num);

    printf("\n");

    return EXIT_SUCCESS;
}
