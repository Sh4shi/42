/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 21:15:04 by sdell-un          #+#    #+#             */
/*   Updated: 2022/05/16 20:56:24 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

bool	is_ordered(t_stack *stack)
{
	t_node	*markup;
	t_node	*parse;

	parse = stack->head;
	markup = parse;
	while (parse->next)
	{
		if (parse->next->data > markup->data)
			markup = parse->next;
		parse = parse->next;
		if (markup != parse)
			return (true);
	}
	return (false);
}

bool	add_num(t_stack *stack, char **strs, char *str)
{
	long	nbr;

	nbr = ft_atol((const char *)str);
	if (nbr > INT_MAX || nbr < INT_MIN || !add_node(stack, (int)nbr))
	{
		free_list(stack);
		if (strs)
			free_matrix(strs);
		return (false);
	}
	return (true);
}

bool	dispatcher_args(t_stack *stack, char *s)
{
	int		j;
	char	**str;

	str = 0;
	if (ft_strchr((const char *)s, ' '))
	{
		str = ft_split(s, ' ');
		j = 0;
		while (str[j])
		{
			if (!add_num(stack, str, str[j]))
				return (false);
			j++;
		}
		free_matrix(str);
		str = 0;
	}
	else
		if (!add_num(stack, str, s))
			return (false);
	return (true);
}

bool	get_num(t_stack *stack, int ac, char **av)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		if (!dispatcher_args(stack, av[i]))
			return (false);
		i++;
	}
	return (true);
}
