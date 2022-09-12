//
// Created by Sharon Dell unto on 29/08/2022.
//

#include "../../../include/push_swap.h"

void    rrr(t_stacks *stack)
{
    if (list_len(stack->a.head) < 2 && list_len(stack->b.head))
        return ;
    else if (list_len(stack->b.head) < 2)
        rra_rrb(&stack->a, 'a');
    else if (list_len(stack->a.head) < 2)
        rra_rrb(&stack->b, 'b');
    else
    {
        rra_rrb(&stack->a, 'a');
        rra_rrb(&stack->b, 'b');
    }
    write(1, "rrr\n", 4);
}

void    ss(t_stacks *stack)
{
    if (list_len(stack->a.head) < 2 && list_len(stack->b.head))
        return ;
    else if (list_len(stack->b.head) < 2)
        sa_sb(&stack->a, 'a');
    else if (list_len(stack->a.head) < 2)
        sa_sb(&stack->b, 'b');
    else
    {
        sa_sb(&stack->a, 'a');
        sa_sb(&stack->b, 'b');
    }
    write(1, "ss\n", 3);
}

void	rr(t_stacks *stack)
{
    if (list_len(stack->a.head) < 2 && list_len(stack->b.head))
        return ;
    else if (list_len(stack->b.head) < 2)
        ra_rb(&stack->a, 'a');
    else if (list_len(stack->a.head) < 2)
        ra_rb(&stack->b, 'b');
    else
    {
        ra_rb(&stack->a, 'a');
        ra_rb(&stack->b, 'b');
    }
    write(1, "rr\n", 3);
}