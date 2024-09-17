#include <stdio.h>
#include <stdlib.h>

/* Print `array` of size `arrsize`. */
void print_array(int *array, int arrsize);

int main()
{
    int array[] = {-864, 2, 23, 435, 23, -4, 6765, 0, 3534, 9, 32, -92};
    int pos_i, i, pos_min, temp;

    int arrsize = sizeof array / sizeof array[0];

    for (pos_i = 0; pos_i < arrsize; pos_i++) {
        pos_min = pos_i;
        for (i = pos_i + 1; i < arrsize; i++) {
            if (array[i] < array[pos_min])
              pos_min = i;
        }

        // Swap only if necessary
        if (pos_min != pos_i) {
            temp = array[pos_min];
            array[pos_min] = array[pos_i];
            array[pos_i] = temp;
        }

        print_array(array, arrsize);
    }

    printf("\nSorted array:\n");
    print_array(array, arrsize);

    return EXIT_SUCCESS;
}

void print_array(int *array, int arrsize)
{
    printf("[");
    for (int j = 0; j < arrsize; j++) {
        if (j < arrsize - 1)
            printf("%i, ", array[j]);
        else
            printf("%i", array[j]);
    }
    printf("]\n");
}

