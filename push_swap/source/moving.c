
#include "../include/push_swap.h"

int lower_num(t_stack *stack)
{
    int num;
    t_node *min;


}

int bigger_num(t_stack *stack) {
    int num;
    t_node *node;

    node = stack->head;
    num = node->index;
    while (node) {
        if (node->index > num)
            num = node->index;
        node = node->next;
    }
    return (num);
}

int fix_b(t_stacks *stack) {
    int count;

    count = 0;
    while (list_len(stack->b.head) > 0) {
        if (list_len(stack->b.head) > 1) {
            if (stack->b.head->index != bigger_num(&stack->b))
                ra_rb(&stack->b);
            else {
                pa(stack);
                count += 1;
            }
        } else {
            pa(stack);
            count += 1;
        }
    }
    return (count);
}