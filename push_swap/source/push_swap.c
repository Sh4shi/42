/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 21:10:43 by sdell-un          #+#    #+#             */
/*   Updated: 2022/05/09 19:04:29 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	add_nbr(int ac, char **av, t_stacks *stacks)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	if (ac == 2)
	{
		while (av[i][j])
			j += add_nbr_str(av, stacks);
	}
	else
		add_nbr_multi_ac(av, stacks);
	//add_index(stacks);
}

int	main(int ac, char **av)
{
	t_stacks	*stacks;

	if (ac < 2)
		return (write(2, "Error\n", 6));
	if (ac == 2 && !is_string(av))
		return (write(2, "Error\n", 6));
	if (!are_numbers(av))
		return (write(2, "Error\n", 6));
	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		return (write(1, "memory allocation error\n", 24));
	stacks = NULL;
	init_list(stacks);
	add_nbr(ac, av, stacks);
}
