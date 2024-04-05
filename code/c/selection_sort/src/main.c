#include <stdio.h>

int main()
{
  int array[16] = {5, -8654, 2, 23, 435, 23, 23465, 4, 66765, 0, 3534, 9,  32, 76, -92, 10};
  int pos_i, // Index currently being sorted
      i, // Position in unsorted subarray
      pos_min, // Position of currently known smallest number
      temp; // Temporarily holds an item during swapping

  // Figure out how many items are in `array`.
  // We could just use 16 here, but now you know how to do this if you didn't already :).
  int arrsize = sizeof array / sizeof array[0];

  for (pos_i = 0; pos_i < arrsize; pos_i++)
  {
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
