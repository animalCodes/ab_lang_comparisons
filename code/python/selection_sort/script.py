# Python selection_sort

array = [-864, 2, 23, 435, 23, -4, 6765, 0, 3534, 9, 32, -92]

for i in range(len(array)):
    min = i
    for j in range(i+1, len(array)):
        if array[j] < array[min]:
            min = j

    if min != i:
        t = array[min]
        array[min] = array[i]
        array[i] = t

    print(array)

print("Sorted array:")
print(array)
