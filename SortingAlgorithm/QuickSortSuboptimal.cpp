#include "QuickSortSuboptimal.h"

Element& QuickSortSuboptimalRight::choose_pivot_strategy(const int left, const int right)
{
    swap(left, right);
    return data[right];
}