/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_algorithms_utility.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 01:05:05 by sdell-un          #+#    #+#             */
/*   Updated: 2022/09/17 01:05:08 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	compare_op(int save1, int save2, int *a, int *b)
{
	if (operations(save1, save2) < operations(*a, *b))
	{
		*a = save1;
		*b = save2;
	}
}

int	operations(int a, int b)
{
	if ((a * b) > 0)
		return (max(abs(a), abs(b)));
	else
		return (abs(a) + abs(b));
}

int	find_pos(int *index_a, int i_nbr, int len_a)
{
	int	i;
	int	bigger_pos;

	i = 0;
	bigger_pos = 0;
	while (i < len_a)
	{
		if (i == 0)
		{
			if (i_nbr < index_a[i] && i_nbr > index_a[0])
				return (i);
		}
		else if (i_nbr < index_a[i] && i_nbr > index_a[i - 1])
			return (i);
		else if (i_nbr > index_a[(len_a - i) % len_a]
			&& i_nbr < index_a[((len_a - i) + 1) % len_a])
			return (-i + 1);
		i++;
	}
	bigger_pos = find_max(index_a, len_a) + 1;
	if (bigger_pos == len_a)
		bigger_pos = 0;
	if (bigger_pos > len_a - bigger_pos)
		bigger_pos = -(len_a - bigger_pos);
	return (bigger_pos);
}

void	find_best(t_stacks *stack, int *a, int *b)
{
	int	*index_a;
	int	*index_b;
	int	save[2];
	int	i;

	i = 0;
	index_a = list_to_array_index(&stack->a, list_len(stack->a.head));
	index_b = list_to_array_index(&stack->b, list_len(stack->b.head));
	*a = -(list_len(stack->a.head));
	*b = list_len(stack->b.head);
	while (i < list_len(stack->b.head))
	{
		if (operations(i, 0) >= operations(*a, *b))
			break ;
		save[0] = find_pos(index_a, index_b[i], list_len(stack->a.head));
		save[1] = i;
		compare_op(save[0], save[1], a, b);
		save[0] = find_pos(index_a, index_b[(list_len(stack->b.head) - i)
				% list_len(stack->b.head)], list_len(stack->a.head));
		save[1] = -i;
		compare_op(save[0], save[1], a, b);
		i++;
	}
	free(index_a);
	free(index_b);
}
