#include <stdio.h>

int main(int argc, char **argv)
{
    for (int i = 1; i < argc; i++) {
        printf("%s", argv[i]);
        // Only print spaces between arguments
        if (i+1 < argc)
            putchar(' ');
    }
    putchar('\n');
}
