
#include "../../include/push_swap.h"

int     find_lis_len(int *liss, int len, int *pos)
{
    int i;
    int lenght;

    i = 0;
    lenght = liss[0];
    while (i < len)
    {
       lenght = max(lenght, liss[i]);
       *pos = i;
        i++;
    }
    return (lenght);
}

int *get_subsequence(int *liss, int *arr, int len)
{
    int *subseq;
    int i;
    int lenght;
    int pos;

    lenght = find_lis_len(liss, len, &pos);
    i = lenght - 1;
    subseq = (int *)malloc(sizeof(int) * lenght);
    while (i >= 0 && pos >= 0)
    {
        subseq[i] = arr[pos];
        while ( pos >= 0 && (liss[pos] == (i + 1) || liss[pos] != i ))
            pos--;
        i--;
    }
    return (subseq);
}

int     max(int one, int two)
{
    if ( one > two)
        return (one);
    else
        return (two);
}

void    find_subsequence(int *liss, const int *arr, int len)
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
