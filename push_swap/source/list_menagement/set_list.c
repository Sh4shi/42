/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 23:23:37 by sdell-un          #+#    #+#             */
/*   Updated: 2022/05/14 16:25:25 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	add_index(t_stack *stack)
{
	t_node	*markup;
	t_node	*parse;
	t_stack	*list_copy;
	t_node	*temp;
	
	list_copy = create_list(stack);
	set_circular(stack);
	parse = stack->min->next;
	markup = parse;
	while (list_copy->tail != stack->max)
	{
		while (markup->prev == parse)
		{
			if ()
			
			markup = markup->prev;
		}
	}
	
}

t_node	*new_node(int nbr)
{
	t_node *node;
	
	node = ft_calloc(1, sizeof(t_node));
	if (!node)
		return (0);
	node->data = nbr;
	return (node);
}

bool	add_node(t_stack *source, int nbr)
{
	t_node	*node;

	node = new_node(nbr);
	if (!node)
		return (false);
	if (!(source->head))
	{
		node->prev = node;
		(source)->head = node;
		(source)->tail = node;
		(source)->max = node;
		(source)->min = node;
	}
	else
	{
		node->prev = (source)->tail;
		source->tail->next = node;
		(source)->tail = node;
		if (node->data > (source)->max->data)
		 	(source)->max = node;
		if (node->data < (source)->min->data)
			(source)->min = node;
	}
	return (true);
}