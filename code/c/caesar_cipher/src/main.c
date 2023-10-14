#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ideally this would be const, but its used in indexOf() which wants a none-const string.
// As such, the const qualifier would be discarded if present.
char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

// Returns the index of the first occurence of `needle` in `haystack`, or -1 if none exists.
int indexOf(char needle, char *haystack) 
{
  // I don't know if I'm being dumb but I couldn't find an equivalent in the standard library.
  for (int i = 0; i < strlen(haystack); i++) {
    if (haystack[i] == needle)
      return i;
  }
  return -1;
}

// Returns `original_char` shifted `shiftc` (Shift Count) places up or down the alphabet.
char shift(char original_char, int shiftc)
{
  // Repeatedly calling strlen() caused sanity to cease, I'm talking 26 + -3 = 19.
  // I don't know why, and I don't know why this fixes it, but it does.
  int alphabet_length = strlen(alphabet);

  int index = indexOf(original_char, alphabet);
  if (index == -1)
    // Don't try to shift none-alphabetical characters
    return original_char;

  index += shiftc;

  // Avoid overflow, but allow wrap-around shifts.
  while (index >= alphabet_length)
    index -= alphabet_length;

  // Same idea as above, but for negative shifts.
  while (index < 0)
    index += alphabet_length;

  return alphabet[index];
}

int main(int argc, char *argv[]) 
{
  if (argc < 3) {
    if (argc == 2)
      fprintf(stderr, "No message given, exiting.\n");
    else
      fprintf(stderr, "No shift or message given, exiting.\n");
    return 1;
  }

  int shiftc = atoi(argv[1]);
  if (!shiftc) { // This is C, so 0 is false.
    // Allow for '0' or similarly "-0", "+0", etc.
    if (argv[1][0] != '0' && argv[1][1] != '0') {
      fprintf(stderr, "Couldn't convert \"%s\" to an integer, exiting.\n", argv[1]);
      return 1;
    }
    // We'll let the user shift the message 0 places if they want to.
  }

  // Run `shift()` on every character in every argument after shiftc
  for (int i = 2; i < argc; i++) {
    for (int j = 0; j < strlen(argv[i]); j++) {
      printf("%c", shift(argv[i][j], shiftc));
    }
  }
  printf("\n");

  return 0;
}