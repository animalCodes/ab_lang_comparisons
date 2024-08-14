#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    double square = 0;
    if (argc > 1)
        square = strtod(argv[1], NULL);

    if (square == 0) {
        printf("%s\n", argv[1]);
        return 0;
    } else if (isnan(square) || square < -0) {
        printf("NaN\n");
        return 0;
    } else if (isinf(square) == 1) {
        printf("+Infinity\n");
        return 0;
    }

    double prev, guess = 1;

    // Compute integer digits
    while (1) {
        prev = floor(guess);
        guess = (guess + (square / guess)) / 2;
        if (prev == floor(guess))
            break;
    }

    // Compute first five decimal digits
    guess = (guess + (square / guess)) / 2;
    guess = (guess + (square / guess)) / 2;
    guess = (guess + (square / guess)) / 2;
    guess = (guess + (square / guess)) / 2;
    guess = (guess + (square / guess)) / 2;
    guess = (guess + (square / guess)) / 2; // +1 to be safe

    printf("%.5lf", guess);
}