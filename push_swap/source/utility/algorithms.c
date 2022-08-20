
#include "../../include/push_swap.h"

void    liss(t_stack *stack)
{
    int *liss;
    int *arr;
    int *subseq;
    int len;

    len = list_len(stack->head);
    arr = list_to_array(stack, len);
    liss = (int *)malloc(sizeof(int) * len);
    put_num(liss, 1, len);
    find_subsequence(liss, arr);
    subseq = get_subsequence(liss, arr, len);
}

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
