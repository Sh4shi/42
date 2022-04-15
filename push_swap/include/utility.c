/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:56:10 by sdell-un          #+#    #+#             */
/*   Updated: 2022/04/15 16:08:05 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_list_circular(t_ptr *ptr)
{
	t_node	*node;

	node = ptr->stack_a->head;
	node->prev = ptr->stack_a->tail;
	ptr->stack_a->tail->next = node;
}

void	set_list(t_ptr *ptr, t_node *node)
{
	node->prev = NULL;
	ptr->stack_a->tail->next = NULL;
}

bool	check_index_value(t_ptr *ptr)
{
	t_node	*node;

	node = ptr->stack_a->head;
	set_list(ptr, node);
	while (node->next != NULL)
	{
		if (node->index == 0)
		{
			set_list_circular(ptr);
			return (true);
		}
		node = node->next;
	}
	set_list_circular(ptr);
	return (false);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	n;

	i = 0;
	sign = 1;
	n = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - 48);
		i++;
	}
	return (sign * n);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	i++;
	return (i);
}
