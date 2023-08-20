#include <stdio.h>

int main()
{
    int array[16] = {5, -8654, 2, 23, 435, 23, 23465, 4, 66765, 0, 3534, 9, 32, 76, -92, 10};

    // Make sure to initialise the indices with a value, otherwise bad things will happen.
    int i=0, pos_i=0, temp;

    // `sizeof()` essentially returns the amount of bytes used up by a variable, in this case we want to know how many `int`s there are in `array`, so we divide by the size of that.
    // (We could just use 16, as it's not like the size is going to change, but where's the fun in that?)
    int arrsize = sizeof(array) / sizeof(array[0]);

    // Outer loop, controls the size of the buffer
    while (pos_i < arrsize)
    {
        // Inner loop, operates on the available portion of the array
        for (; i < arrsize; i++)
        {
            // Here is where you could fiddle with how a "more valuable" item is defined
            if (array[i] < array[pos_i])
            {
                temp = array[i];
                array[i] = array[pos_i];
                array[pos_i] = temp;
            }
        }
        pos_i++;
        // Note: setting `i` to 0 here will cause the array to be sorted backwards
        i = pos_i+1;
    }
    
    // Attempt to print out the items of `array` in a none-hideous fashion
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
