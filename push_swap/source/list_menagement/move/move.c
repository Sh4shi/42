//
// Created by Sharon Dell unto on 8/24/22.
//


#include "../../../include/push_swap.h"
/*
void    swap_head_tail(t_stack *stack)
{
    if (list_len(stack->head) < 2)
        return ;
    stack->tail->next = stack->head->next;
    stack->tail->prev->next = stack->head;
    stack->head->prev = stack->tail->prev;
    stack->head->next->prev = stack->tail;
    stack->tail = stack->tail->prev->next;
    stack->head = stack->head->next->prev;
    stack->tail->next = 0;
    stack->head->prev = 0;
}
*/
void    pb(t_stacks *stack)
{
    if (!(stack->a.head))
        return ;
    if (!(stack->b.head))
    {
        stack->b.head = stack->a.head;
        stack->a.head = stack->a.head->next;
        stack->a.head->prev = 0;
        stack->b.head->prev = 0;
        stack->b.tail = stack->b.head;
        stack->b.head->next = stack->b.tail;
        stack->b.tail->prev = stack->b.head;
        stack->b.tail->next = 0;
        return ;
    }
    if (list_len(stack->a.head) == 1)
    {
        stack->b.head->prev = stack->a.head;
        ft_bzero(&stack->a, sizeof(t_stack));
        stack->b.head->prev->next = stack->b.head;
        stack->b.head = stack->b.head->prev;
        stack->b.head->prev = 0;
        return ;
    }
    stack->b.head->prev = stack->a.head;
    stack->a.head = stack->a.head->next;
    stack->b.head->prev->next = stack->b.head;
    stack->a.head->prev = 0;
    stack->b.head = stack->b.head->prev;
    stack->b.head->prev = 0;
}

void    pa(t_stacks *stack)
{
    if (!(stack->b.head))
        return ;
    if (!(stack->a.head))
    {
        stack->a.head = stack->b.head;
        stack->b.head = stack->b.head->next;
        stack->b.head->prev = 0;
        stack->a.head->prev = 0;
        stack->a.tail = stack->a.head;
        stack->a.head->next = stack->a.tail;
        stack->a.tail->prev = stack->a.head;
        stack->a.tail->next = 0;
        return ;
    }
    if (list_len(stack->b.head) == 1)
    {
        stack->a.head->prev = stack->b.head;
        ft_bzero(&stack->b, sizeof(t_stack));
        stack->a.head->prev->next = stack->a.head;
        stack->a.head = stack->a.head->prev;
        stack->a.head->prev = 0;
        return ;
    }
    stack->a.head->prev = stack->b.head;
    stack->b.head = stack->b.head->next;
    stack->a.head->prev->next = stack->a.head;
    stack->b.head->prev = 0;
    stack->a.head = stack->a.head->prev;
    stack->a.head->prev = 0;
}

void    rra_rrb(t_stack *stack)
{
    if (list_len(stack->head) < 2)
        return ;
    stack->tail->next = stack->head;
    stack->head->prev = stack->tail;
    stack->tail = stack->tail->prev;
    stack->tail->next = 0;
    stack->head->prev->prev = 0;
    stack->head = stack->head->prev;
}

void    ra_rb(t_stack *stack)
{
    if (list_len(stack->head) < 2)
        return ;
    stack->head->prev = stack->tail;
    stack->tail->next = stack->head;
    stack->head = stack->head->next;
    stack->head->prev = 0;
    stack->tail = stack->tail->next;
    stack->tail->next = 0;
}

void    sa_sb(t_stack *stack)
{
    if (list_len(stack->head) < 2)
        return ;
    stack->head = stack->head->next;
    stack->head->prev->next = stack->head->next;
    stack->head->prev->prev = stack->head;
    if (stack->head->next)
        stack->head->next->prev = stack->head->prev;
    stack->head->next = stack->head->prev;
    stack->head->prev = 0;
}