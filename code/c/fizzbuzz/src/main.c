#include <stdio.h>
#include <stdlib.h> // For strtol
#include <stdbool.h> // For booleans

int main(int argc, char *argv[]) {
    // Should always have at least one argument - the path to the program.
    if (argc < 2) {
        printf("No argument specified, exiting.");
        return 1;
    }

    // Convert to base 10 number 
    int num = strtol(argv[1], NULL, 10);
    // Check if conversion was successful (strtol returns `0` if unable to convert.)
    if (num == 0 && *argv[1] != '0') {
        printf("Unable to convert \"%s\" to an integer, exiting.", argv[1]);
        return 2;
    }
    
    bool printed = 0; // If we have printed a value.
    if (num != 0) {
        if (num % 3 == 0) {
            printf("Fizz");
            printed = true;
        }
        if (num % 5 == 0) {
            printf("Buzz");
            printed = true;
        }
    }

    if (!printed) printf("%i", num);
    // Add a line break
    printf("\n");


    return 0;
}
