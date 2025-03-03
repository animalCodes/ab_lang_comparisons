#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// C sqrt

int main(int argc, char *argv[])
{
    char *end;
    double square = 0;
    if (argc > 1)
        square = strtod(argv[1], &end);

    if (end == argv[1] || square < 0 ||
        (isinf(square) == 1) || isnan(square)) {
        printf("NaN\n");
        return 0;
    }

    if (square == 0) {
        printf("%.5lf\n", square);
        return 0;
    }

    double prev, guess = 1;

    while (1) {
        prev = floor(guess);
        guess = (guess + (square / guess)) / 2;
        if (prev == floor(guess))
            break;
    }

    guess = (guess + (square / guess)) / 2;
    guess = (guess + (square / guess)) / 2;

    printf("%.5lf\n", guess);
}
