//
// Created by Sharon Dell unto on 8/24/22.
//


#include "../../../include/push_swap.h"

//void    sa_sb(t_node *node)
//{
//    if (list_len(node) < 2)
//        return ;
//    node = node->next;
//    node->prev->next = node->next;
//    node->prev->prev = node;
//    if (node->next)
//        node->next->prev = node->prev;
//    node->next = node->prev;
//    node->prev = 0;
//}

//void    ra_rb(t_stack *stack)
//{
//    set_circular(stack);
//    sa_sb(stack->tail);
//    set_linear(stack);
//}

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