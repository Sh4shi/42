/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 04:01:29 by sdell-un          #+#    #+#             */
/*   Updated: 2022/03/25 08:33:34 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	add_node(int num, t_ptr *ptr, int first_num)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (write(2, "Error\n", 6));
	if (first_num == 0)
	{
		ptr->stack_a->head = node;
		ptr->stack_a->tail = node;
		node->data = num;
		node->next = node;
		node->prev = node;
		node->index = 0;
		ptr->stack_a->min_val = node->data;
	}
	else
	{
		node->prev = ptr->stack_a->tail;
		node->next = ptr->stack_a->head;
		node->data = num;
		ptr->stack_a->tail = node;
		find_min_val(ptr);
	}
}

void	change_type(int argc, char **argv, t_ptr *ptr)
{
	int		i;
	int		j;
	char	*str;
	int		num;

	i = 1;
	j = 0;
	if (argc == 2)
	{
		while (argv[i][j])
		{
			str = ft_split(argv[i][j], ' ');
			num = ft_atoi(str);
			add_node(num, ptr, j);
			j += ft_strlen(str) + 2;
		}
	}
	else if (argc > 2)
	{
		while (argv[i])
		{
			j = 0;
			if (is_string(argv[i][j]))
			{
				while (argv[i][j])
				{
					str = ft_split(argv[i][j], ' ');
					num = ft_atoi(str);
					add_node(num, ptr, j);
					j += ft_strlen(str) + 2;
				}
			}
			else
			{
				while (argv[i])
				{
					str = argv[i];
					num = ft_atoi(str);
					add_node(num, ptr, i - 1);
				}
			}
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	t_ptr	*ptr;

	if (argc < 2)
		return (write(2, "Error\n", 6));
	if (!are_numbers(argv))
		return (write(2, "Error\n", 6));
	if (argc == 2 && !is_string(argv))
		return (write(2, "Error\n", 6));
	ptr->stack_a->len = get_numbers(argv);
	change_type(argc, argv, ptr);
}
