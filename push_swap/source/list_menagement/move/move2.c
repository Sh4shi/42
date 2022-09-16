/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 00:52:12 by sdell-un          #+#    #+#             */
/*   Updated: 2022/09/17 00:52:14 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

void	pb_sup(t_stacks *stack)
{
	stack->b.head = stack->a.head;
	stack->a.head = stack->a.head->next;
	stack->a.head->prev = 0;
	stack->b.head->prev = 0;
	stack->b.tail = stack->b.head;
	stack->b.head->next = stack->b.tail;
	stack->b.tail->prev = stack->b.head;
	stack->b.tail->next = 0;
	write(1, "pb\n", 3);
}

void	pb(t_stacks *stack)
{
	if (!(stack->a.head))
		return ;
	if (!(stack->b.head))
	{
		pb_sup(stack);
		return ;
	}
	if (list_len(stack->a.head) == 1)
	{
		stack->b.head->prev = stack->a.head;
		ft_bzero(&stack->a, sizeof(t_stack));
		stack->b.head->prev->next = stack->b.head;
		stack->b.head = stack->b.head->prev;
		stack->b.head->prev = 0;
		write(1, "pb\n", 3);
		return ;
	}
	stack->b.head->prev = stack->a.head;
	stack->a.head = stack->a.head->next;
	stack->b.head->prev->next = stack->b.head;
	stack->a.head->prev = 0;
	stack->b.head = stack->b.head->prev;
	stack->b.head->prev = 0;
	write(1, "pb\n", 3);
}
