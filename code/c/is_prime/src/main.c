#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "No input received, exiting.\n");
        return EXIT_FAILURE;
    }

    int num = atoi(argv[1]);
    if (!num && *argv[1] != '0') {
        fprintf(stderr, "Unable to convert %s to an int, exiting.\n", argv[1]);
        return EXIT_FAILURE;
    }

    if (num < 2
        || num > 2 && num % 2 == 0
        || num > 3 && num % 3 == 0) {
        printf("False\n");
        return EXIT_SUCCESS;
    }

    for (int i = 5; i*i < num; i += 6) {
        if (num % i == 0 || num % (i+2) == 0) {
            printf("False\n");
            return EXIT_SUCCESS;
        }
    }

    printf("True\n");

    return EXIT_SUCCESS;
}
