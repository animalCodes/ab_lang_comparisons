using System;

// C# selection_sort

public class Program
{
    public static void Main()
    {
        int[] array = [-864, 2, 23, 435, 23, -4, 6765, 0, 3534, 9, 32, -92];

        int pos, i, min, temp;

        for (pos = 0; pos < array.Length; pos++)
        {
            min = pos;
            for (i = pos+1; i < array.Length; i++)
            {
                if (array[i] < array[min])
                    min = i;
            }

            if (min != pos)
            {
                temp = array[min];
                array[min] = array[pos];
                array[pos] = temp;
            }

            Console.WriteLine("[" + string.Join(", ", array) + "]");
        }

        Console.WriteLine("Sorted array:");
        Console.WriteLine("[" + string.Join(", ", array) + "]");
    }
}
