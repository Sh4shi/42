/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 23:18:09 by sdell-un          #+#    #+#             */
/*   Updated: 2022/05/22 21:00:32 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int sorrt_arr(int *arr, int nbr, int decimal)
{
    t_list     *bucket[10];
    int         count;
    int         box;
    t_list      *node;

    count = 0;
    ft_memset(&bucket,0, sizeof(t_list *) * 10);
    while (count < nbr)
    {
        box = (arr[count] / decimal) % 10;
        if (bucket[box] == 0)
            bucket[box] = ft_lstnew(arr[count]);
        else
        {
            node = ft_lstnew(arr[count]);
            ft_lstadd_back(&bucket[box], node);
        }
        count++;
    }
}

int	*radix_sort(int *arr, t_stack  *stack)
{
	int nbr;
	int max;
	int	decimal;

	max = stack->max->data;
	nbr = SIZE_ARR(arr);
	decimal = 1;
	while (max / decimal > 0)
	{
		sort_arr(arr, nbr, decimal);
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
	while (i < list_len(&stack))
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
