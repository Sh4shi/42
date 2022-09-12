/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 23:18:09 by sdell-un          #+#    #+#             */
/*   Updated: 2022/08/24 20:34:00 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int     find_max(int *index_a, int len_a)
{
    int		pos;
    int		max;
    int		i;

    i = 0;
    max = index_a[i];
    pos = 0;
    while (i < len_a)
    {
        if (index_a[i] > max)
        {
            max = index_a[i];
            pos = i;
        }
        i++;
    }
    return (pos);
}

int     max(int one, int two)
{
    if ( one > two)
        return (one);
    else
        return (two);
}

int	*list_to_array(t_stack *stack, int len)
{
	int	*arr;
	int i;
	t_node *node;

    node = stack->head;
    arr = (int *)malloc(sizeof(int) * len);
	i = 0;
    while (node)
    {
        arr[i++] = node->data;
        node = node->next;
    }
	return (arr);
}

int	*list_to_array_index(t_stack *stack, int len)
{
    int	*arr;
    int i;
    t_node *node;

    node = stack->head;
    arr = (int *)malloc(sizeof(int) * len);
    i = 0;
    while (node)
    {
        arr[i++] = node->index;
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
