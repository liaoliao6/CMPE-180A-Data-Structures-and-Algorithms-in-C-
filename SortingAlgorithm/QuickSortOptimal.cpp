#include "QuickSortOptimal.h"

Element& QuickSortOptimal::choose_pivot_strategy(const int left, const int right)
{
    int mid = (right + left) / 2;
    int position = 0;
    if(left <= mid && mid <= right)
        position = mid;
    else if(mid <= left && left <= right)
        position = left;
    else
        position = right;
    swap(position, right);
    return data[right];
}