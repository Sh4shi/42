/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 00:12:17 by sdell-un          #+#    #+#             */
/*   Updated: 2022/09/17 00:12:24 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_sort(t_stack *s)
{
	t_node	*t;

	t = s->head;
	while (t->next)
	{
		if (!(t->index < t->next->index))
			return (0);
		t = t->next;
	}
	return (1);
}

void	five_sort(t_stacks *stacks, int len)
{
	int	i;
	int	med;

	med = (len / 2) + 1;
	i = 0;
	while (i < len)
	{
		if ((stacks->a.head->index) < med)
			pb(stacks);
		else
			ra_rb(&stacks->a, 'a', 1);
		i++;
	}
	if (!is_sort(&stacks->a))
		three_sort(&stacks->a);
	if (stacks->b.head->data < stacks->b.head->next->data)
		sa_sb(&stacks->b, 'b', 1);
	pa(stacks);
	pa(stacks);
}
