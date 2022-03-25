/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 07:40:26 by sdell-un          #+#    #+#             */
/*   Updated: 2022/03/25 10:04:25 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	find_min_val(t_ptr *ptr)
{
	t_node	*node;
	t_node	*min_nbr;

	node = ptr->stack_a->head;
	while (node->next != ptr->stack_a->head)
	{
		if (node->data < ptr->stack_a->min_val)
		{
			ptr->stack_a->min_val = node->data;
			node->index += 1;
		}
		node = node->next;
	}
	if (node == ptr->stack_a->tail)
	{
		if (node->data < ptr->stack_a->min_val)
		{
			ptr->stack_a->min_val = node->data;
			node->index += 1;
		}
		node = node->next;
		if (node->data < ptr->stack_a->min_val)
		{
			ptr->stack_a->min_val = node->data;
			node->index += 1;
		}
	}
}
