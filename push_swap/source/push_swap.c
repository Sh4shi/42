/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 21:10:43 by sdell-un          #+#    #+#             */
/*   Updated: 2022/08/24 21:05:23 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    reverse(t_stacks *stack, int *a, int *b)
{
    int i;
    int tmp;

    i = 0;
    if (*a > 0)
        tmp = MIN(*a, *b);
    else
        tmp = MAX(*a, *b);
    if (*a * *b > 0)
    {
        if (*a > 0)
        {
            while (i++ < ABS(tmp))
            {
                rr(stack);
                (*a)--;
                (*b)--;
            }
        }
        else
            while (i++ < ABS(tmp))
            {
                rrr(stack);
                (*a)++;
                (*b)++;
            }
    }
}

void    empty_stackb(t_stacks *stack)
{
    int i;
    int a;
    int b;

    i = 0;
    find_best(stack, &a, &b);
    reverse(stack, &a, &b);
    if (a > 0)
    {
        while (i++ < a)
            ra_rb(&stack->a, 'a', 1);
    }
    else
    {
        while (i++ < ABS(a))
            rra_rrb(&stack->a, 'a', 1);
    }
    i = 0;
    if (b > 0)
    {
        while (i++ < b)
            ra_rb(&stack->b, 'b', 1);
    }
    else
    {
        while (i++ < ABS(b))
            rra_rrb(&stack->b, 'b', 1);
    }
    pa(stack);
}

void    start(t_stacks *stack)
{
    int *subseq;
    int lenght;

    lenght = 0;
    subseq = liss(&stack->a, &lenght);
    push_liss(stack, subseq, lenght);
    while (list_len(stack->b.head) > 0)
        empty_stackb(stack);
    while (stack->a.head->index != 1)
        ra_rb(&stack->a, 'a', 1);
    free(subseq);
}

int	main(int ac, char **av)
{
	t_stacks	stack;
    int         len;

	ft_bzero(&stack, sizeof(t_stacks));
	if (ac < 2 || !is_nbr(ac, av) || !get_num(&stack.a, ac, av) || !duplicated(&stack.a))
		return (write(2, "Error\n", 6));
    if (!is_ordered(&stack.a))
        return 0;
    add_index(&stack.a);
    len = list_len(stack.a.head);
    if (len == 3)
        three_sort(&stack.a);
    else if (len == 5)
        five_sort(&stack, len);
    else
        start(&stack);

    /*printf("stack A:");
    for (t_node *node = stack.a.head; node; node = node->next)
        printf("%d|%d| ->  ", node->index, node->data);
    printf("\n");
    printf("stack b:");
    for(t_node *node = stack.b.head; node; node = node->next)
        printf("%d|%d| ->  ", node->index, node->data);*/

    free_list(&stack.a);
    free_list(&stack.b);
}
