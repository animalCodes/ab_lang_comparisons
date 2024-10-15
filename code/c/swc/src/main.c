#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define HELP_MESSAGE                                                           \
"Usage: swc [options] file\n"                                                  \
"Print newline, word and byte counts for file. A word is a sequence of\n"      \
"non-whitespace delimited by whitespace or start/end of input.\n\n"            \
                                                                               \
"The options below may be used to select which counts are printed, always in\n"\
"the following order: newline, word, byte.\n"                                  \
"  -c  print byte count.\n"                                                    \
"  -l  print newline count.\n"                                                 \
"  -w  print word count.\n"                                                    \
"  -h  display this help and exit.\n"                                          \

const char *valid_opts = "lwch";

/* Return value of count(). */
typedef struct {
    int newlines;
    int words;
    int bytes;
} counts_t;

/* Parse command-line options.
    Returns the sum of the set options:
        'l' = 4, 'w' = 2, 'c' = 1. If 'h' is found, 8 is returned.
    If an invalid option (not listed in valid_opts) is found, -1 is returned and
        optopt will be set to the invalid character.
    After calling this optind will be an index into argv of the first non-option
        element. */
int parse_opts(int argc, char *argv[]);

/* Count newlines, words and bytes in `file`. */
counts_t count(FILE *file);

int main(int argc, char *argv[])
{
    int opts = parse_opts(argc, argv);
    if (opts == 8) {
        printf(HELP_MESSAGE);
        return EXIT_SUCCESS;
    }

    if (opts == -1) {
        printf("Invalid option \"%c\", try \"swc -h\" for help.\n", optopt);
        return EXIT_FAILURE;
    }

    if (optind >= argc) {
        fprintf(stderr, "No file specified, exiting.\n");
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[optind], "r");
    if (file == NULL) {
        fprintf(stderr, "Cannot access file \"%s\"\n", argv[optind]);
        return EXIT_FAILURE;
    }

    counts_t counts = count(file);

    if (opts >= 4) {
        opts -= 4;
        printf("%d", counts.newlines);
        if (opts > 0)
            putchar(' ');
    }

    if (opts >= 2) {
        opts -= 2;
        printf("%d", counts.words);
        if (opts > 0)
            putchar(' ');
    }

    if (opts) {
        printf("%d", counts.bytes);
    }
    putchar('\n');

    fclose(file);
}

int parse_opts(int argc, char *argv[])
{
    opterr = 0; // Stop getopt from printing it's own error messages.
    int opts = 0;
    char opt;
    while ((opt = getopt(argc, argv, valid_opts)) != -1) {
        switch (opt) {
            // OR rather than addition to stop duplicate options from breaking
            // everything
            case 'l': 
                opts |= 4; break;
            case 'w':
                opts |= 2; break;
            case 'c':
                opts |= 1; break;
            case 'h':
                return 8;
                return EXIT_SUCCESS;
            default:
                return -1;
        }
    }

    // If no options were set, treat as "-lwc"
    if (!opts)
        return 7;

    return opts;
}

counts_t count(FILE *file)
{
    counts_t counts = {0, 0, 0};
    char buffer[80]; // Buffer size is entirely arbitrary
    bool space = true; // Initialise to true in order to detect a word at the
                       // very start of file.

    // Count newlines, words and bytes all in one go, this of course leads to a
    // bunch of unnecessary work when not all options are set, but only counting
    // them if they are set would be fiddly and only result in slightly less
    // operations being performed, as in any case we still need to read and
    // iterate over the contents of the entire file.
    while (fgets(buffer, 80, file) != NULL) {
        int i = 0;
        for (; buffer[i] != '\0'; i++) {
            if (buffer[i] == '\n')
                counts.newlines++;

            if (!isspace(buffer[i]) && space) {
                space = false;
                counts.words++;
            } else if (isspace(buffer[i]))
                space = true;
        }
        counts.bytes += i;
    }

    return counts;
}
