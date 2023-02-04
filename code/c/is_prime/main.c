#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("No input received, exiting\n");
        return 1;
    }

    int num = atoi(argv[1]);
    if (num == 0 && *argv[1] != '0') {
        printf("Unable to convert %s to int, exiting\n", argv[1]);
        return 2;
    }

    if (num < 2) {
        printf("False\n");
        return 0;
    }

    for (int div = num-1; div > 1; div--) {
        if (num % div == 0) {
            printf("False\n");
            return 0;
        }
    }

    printf("True\n");
    return 0;
}
