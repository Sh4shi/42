//
// Created by Sharon Dell unto on 29/08/2022.
//

#include "../../../include/push_swap.h"

void    rrr(t_stacks *stack)
{
    if (list_len(stack->a.head) < 2 && list_len(stack->b.head))
        return ;
    else if (list_len(stack->b.head) < 2)
        rra_rrb(&stack->a);
    else if (list_len(stack->a.head) < 2)
        rra_rrb(&stack->b);
    else
    {
        rra_rrb(&stack->a);
        rra_rrb(&stack->b);
    }
}

void    ss(t_stacks *stack)
{
    if (list_len(stack->a.head) < 2 && list_len(stack->b.head))
        return ;
    else if (list_len(stack->b.head) < 2)
        sa_sb(&stack->a);
    else if (list_len(stack->a.head) < 2)
        sa_sb(&stack->b);
    else
    {
        sa_sb(&stack->a);
        sa_sb(&stack->b);
    }
}

void	rr(t_stacks *stack)
{
    if (list_len(stack->a.head) < 2 && list_len(stack->b.head))
        return ;
    else if (list_len(stack->b.head) < 2)
        ra_rb(&stack->a);
    else if (list_len(stack->a.head) < 2)
        ra_rb(&stack->b);
    else
    {
        ra_rb(&stack->a);
        ra_rb(&stack->b);
    }
}