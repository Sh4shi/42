/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:22:51 by sdell-un          #+#    #+#             */
/*   Updated: 2022/05/31 19:55:36 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void free_bucket(t_list **bucket, int len)
{
    int i;
    t_list *ptr;
    t_list *tmp;

    i = 0;
    while (i < len)
    {
        ptr = bucket[i];
        if (ptr)
        {
            while (ptr)
            {
                tmp = ptr;
                ptr = ptr->next;
                free(tmp->content);
                free(tmp);
            }
        }
        i++;
    }
}

int	*copy_sorted(int *arr, t_list **bucket, int len_array)
{
	t_list	*node;
	int		box;
	int		i;

	i = 0;
	box = 0;
    arr =  ft_memset(arr, 0, len_array* sizeof(int));
	while (box < 10)
	{
		node = bucket[box];
		while(node)
		{
			arr[i] = *((int *)(node->content));
			node = node->next;
			i++;
		}
		box += 1;
	}
    return (arr);
}

int	*sort_arr(int *arr, int nbr, int decimal)
{
    t_list     *bucket[10];
    int         count;
    int         box;
    int         *ret;
    int         *ntmp;

    count = 0;
    ft_memset(&bucket, 0, sizeof(t_list *) * 10);
    while (count < nbr)
    {
        box = (arr[count] % (10 * decimal)) / decimal;
        ntmp = malloc(sizeof(int));
        *ntmp = arr[count];
        ft_lstadd_back(&bucket[box],
                       ft_lstnew( (void *)(ntmp) ));
        count++;
    }
    ret = copy_sorted(arr, bucket, nbr);
	free_bucket(bucket, 10);
    return (ret);
}

int	*radix_sort(int *arr, t_stack  *stack, int nbr)
{
	int		decimal;

	decimal = 1;
	while (stack->max->data / decimal > 0)
	{
		arr = sort_arr(arr, nbr, decimal);
		decimal *= 10;
	}
	return (arr);
}
