/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utility.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 03:27:24 by sdell-un          #+#    #+#             */
/*   Updated: 2022/05/14 03:33:26 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void free_list(t_stack *stack)
{
	t_node *node;
	t_node *save;

	node = stack->head;
	while (node->next)
	{
		save = node->next;
		free (node);
		node = save;
	}
}