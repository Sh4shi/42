/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 23:18:09 by sdell-un          #+#    #+#             */
/*   Updated: 2022/05/14 05:17:29 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	sort_arr(int *arr, int size, int decimal)
{

}

int	*radixsort(int *arr, t_stack  *stack)
{
	int size;
	int max;
	int	decimal;

	max = stack->max->data;
	size = SIZE_ARR(arr);
	decimal = 1;
	while (max / decimal > 0)
	{
		sort_arr(arr, size, decimal);
		decimal *= 10;
	}
}

int	*list_copy(t_stack *stack)
{
	int	*arr;
	int i;
	t_node *node;

	node = stack->head;
	arr = (int *)malloc(sizeof(int) * list_len(&stack));
	i = 0;
	while (node)
	{
		arr[i] = node->data;
		node = node->next;
		i++;
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
