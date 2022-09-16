/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 00:23:18 by sdell-un          #+#    #+#             */
/*   Updated: 2022/09/17 00:23:22 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	check_bigger(t_stacks *stack, int *subseq, int lenght)
{
	if (!data_is_in_lis(stack->a.tail->data, subseq, lenght))
	{
		if ((stack->a.tail->data < stack->a.head->data)
			&& (stack->a.tail->data < stack->a.head->next->data))
			rra_rrb(&stack->a, 'a', 1);
	}
	if (!data_is_in_lis(stack->a.head->next->data, subseq, lenght))
	{
		if (stack->a.head->next->data < stack->a.head->data)
			sa_sb(&stack->a, 'a', 1);
	}
}

bool	data_is_in_lis(int data, int *subseq, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (data == subseq[i])
			return (true);
		i++;
	}
	return (false);
}

void	push_liss(t_stacks *stack, int *subseq, int lenght)
{
	while (list_len(stack->a.head) > lenght)
	{
		if (!data_is_in_lis(stack->a.head->data, subseq, lenght))
			pb(stack);
		else
			ra_rb(&stack->a, 'a', 1);
	}
}
