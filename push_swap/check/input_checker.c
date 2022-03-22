/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:04:08 by sdell-un          #+#    #+#             */
/*   Updated: 2022/03/22 16:45:44 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	is_string(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] == ' ')
			return (true);
		i++;
	}
	return (false);
}

bool	are_numbers(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] != ' ' && argv[i][j] != '+' && argv[i][j] != '-') \
				|| (argv[i][j] < '0' && argv[i][j] > '9'))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

int	get_numbers(char **argv)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (argv[i])
	{
		if (is_string(argv[i]))
			count += get_num_el(argv[i], ' ');
		else
			count++;
	}
	return (count);
}
