/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 23:18:09 by sdell-un          #+#    #+#             */
/*   Updated: 2022/05/31 16:24:24 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	*list_to_array(t_stack *stack)
{
	int	*arr;
	int i;
	t_node *node;
    int len;

    node = stack->head;
    len = list_len(node);
    arr = (int *)malloc(sizeof(int) * len);
	i = 0;
    while (node)
    {
        arr[i++] = node->data;
        node = node->next;
    }
	return (arr);
}

void	free_matrix(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free (str);	
}

long	ft_atol(const char *str)
{
	long	i;
	long	sign;
	long	n;

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
