/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 00:33:29 by sdell-un          #+#    #+#             */
/*   Updated: 2022/09/17 00:33:32 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

bool	duplicated(t_stack *stack)
{
	t_node	*parse;
	t_node	*twin;

	parse = stack->head;
	set_circular(stack);
	while (1)
	{
		twin = parse;
		while (twin->next != parse)
		{
			if (twin->next->data == parse->data)
			{
				set_linear(stack);
				free_list(stack);
				return (false);
			}
			twin = twin->next;
		}
		parse = parse->next;
		if (parse->prev == stack->tail)
		{
			set_linear(stack);
			return (true);
		}
	}
}

bool	is_nbr(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]) &&
				av[i][j] != ' ' && av[i][j] != '+' && av[i][j] != '-')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
