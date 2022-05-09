/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:20:39 by sdell-un          #+#    #+#             */
/*   Updated: 2022/05/09 16:14:22 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	add_nbr_ac(char *av, t_stacks *stacks)
{
	int	num;

	num = ft_atoi(av);
	add_node(stacks, num);
}

int	add_nbr_str(char *av, t_stacks *stacks)
{
	char	*str;
	int		num;

	str = split(av);
	num = ft_atoi(str);
	add_node(stacks, num);
	return (ft_strlen(str) + 1);
}

void	add_nbr_multi_ac(char **av, t_stacks *stacks)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (av[i])
	{
		j = 0;
		if (is_string(av[i][j]))
		{
			while (av[i][j])
				j += add_nbr_str(av, stacks);
		}
		else
		{
			while (av[i])
				add_nbr_ac(av, stacks);
		}
		i++;
	}
}
