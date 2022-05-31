/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:22:51 by sdell-un          #+#    #+#             */
/*   Updated: 2022/05/31 16:58:07 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	*copy_sorted(int *arr, t_list **bucket)
{
	t_list	*node;
	int		box;
	int		i;

	i = 0;
	box = 0;
	arr =  ft_memset(arr, 0, sizeof(int) * sizeof(*arr));
	while (box < 10)
	{
		node = bucket[box];
		while(node->next)
		{
			arr[i] = *node->content;
			node = node->next;
			i++;	
		}
		box += 1;
	}
	return (arr);
}

int	*sorrt_arr(int *arr, int nbr, int decimal)
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
	return (copy_sorted(arr, bucket));
}

int	*radix_sort(int *arr, t_stack  *stack)
{
	size_t	nbr;
	int		decimal;

	nbr = (sizeof(*arr) / sizeof(arr[0]));
	decimal = 1;
	while (stack->max->data / decimal > 0)
	{
		arr = sort_arr(arr, nbr, decimal);
		decimal *= 10;
	}
	return (arr);
}