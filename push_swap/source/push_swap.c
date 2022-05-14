/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 21:10:43 by sdell-un          #+#    #+#             */
/*   Updated: 2022/05/14 05:20:40 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_stacks	stack;
	
	ft_bzero(&stack, sizeof(t_stacks));
	if (ac < 2 || !is_nbr(ac, av) || !get_num(&stack.a, ac, av) ||
		!stack.a.max->next)
		return (write(2, "Error\n", 6));

	#include <stdlib.h>
	for (t_node *tmp = stack.a.head; tmp; tmp = tmp->next)
		printf("%d ", tmp->data);
}
