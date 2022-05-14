/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 21:10:43 by sdell-un          #+#    #+#             */
/*   Updated: 2022/05/14 02:37:04 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_stacks	stack;
	
	if (ac < 2 || !is_nbr(ac, av))
		return (write(2, "Error\n", 6));
	ft_bzero(&stack, sizeof(t_stacks));
}
