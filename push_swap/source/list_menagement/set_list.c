/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 23:23:37 by sdell-un          #+#    #+#             */
/*   Updated: 2022/08/24 21:05:35 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	search_num(int *arr, int num)
{
	int	i;

	i = 0;
	while (arr[i] != num)
		i++;
	return (i);
}

void	set_index(t_stack *stack, int *arr)
{
	t_node	*node;

	node = stack->head;
	while (node)
	{
		node->index = search_num(arr, node->data) + 1;
		node = node->next;
	}
}

void	add_index(t_stack *stack)
{
	int	*arr;
	int	len;

	len = list_len(stack->head);
	arr = list_to_array(stack, len);
	bubble_sort(arr, len);
	set_index(stack, arr);
	free (arr);
}

t_node	*new_node(int nbr)
{
	t_node	*node;

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
