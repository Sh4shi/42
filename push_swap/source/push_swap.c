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
    int count;
    int to_push;

    lenght = 0;
    count = 0;
    subseq = liss(&stack->a, &lenght);
    puts("LIS:");
    for (int i = 0; i < lenght; ++i)
        printf("%d ", subseq[i]);
    puts("\n-------------------");
    if (list_len(stack->a.head) != lenght)
    {
        push_liss(stack, subseq, lenght);
        to_push = fix_b(stack);
    }
    while (count < to_push)
    {
        ra_rb(&stack->a);
        count++;
        stack->moves += 1;
    }
    free(subseq);
}

int	main(int ac, char **av)
{
	t_stacks	stack;
    int         len;

	ft_bzero(&stack, sizeof(t_stacks));
	if (ac < 2 || !is_nbr(ac, av) || !get_num(&stack.a, ac, av) ||
		!is_ordered(&stack.a) || !duplicated(&stack.a))
		return (write(2, "Error\n", 6));
	else
		add_index(&stack.a);

    len = list_len(stack.a.head);
    if (len == 3)
        three_sort(&stack.a);
    else if (len == 5)
        five_sort(&stack, len);
    else
        start(&stack);

    printf("stack A:");
    for (t_node *node = stack.a.head; node; node = node->next)
        printf("%d|%d| ->  ", node->index, node->data);
    printf("\n");
    printf("stack b:");
    for(t_node *node = stack.b.head; node; node = node->next)
        printf("%d|%d| ->  ", node->index, node->data);
    printf("\nmoves: %d\n", stack.moves);


    free_list(&stack.a);
    free_list(&stack.b);
}
