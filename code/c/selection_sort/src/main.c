#include <stdio.h>

int main()
{
  int array[16] = {5, -8654, 2, 23, 435, 23, 23465, 4, 66765, 0, 3534, 9,  32, 76, -92, 10};
  int pos_i, i, pos_min, temp;

  // `sizeof` essentially returns the amount of bytes used up by a variable, in this case we want to know how many `int`s there are in `array`, so we divide by the size of that.
  // (We could just use 16, as it's not like the size is going to change, but where's the fun in that?)
  int arrsize = sizeof array / sizeof array[0];

  // `pos_i` = the index being sorted, additionally marks the end of the sorted subarray (exclusively)
  for (pos_i = 0; pos_i < arrsize; pos_i++)
  {
    // `pos_min` holds the index of the item to be swapped with `pos_i`, it will be updated whenever a lesser item is found
    pos_min = pos_i;
    for (i = pos_i + 1; i < arrsize; i++)
    {
      if (array[i] < array[pos_min])
        pos_min = i;
    }

    // Swap only if necessary
    if (pos_min != pos_i)
    {
      temp = array[pos_min];
      array[pos_min] = array[pos_i];
      array[pos_i] = temp;
    }
  }

  // Attempt to print out the items of `array` in a none-hideous format
  printf("[");
  for (int j = 0; j < arrsize; j++)
  {
    if (j < arrsize - 1)
      printf("%i, ", array[j]);
    // Don't print a trailing ", " for the last item in the array
    else
      printf("%i", array[j]);
  }
  printf("]\n");

  return 0;
}
