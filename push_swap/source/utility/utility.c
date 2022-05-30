/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 23:18:09 by sdell-un          #+#    #+#             */
/*   Updated: 2022/05/30 22:45:13 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void sorrt_arr(int *arr, int nbr, int decimal)
{
    t_list     *bucket[10];
    int         count;
    int         box;
    t_list      *node;

    count = 0;
    ft_memset(&bucket,0, sizeof(t_list *) * 10);
    while (count < nbr)
    {
        box = (arr[count] % 10) / decimal;
        if (bucket[box] == 0)
            bucket[box] = ft_lstnew(&arr[count]);
        else
        {
            node = ft_lstnew(&arr[count]);
            ft_lstadd_back(&bucket[box], node);
        }
        count++;
    }
}

void	radix_sort(int *arr, t_stack  *stack)
{
	size_t nbr;
	int	decimal;

	nbr = (sizeof(arr) / sizeof(arr[0]));
	decimal = 1;
	while (stack->max->data / decimal > 0)
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
	arr = (int *)malloc(sizeof(int) * list_len(node));
	i = 0;
	while (i < list_len(node))
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
