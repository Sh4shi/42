/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 13:34:29 by sdell-un          #+#    #+#             */
/*   Updated: 2022/05/09 19:04:15 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//void	add_index(t_stacks *stacks)
//{
//	
//}

void	new_node(t_stacks *stacks, int num)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	new_node->data = num;
	if (new_node->data > stacks->a->max->data)
		stacks->a->max = &new_node;
	else if (new_node->data < stacks->a->min->data)
		stacks->a->min = &new_node;
	new_node->index = 0;
	new_node->prev = &stacks->a->tail;
	new_node->next = NULL;
	stacks->a->tail = &new_node;
}

void	add_first_node(t_stacks *stacks, int num)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->data = num;
	node->index = 0;
	node->next = NULL;
	node->prev = NULL;
	stacks->a->head = &node;
	stacks->a->tail = &node;
	stacks->a->max = &node;
	stacks->a->min = &node;
}

void	add_node(t_stacks *stacks, int num)
{
	if (!stacks->a->head)
		add_first_node(stacks, num);
	else
		new_node(stacks, num);
}
