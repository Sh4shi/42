/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 21:15:04 by sdell-un          #+#    #+#             */
/*   Updated: 2022/05/14 04:56:04 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

bool	add_num(t_stack *stack, char **strs, char *str)
{
	long nbr;

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
bool	get_num(t_stack *stack, int ac, char **av)
{
	int i;
	int j;
	char **str;
	
	i = 1;
	j = 0;
	while (i < ac)
	{
		if (ft_strchr((const char*)av[i], ' '))
		{
			str = ft_split(av[i], ' ');
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
			if (!add_num(stack, str, av[i]))
				return (false);
		i++;
	}
	return (true);
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
