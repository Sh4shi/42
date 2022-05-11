/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:48:40 by sdell-un          #+#    #+#             */
/*   Updated: 2022/05/11 18:32:51 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	init_b(t_stacks *stacks)
{
	stacks->b->head = NULL;
	stacks->b->tail = NULL;
	stacks->b->max = NULL;
	stacks->b->min = NULL;
}

void	init_a(t_stacks *stacks)
{
	stacks->a->head = NULL;
	stacks->a->tail = NULL;
	stacks->a->max = NULL;
	stacks->a->min = NULL;
}

void	init_list(t_stacks *stacks)
{
	init_a(stacks);
	init_b(stacks);
	stacks->a = NULL;
	stacks->b = NULL;
}
