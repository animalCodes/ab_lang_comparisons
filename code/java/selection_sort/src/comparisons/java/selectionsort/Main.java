package comparisons.java.selectionsort;

import java.util.ArrayList;

// Java selection_sort

class Main {
    public static void main(String[] args) {
        ArrayList<Integer> array = initArray();

        int pos_min, i, temp;

        for (int pos_i = 0; pos_i < array.size(); pos_i++) {
            pos_min = pos_i;
            for (i = pos_i+1; i < array.size(); i++) {
                if (array.get(i) < array.get(pos_min))
                    pos_min = i;
            }

            if (pos_min != pos_i) {
                temp = array.get(pos_min);
                array.set(pos_min, array.get(pos_i));
                array.set(pos_i, temp);
            }

            System.out.println(array);
        }

        System.out.println("Sorted array:");
        System.out.println(array);
    }

    /**
     * Construct and initialise the array to be sorted.
     *
     * @return The demo array.
     */
    private static ArrayList<Integer> initArray() {
        // We could use a static array here, but `ArrayList`s are more commonly
        // used.
        ArrayList<Integer> array = new ArrayList<>();
        array.add(-864);
        array.add(2);
        array.add(23);
        array.add(435);
        array.add(23);
        array.add(-4);
        array.add(6765);
        array.add(0);
        array.add(3534);
        array.add(9);
        array.add(32);
        array.add(-92);
        array.trimToSize();
        return array;
    }
}
