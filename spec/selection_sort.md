# Selection sort

Selection sort is a sorting algorithm which, while not being particularly efficient, is much easier to understand than many other sorting algorithms.

### Invocation

`selection_sort`

### Examples

| Input            | Output                                                  |
| ---------------- | ------------------------------------------------------- |
| `selection_sort` | `[-864, -92, -4, 0, 2, 9, 23, 23, 32, 435, 3534, 6765]` |

## Implementation

### Functions

- `size(array)` - The number of elements in `array`.

- `print_arr(array)` - Print the members of `array`, deliminated by ", ", surrounded by square brackets.

### Code

> The basic operation of selection sort is as follows:
>
> Split the array into two (conceptual) subarrays, where the first is comprised of sorted items. (At first it will only have one member)
>
> On each iteration, compare the next item against all others in the unsorted subarray, until the least - or greatest - is found.
>
> At the end of each iteration, the "most valuable" item is swapped with the current one.
>
> The above process is repeated until the sorted subarray has entirely consumed the unsorted one.

> This implementation uses the following variables:
>
> - `array`, the static array to be sorted.
>
> - `pos_i`, index currently being sorted.
>
> - `i`, position in unsorted subarray.
>
> - `pos_min`, position of currently known smallest number.
>
> - `temp`, used for swapping; temporarily holds the value of a member.

> Sort from least to greatest.

```
array = [-864, 2, 23, 435, 23, -4, 6765, 0, 3534, 9, 32, -92]

for (pos_i = 0; pos_i < size(array); pos_i++) {
    pos_min = pos_i
    for (i = pos_i + 1; i < size(array); i++) {
        if (array[i] < array[pos_min])
            pos_min = i
    }

    if (pos_min != pos_i) {
        temp = array[pos_min]
        array[pos_min] = array[pos_i]
        array[pos_i] = temp
    }
}

print_arr(array)
```

**Implemented in**: C.

**To be implemented in**: C++, C#, denoJS, Go, Java, Kotlin, Node.js, Ruby, Rust.

