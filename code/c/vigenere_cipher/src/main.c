#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// C vigenere_cipher

const char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

/* Read input from stdin until '\n' is received. */
char *readline();

/* Shift `c`, `k` places.
    `c` and `k` Must be alphabetical characters. */
char shift(char c, char k);

/* Index of first occurence of `needle` in `haystack`. Or -1 if not found. */
int str_i(const char *haystack, char needle);

int main(int argc, char **argv)
{
    if (argc < 2) {
        fprintf(stderr, "No message given, exiting.\n");
        return 1;
    }

    printf("Enter key: ");
    char *key = readline();
    int keylen = strlen(key);

    if (keylen <= 0) {
        fprintf(stderr, "No key given, exiting.\n");
        return 1;
    }

    for (int i = 0; key[i] != '\0'; i++) {
        if (!isalpha(key[i])) {
            printf("Key contains non-alphabetical characters, exiting.\n");
            return 1;
        }
    }

    int k = 0;
    for (int i = 1; i < argc;) {
        for (int j = 0; argv[i][j] != '\0'; j++) {
            if (isalpha(argv[i][j]))
                putchar(shift(argv[i][j], key[k++]));
            else
                putchar(argv[i][j]);
            // Don't actually need to extend `key` :P
            if (k >= keylen)
                k = 0;
        }
        if (++i <= argc)
            putchar(' ');
    }

    putchar('\n');

    free(key);
}

char *readline()
{
    size_t size = 80;
    char *buf = calloc(sizeof (char), size);
    int offset = 0;

    buf[offset] = fgetc(stdin);
    while (buf[offset] != EOF && buf[offset] != '\n') {
        if (offset >= (size - 1))
            buf = realloc(buf, (size *= 2));
        buf[++offset] = fgetc(stdin);
    }

    buf[offset] = '\0';
    return buf;
}

char shift(char c, char k)
{
    return alphabet[(str_i(alphabet, c) + str_i(alphabet, k)) % 26];
}

int str_i(const char *haystack, char needle)
{
    for (int i = 0; haystack[i] != '\0'; i++) {
    if (haystack[i] == needle)
        return i;
    }
    return -1;
}
