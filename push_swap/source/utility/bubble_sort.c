
#include "../../include/push_swap.h"

void    bubble_sort(int *arr, int len)
{
    int i;
    int y;
    int temp;

    i = 0;
    while (i < len)
    {
        y = i;
        while (y < len)
        {
            if (arr[i] > arr[y])
            {
                temp = arr[i];
                arr[i] = arr[y];
                arr[y] = temp;
            }
            y++;
        }
        i++;
    }
}
