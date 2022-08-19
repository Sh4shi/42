
#include "../../include/push_swap.h"

int     max(int one, int two)
{
    if ( one > two)
        return (one);
    else
        return (two);
}

void    put_num(int *liss, int num, int len)
{
    int i;

    i = 0;
    while(i < len)
    {
        liss[i] = num;
        i++;
    }
}

void    liss(t_stack *stack)
{
    int *liss;
    int *arr;
    int len;
    int j;
    int i;

    len = list_len(stack->head);
    arr = list_to_array(stack, len);
    liss = (int *)malloc(sizeof(int) * len);
    put_num(liss, 1, len);
    i = 1;

    while(i < len)
    {
        j = 0;
        while(j < i)
        {
            if (arr[j] < arr[i])
                liss[i] = max(liss[i], liss[j] + 1);
            j++;
        }
        i++;
    }
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
