/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utility.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 03:27:24 by sdell-un          #+#    #+#             */
/*   Updated: 2022/05/30 22:02:33 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int		list_len(t_node *node)
{
	int len;

    len = 0;
    if (!node)
        return (0);
	while (node)
	{
		len++;
		node = node->next;
	}
	return (len);
}

void	set_linear(t_stack *stack)
{
	stack->head->prev = NULL;
	stack->tail->next = NULL;	
}

void	set_circular(t_stack *stack)
{
	stack->head->prev = stack->tail;
	stack->tail->next = stack->head;
}

void free_list(t_stack *stack)
{
	t_node *node;
	t_node *save;

	node = stack->head;
	while (node)
	{
		save = node;
        node = node->next;
		free (save);
	}
}