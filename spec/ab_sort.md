# Animal's Basic Sort

Note: I will use "array" to refer to an associated collection of values that can be iterated through, different languages prefer different types such as linked lists or vectors, so always use what is most appropriate for the given language.

The basic idea of this algorithm is to never "re-sort" an item, that is, once we know for sure than an item in the array is in its correct position, it will not be touched - or even looked at - again.
This is accomplished through the use of a "buffer", essentially on every pass the algorithm will shrink how much of the array it operates on, with each iteration locating the "most valuable" item for the current portion of the array.

**Showcases**: Iterating through arrays, getting/setting values in arrays.

* For simplicities' sake, the initial array (from here on referred to as just `array`) should be hard-coded into the program itself, and to avoid confusion, all implementations should use the following set of values:
    * `[5, -8654, 2, 23, 435, 23, 23465, 4, 66765, 0, 3534, 9, 32, 76, -92, 10]`

* Create three (mutable) variables:
    * `i`, represents an index in the `array`, initial value 0
    * `pos_i`, repesents the algorithm's current "*pos*ition" in `array`, initial value 0
    * `temp`, used to temporarily hold one of `array`'s values, must be the same type as the array's items, initial value doesn't matter.

* Loop until `pos_i` is greater than or equal to the length of `array`
    * And at the end of each loop, increment `pos_i` by one and set `i` to `pos_i + 1`

* Create another loop inside the body of *that* loop that will iterate until `i` is greater than or equal to the length of `array`.
    * Increment `i` by one at the end of the *inner* loop

* Now for the fun part, if `array[i] < array[pos_i]`, we need to "swap" `array[i]` and `array[pos_i]`, like so:
    * Set `temp` to `array[i]`
    * Set `array[i]` to `array[pos_i]`
    * And set `array[pos_i]` to `temp`
    * In that exact order, otherwise the universe will collapse

* After the outer loop has finished, print out the sorted array, ideally in a fashion that resembles the array in source.

**Implemented in**: 

**To be implemented in**: C, C++, C#, denoJS, Go, Java, Kotlin, Node.js, Ruby, Rust.

