/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 04:01:29 by sdell-un          #+#    #+#             */
/*   Updated: 2022/03/21 04:30:10 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_node(long int num, t_node *node, int count)
{
	t_node	*first_node;
	t_node	*last_node;

	node->data = num;
	node->next = node;
	node->prev = node;
	if (count == 0)
		first_node = node;
	last_node = node;
}

int	change_type(char **argv, int i, int j, t_node *node)
{
	long int	num;
	char		*str;
	int			count;

	num = 0;
	count = 0;
	str = ft_split(argv[j][i], " ");
	num = ft_atoi(str);
	i = ft_strlen(str) + 1;
	if (i != 0)
		count = 1;
	add_node(num, node, count);
	count++;
	return (i);
}

void	check(int argc, char **argv, t_node *node)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (argc == 2)
		while (argv[1][i])
			i = change_type(argv, i, j + 1, node);
	else if (argc > 2)
	{
		while (argv[j][i])
		{
			while (argv[j][i])
				i = change_type(argv, i, j, node);
			j++;
		}
	}
}

int	main(int argc, char **argv)
{
	t_node		*node;

	node = molloc(sizeof(t_node));
	if (!node)
		return (NULL);
	if (argc < 2)
		return (NULL);
	else
		check(argc, argv, node);
}
