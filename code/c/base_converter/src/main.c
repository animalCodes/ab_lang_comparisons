#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// C base_converter

/* Print the value of `n` in binary. */
void print_binary(uint n);

int main(int argc, char** argv)
{
    if (argc < 3) {
        if (argc < 2)
            printf("No base or number specified, exiting.\n");
        else
            printf("No number specified, exiting.\n");
        return EXIT_FAILURE;
    }

    char *end;
    int n = strtol(argv[2], &end, 10);

    if (end == argv[2]) {
        printf("\"%s\" isn't a decimal integer, exiting.\n", argv[2]);
        return EXIT_FAILURE;
    }

    if (!n) {
        printf("0\n");
        return EXIT_SUCCESS;
    }

    int base = atoi(argv[1]);

    uint m = abs(n);
    if (n < 0)
        putchar('-');

    if (base == 2) 
        print_binary(m);
    else if (base == 8)
        printf("%o\n", m);
    else if (base == 16)
        printf("%X\n", m);
    else {
        printf("Base must be 2, 8, or 16, exiting.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void print_binary(uint n)
{
    // The floored base 2 logarithm of n will give us how many bits we need - 1.
    // Add another for the null byte.
    int len = floor(log2((double)n)) + 2;
    char out[len];
    out[len-1] = '\0';

    div_t res = {n, 0}; // {quotient, remainder}
    for (int i = len-2; res.quot > 0; i--) {
        res = div(res.quot, 2);
        out[i] = (res.rem == 1) ? '1' : '0';
    }

    printf("%s\n", out);
}
