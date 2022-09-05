
#include "../include/push_swap.h"

void     check_bigger(t_stacks *stack, int *subseq, int lenght)
{
    if (!data_is_in_lis(stack->a.tail->data, subseq, lenght))
    {
        if ((stack->a.tail->data < stack->a.head->data) &&
                (stack->a.tail->data < stack->a.head->next->data))
        {
            rra_rrb(&stack->a);
            stack->moves += 1;
        }
    }
    if (!data_is_in_lis(stack->a.head->next->data, subseq, lenght))
    {
        if (stack->a.head->next->data < stack->a.head->data)
        {
            sa_sb(&stack->a);
            stack->moves += 1;
        }
    }
}

bool    data_is_in_lis(int data, int *subseq, int len)
{
    int i;

    i = 0;
    while (i < len)
    {
        if (data == subseq[i])
            return (true);
        i++;
    }
    return (false);
}

void    push_liss(t_stacks *stack, int *subseq, int lenght)
{
    while (list_len(stack->a.head) != lenght)
    {
        if (!data_is_in_lis(stack->a.head->data, subseq, lenght))
        {
            check_bigger(stack, subseq, lenght);
            pb(stack);
            stack->moves += 1;
        }
        else if (list_len(stack->a.head) != lenght)
        {
            while (data_is_in_lis(stack->a.head->data, subseq, lenght))
            {
                ra_rb(&stack->a);
                stack->moves += 1;
            }
        }
    }
    while (stack->a.head->index != 0)
    {
        ra_rb(&stack->a);
        stack->moves += 1;
    }
}
