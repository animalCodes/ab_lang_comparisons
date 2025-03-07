
// Node.js selection_sort

const array = [-864, 2, 23, 435, 23, -4, 6765, 0, 3534, 9, 32, -92]

for (let pos_i = 0; pos_i < array.length; pos_i++) {
    let pos_min = pos_i
    for (let i = pos_i+1; i < array.length; i++) {
        if (array[i] < array[pos_min])
            pos_min = i
    }

    if (pos_min != pos_i) {
        let temp = array[pos_min]
        array[pos_min] = array[pos_i]
        array[pos_i] = temp
    }

    console.log("[" + array.join(", ") + "]")
}

console.log("Sorted array:")
console.log("[" + array.join(", ") + "]")
