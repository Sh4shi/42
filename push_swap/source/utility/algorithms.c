/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 00:57:45 by sdell-un          #+#    #+#             */
/*   Updated: 2022/09/17 00:57:47 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	*liss(t_stack *stack, int *lenght)
{
	int	*liss;
	int	*arr;
	int	len;
	int	*subseq;

	len = list_len(stack->head);
	arr = list_to_array(stack, len);
	rotate_arr(len, arr, stack->min);
	liss = (int *)malloc(sizeof(int) * len);
	ft_memset(liss, 0, sizeof(int) * len);
	put_num(liss, 1, len);
	find_subsequence(liss, arr, len);
	subseq = get_subsequence(liss, arr, len, lenght);
	free (liss);
	free (arr);
	return (subseq);
}

void	bubble_sort(int *arr, int len)
{
	int	i;
	int	y;
	int	temp;

	i = 0;
	while (i < len)
	{
		y = i;
		while (y < len)
		{
			if (arr[i] > arr[y])
			{
				temp = arr[i];
				arr[i] = arr[y];
				arr[y] = temp;
			}
			y++;
		}
		i++;
	}
}
