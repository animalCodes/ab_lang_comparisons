#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) {
    // Check input exists
    if (argc < 2) {
        printf("No input received, exiting.\n");
        return 1;
    }

    // Attempt to convert to an int
    int num = atoi(argv[1]);
    if (num == 0 && *argv[1] != '0') {
        printf("Unable to convert %s to an int, exiting.\n", argv[1]);
        return 2;
    }

    // Preliminary checks
    if (num < 2 
        || num > 2 && num % 2 == 0
        || num > 3 && num % 3 == 0) {
        printf("False\n");
        return 0;
    }

    // Trial division
    for (int i = 5; i*i < num; i += 6) {
        // 5 (7), 11 (13), 17 (19), 23 (25), 29 (31), 35 (37)..
        if (num % i == 0 || num % (i+2) == 0) {
            printf("False\n");
            return 0;
        }
    }

    printf("True\n");
    return 0;
}