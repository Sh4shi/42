/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 07:40:26 by sdell-un          #+#    #+#             */
/*   Updated: 2022/04/06 13:20:57 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	add_index(t_ptr *ptr)
{
	t_node	*node;
	int		i;
	int		num;

	node = ptr->stack_a->min_val;
	i = 0;
	num = node->data;
	while (check_index_value(ptr))
	{
		node->index = i + 1;
		node = node->next;
		
	}
}
