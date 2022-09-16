/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_utility.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 00:59:04 by sdell-un          #+#    #+#             */
/*   Updated: 2022/09/17 00:59:10 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rotate_arr(int len, int *arr, t_node *min)
{
	int	save;

	save = 0;
	while (arr[0] != min->data)
	{
		save = arr[0];
		ft_memmove(arr, &arr[1], ((len - 1) * sizeof(int)));
		arr[len - 1] = save;
	}
}

int	find_lis_len(int *liss, int len, int *pos)
{
	int	i;
	int	lenght;

	i = 0;
	lenght = liss[0];
	while (i < len)
	{
		if (lenght < liss[i])
		{
			lenght = liss[i];
			*pos = i;
		}
		i++;
	}
	return (lenght);
}

int	*get_subsequence(int *liss, int *arr, int len, int *lenliss)
{
	int	i;
	int	lenght;
	int	pos;
	int	*subseq;

	lenght = find_lis_len(liss, len, &pos);
	*lenliss = lenght;
	i = lenght - 1;
	subseq = (int *)malloc(sizeof(int) * lenght);
	while (i >= 0 && pos >= 0)
	{
		subseq[i] = arr[pos];
		while (pos >= 0 && (liss[pos] == (i + 1) || liss[pos] != i))
			pos--;
		i--;
	}
	return (subseq);
}

void	find_subsequence(int *liss, const int *arr, int len)
{
	int	i;
	int	j;

	i = 1;
	while (i < len)
	{
		j = 0;
		while (j < i)
		{
			if (arr[j] < arr[i])
				liss[i] = max(liss[i], liss[j] + 1);
			j++;
		}
		i++;
	}
}

void	put_num(int *liss, int num, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		liss[i] = num;
		i++;
	}
}
