/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 00:47:10 by sdell-un          #+#    #+#             */
/*   Updated: 2022/09/17 00:47:13 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

void	rrr(t_stacks *stack)
{
	if (list_len(stack->a.head) < 2 && list_len(stack->b.head))
		return ;
	else if (list_len(stack->b.head) < 2)
		rra_rrb(&stack->a, 'a', 0);
	else if (list_len(stack->a.head) < 2)
		rra_rrb(&stack->b, 'b', 0);
	else
	{
		rra_rrb(&stack->a, 'a', 0);
		rra_rrb(&stack->b, 'b', 0);
	}
	write(1, "rrr\n", 4);
}

void	ss(t_stacks *stack)
{
	if (list_len(stack->a.head) < 2 && list_len(stack->b.head))
		return ;
	else if (list_len(stack->b.head) < 2)
		sa_sb(&stack->a, 'a', 0);
	else if (list_len(stack->a.head) < 2)
		sa_sb(&stack->b, 'b', 0);
	else
	{
		sa_sb(&stack->a, 'a', 0);
		sa_sb(&stack->b, 'b', 0);
	}
	write(1, "ss\n", 3);
}

void	rr(t_stacks *stack)
{
	if (list_len(stack->a.head) < 2 && list_len(stack->b.head))
		return ;
	else if (list_len(stack->b.head) < 2)
		ra_rb(&stack->a, 'a', 0);
	else if (list_len(stack->a.head) < 2)
		ra_rb(&stack->b, 'b', 0);
	else
	{
		ra_rb(&stack->a, 'a', 0);
		ra_rb(&stack->b, 'b', 0);
	}
	write(1, "rr\n", 3);
}
