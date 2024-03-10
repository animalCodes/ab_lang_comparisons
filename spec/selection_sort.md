# Selection sort

The most notable feature of this sorting algorithm is that it never "re-sorts" an item. that is, once an item is known to be in its correct position, it will not be touched - or even looked at - again.

This is accomplished by splitting the array into two (conceptual) subarrays, where the first subarray is entirely comprised of sorted items that will not be touched again. 
On each iteration the current item is compared against all remaining items, if one is deemed "more valuable" the two values will be swapped, and so on until the "most valuable" item for that iteration is found.
Once the end of the array is reached, the same process is carried out with the next item, until the array is exhausted.

## Implementation

For simplicity's sake, the initial array (from here on referred to as just "array") should be hard-coded into the program itself, and to avoid confusion, all implementations should use the following set of values:
* `[5, -8654, 2, 23, 435, 23, 23465, 4, 66765, 0, 3534, 9, 32, 76, -92, 10]`

Sort from least to greatest.

* Iterate over array (for i).
  * On every iteration, find the minimum value element past array[i].
  * If the found element isn't equal to array[i], swap them.

* Print the sorted array in the format shown above.

**Implemented in**: C.

**To be implemented in**: C++, C#, denoJS, Go, Java, Kotlin, Node.js, Ruby, Rust.

