#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

/* Return the index of the first occurence of `c` in `str`, or -1 if none
    found. */
int str_i(char c, char *str);

/* Return `c` shifted `shiftc` places up or down the alphabet. */
char shift(char c, int shiftc);

int main(int argc, char *argv[]) 
{
    if (argc < 3) {
        if (argc == 2)
            fprintf(stderr, "No message given, exiting.\n");
        else
            fprintf(stderr, "No shift or message given, exiting.\n");
        return EXIT_FAILURE;
    }

    char *end;
    int shiftc = strtol(argv[1], &end, 10);

    if (end == argv[1]) {
        fprintf(stderr, "Couldn't convert \"%s\" to an integer, exiting.\n",
                argv[1]);
        return EXIT_FAILURE;
    }

    for (int i = 2; i < argc; i++) {
        for (int j = 0; j < strlen(argv[i]); j++) {
            putchar(shift(argv[i][j], shiftc));
        }
        putchar(' ');
    }
    putchar('\n');

    return EXIT_SUCCESS;
}

int str_i(char c, char *str)
{
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == c)
            return i;
    }
    return -1;
}

char shift(char c, int shiftc)
{
    int length = strlen(alphabet);

    int index = str_i(c, alphabet);
    if (index == -1)
        // Don't try to shift none-alphabetical characters
        return c;

    index += shiftc;

    // "Wrap-around" on over/underflow
    index %= length;
    if (index < 0)
        index += length;

    return alphabet[index];
}
