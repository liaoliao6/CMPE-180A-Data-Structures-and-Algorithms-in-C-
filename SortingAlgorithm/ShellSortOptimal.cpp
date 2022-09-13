#include "ShellSortOptimal.h"

void ShellSortOptimal::run_sort_algorithm() throw (string)
{
    int gap = 1;
    while (gap < data.size())
    {
        gap = gap * 3 + 1;
    }
    for (; gap > 0; gap/= 3)
    {
        for (int i = gap; i < data.size(); i += 1)
        {
            int j;
            for (j = i; j >= gap && data[j - gap] > data[j]; j -= gap)
                swap(j - gap, j);
            compare_count = compare_count + (i - j) / gap + 1;
        }
    }
}