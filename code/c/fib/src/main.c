#include <stdio.h>
#include <stdlib.h>

// C fib

/* `n`th fibonacci number. */
uint fib(uint n);

int main(int argc, char** argv)
{
    int n = 0;

    if (argc > 1)
        n = atoi(argv[1]);

    if (n <= 0) {
        printf("%d\n", n);
        return EXIT_SUCCESS;
    }

    printf("%d\n", fib(n));

    return EXIT_SUCCESS;
}

uint fib(uint n)
{
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}
