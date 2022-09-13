#include "InsertionSort.h"

void InsertionSort::run_sort_algorithm() throw (string)
{
    int i, j;
    for (i = 1; i < data.size(); i++)
    {
        j = i;

        while (j > 0 && data[j - 1] > data[j])
        {
            swap(j, j-1);
            j--;
        }

        compare_count = compare_count + i - j + 1;
    }

}

