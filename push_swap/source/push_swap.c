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

void    start(t_stacks *stack)
{
    int *subseq;
    int lenght;

    lenght = 0;
    subseq = liss(&stack->a, &lenght);
    if (list_len(stack->a.head) != lenght)
        push_liss(stack, subseq, lenght);
    if (list_len(stack->b.head) > 0)
    {
        fix_b(stack);
        while (stack->a.head->index > 0)
            ra_rb(&stack->a);
    }
}

int	main(int ac, char **av)
{
	t_stacks	stack;

	ft_bzero(&stack, sizeof(t_stacks));
	if (ac < 2 || !is_nbr(ac, av) || !get_num(&stack.a, ac, av) ||
		!is_ordered(&stack.a) || !duplicated(&stack.a))
		return (write(2, "Error\n", 6));
	else
		add_index(&stack.a);
    start(&stack);
    for (t_node *node = stack.a.head; node; node = node->next)
        printf("stack A:%d   i)%d\n", node->data, node->index);
    for(t_node *node = stack.b.head; node; node = node->next)
        printf("stack B:%d   i)%d\n", node->data, node->index);
    free_list(&stack.a);
    free_list(&stack.b);
}
