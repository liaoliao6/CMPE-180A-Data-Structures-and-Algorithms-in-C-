#include "ShellSortSuboptimal.h"

void ShellSortSuboptimal::run_sort_algorithm() throw (string)
{
    for (int gap = data.size()/2; gap > 0; gap /= 2)
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