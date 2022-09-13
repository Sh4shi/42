//
// Created by Sharon on 11/09/22.
//

#include "../include/push_swap.h"

void    three_sort(t_stack *stack)
{
    if (stack->head == stack->min)
    {
        rra_rrb(stack, 'a', 1);
        sa_sb(stack, 'a', 1);
    }
    else if (stack->tail == stack->min)
    {
        if(stack->head == stack->max)
        {
            sa_sb(stack, 'a', 1);
            rra_rrb(stack, 'a', 1);
        }
        else
            rra_rrb(stack, 'a', 1);
    }
    else if (stack->head == stack->max)
        ra_rb(stack, 'a', 1);
    else
        sa_sb(stack, 'a', 1);
}