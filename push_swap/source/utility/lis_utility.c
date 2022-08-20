
#include "../../include/push_swap.h"

int     find_lis_len(int *liss, int len)
{
    int i;
    int lenght;

    i = 0;
    lenght = 1;
    while (i < len)
    {
        if (lenght < liss[i])
            lenght += 1;
        i++;
    }
    return (lenght);
}

int *get_subsequence(int *liss, int *arr, int len)
{
    int *subseq;
    int i;
    int lenght;
    int x;

    i = lenght;
    x = lenght;
    lenght = find_lis_len(liss, len);
    subseq = (int *)malloc(size of(int) * lenght);
    while (i > 0)
    {
        while (len > 0 && x > 0)
        {
            if (x == liss[i])
            {
                subseq[i] = arr[len];
                x -= 1;
            }
            len--;
        }
        i--;
    }
    free (liss);
    free (arr);
    return (subseq);
}

int     max(int one, int two)
{
    if ( one > two)
        return (one);
    else
        return (two);
}

void    find_subsequence(int *liss, int *arr)
{
    int i;
    int j;

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
