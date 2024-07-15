#include <stdio.h>
#include <stdlib.h> // Just for EXIT_SUCCESS

int main() {
  // Note: As there is no formatting used here, we could replace this with
  // `puts()`. However, using `printf()` is more consistent and depending on the
  // compiler this may be done for us.
  printf("Hello, World!\n");
  return EXIT_SUCCESS;
}
