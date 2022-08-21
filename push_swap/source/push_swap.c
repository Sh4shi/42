/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 21:10:43 by sdell-un          #+#    #+#             */
/*   Updated: 2022/08/13 16:45:38 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_stacks	stack;
    int         *subseq;
	
	ft_bzero(&stack, sizeof(t_stacks));
	if (ac < 2 || !is_nbr(ac, av) || !get_num(&stack.a, ac, av) ||
		!is_ordered(&stack.a) || !duplicated(&stack.a))
		return (write(2, "Error\n", 6));
	else
		add_index(&stack.a);
    subseq = liss(&stack.a);
	

    for (t_node *tmp = stack.a.head; tmp; tmp = tmp->next)
		printf("%d: %d\n", tmp->index, tmp->data);
    free_list(&stack.a);
}
