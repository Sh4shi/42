//
// Created by Sharon on 11/09/22.
//

#include "../include/push_swap.h"

int     find_list_max(t_node *node)
{
    int max;

    max = node->data;
    while (node)
    {
        if (node->data > max)
            max = node->data;
        node = node->next;
    }
    return (max);
}

int     find_list_min(t_node *node)
{
    int min;

    min = node->data;
    while (node)
    {
        if (node->data < min)
            min = node->data;
        node = node->next;
    }
    return (min);
}

void    three_sort(t_stack *stack)
{
    int max;
    int min;

    max = find_list_max(stack->head);
    min = find_list_min(stack->head);
    if (stack->head->data == min)
    {
        rra_rrb(stack, 'a', 1);
        sa_sb(stack, 'a', 1);
    }
    else if (stack->tail->data == min)
    {
        if(stack->head->data == max)
        {
            sa_sb(stack, 'a', 1);
            rra_rrb(stack, 'a', 1);
        }
        else
            rra_rrb(stack, 'a', 1);
    }
    else if (stack->head->data == max)
        ra_rb(stack, 'a', 1);
    else
        sa_sb(stack, 'a', 1);
}