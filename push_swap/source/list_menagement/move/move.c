/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 00:48:06 by sdell-un          #+#    #+#             */
/*   Updated: 2022/09/17 00:48:08 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

void	pa_sup(t_stacks *stack)
{
	stack->a.head = stack->b.head;
	stack->b.head = stack->b.head->next;
	stack->b.head->prev = 0;
	stack->a.head->prev = 0;
	stack->a.tail = stack->a.head;
	stack->a.head->next = stack->a.tail;
	stack->a.tail->prev = stack->a.head;
	stack->a.tail->next = 0;
	write(1, "pa\n", 3);
}

void	pa(t_stacks *stack)
{
	if (!(stack->b.head))
		return ;
	if (!(stack->a.head))
	{
		pa_sup(stack);
		return ;
	}
	if (list_len(stack->b.head) == 1)
	{
		stack->a.head->prev = stack->b.head;
		ft_bzero(&stack->b, sizeof(t_stack));
		stack->a.head->prev->next = stack->a.head;
		stack->a.head = stack->a.head->prev;
		stack->a.head->prev = 0;
		write(1, "pa\n", 3);
		return ;
	}
	stack->a.head->prev = stack->b.head;
	stack->b.head = stack->b.head->next;
	stack->a.head->prev->next = stack->a.head;
	stack->b.head->prev = 0;
	stack->a.head = stack->a.head->prev;
	stack->a.head->prev = 0;
	write(1, "pa\n", 3);
}

void	rra_rrb(t_stack *stack, char s, char print)
{
	if (list_len(stack->head) < 2)
		return ;
	stack->tail->next = stack->head;
	stack->head->prev = stack->tail;
	stack->tail = stack->tail->prev;
	stack->tail->next = 0;
	stack->head->prev->prev = 0;
	stack->head = stack->head->prev;
	if (print)
	{
		if (s == 'a')
			write(1, "rra\n", 4);
		else
			write(1, "rrb\n", 4);
	}
}

void	ra_rb(t_stack *stack, char s, char print)
{
	if (list_len(stack->head) < 2)
		return ;
	stack->head->prev = stack->tail;
	stack->tail->next = stack->head;
	stack->head = stack->head->next;
	stack->head->prev = 0;
	stack->tail = stack->tail->next;
	stack->tail->next = 0;
	if (print)
	{
		if (s == 'a')
			write(1, "ra\n", 3);
		else
			write(1, "rb\n", 3);
	}
}

void	sa_sb(t_stack *stack, char s, char print)
{
	if (list_len(stack->head) < 2)
		return ;
	stack->head = stack->head->next;
	stack->head->prev->next = stack->head->next;
	stack->head->prev->prev = stack->head;
	if (stack->head->next)
		stack->head->next->prev = stack->head->prev;
	stack->head->next = stack->head->prev;
	stack->head->prev = 0;
	if (print)
	{
		if (s == 'a')
			write(1, "sa\n", 3);
		else
			write(1, "sb\n", 3);
	}
}
