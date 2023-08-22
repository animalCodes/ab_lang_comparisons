# Selection sort

Note that while I use the term "array" through this specification, the underlying list data structure isn't overly important.

The most notable feature of this sorting algorithm is that it never "re-sorts" an item. that is, once an item is known to be in its correct position, it will not be touched - or even looked at - again.
This is accomplished by splitting the array into two subarrays, where the first subarray is entirely comprised of sorted items that will not be touched. On each iteration the current item is compared against all remaining items, if one is deemed "more valuable" the two values will be swapped, and so on until the "most valuable" item for that iteration is found.
Once the end of the array is reached, the same process is carried out with the next item, until the array is exhausted.

**Showcases**: Iterating through arrays, getting/setting values in arrays.

* For simplicity's sake, the initial array (from here on referred to as just `array`) should be hard-coded into the program itself, and to avoid confusion, all implementations should use the following set of values:
    * `[5, -8654, 2, 23, 435, 23, 23465, 4, 66765, 0, 3534, 9, 32, 76, -92, 10]`

* Create four (mutable) variables:
    * `pos_i`, represents the algorithm's current "*pos*ition" in `array`,
    * `i`, an iterator over the currently available portion of the array,
    * `pos_min`, the *pos*ition of the current *min*imum item, will be updated regularly,
    * `temp`, used to temporarily hold one of `array`'s values for swapping.

* Create a loop iterating until `pos_i` is greater than or equal to the length of `array`, increment `pos_i` on each iteration
    * A for loop is a good choice here, if available

* Inside the loop, set `pos_min` to `pos_i`
    * `pos_min` needs an initial value, and `pos_i` is as good as any

* Still inside the outer loop, create another with similar behaviour but iterating with + incrementing `i` instead of `pos_i`
    * This is for looping over the available portion of the array

* Inside the inner loop, if `array[i] < array[pos_min]`, set `pos_min` to `i`
    * This will sort the array from least to greatest numbers, to reverse use `array[i] > array[pos_min]`

* At the end of the outer loop, if `pos_min` does **not** equal `pos_i`, swap `array[pos_i]` and `array[pos_min]`, like so:
    * Set `temp` to `array[pos_min]`
    * Set `array[pos_min]` to `array[pos_i]`
    * And set `array[pos_i]` to `temp`

* After the outer loop has finished, print out the sorted array, ideally in a fashion that resembles the array in-source.

**Implemented in**: C.

**To be implemented in**: C++, C#, denoJS, Go, Java, Kotlin, Node.js, Ruby, Rust.

