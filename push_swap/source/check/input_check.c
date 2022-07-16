/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 21:15:04 by sdell-un          #+#    #+#             */
/*   Updated: 2022/05/16 20:56:24 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

bool	duplicated(t_stack *stack)
{
	t_node *parse;
	t_node *twin;
	
	parse = stack->head;
	set_circular(stack);
	while (1)
	{
		twin = parse;
		while (twin->next != parse)
		{
			if (twin->next->data == parse->data)
            {
                free_list(stack);
                return (false);
            }
			twin = twin->next;
		}
		parse = parse->next;
		if (parse->prev == stack->tail)
		{
			set_linear(stack);
			return (true);
		}
	}	
}

bool	is_ordered(t_stack *stack)
{
	t_node *markup;
	t_node *parse;
	
	parse = stack->head;
	markup = parse;
	while (parse->next)
	{
		if (parse->next->data > markup->data)
			markup = parse->next;
		parse = parse->next;
		if (markup != parse)
			return (true);
	}
    //free_list(stack); ?? perchè se sono ordinati non devo fare il free?
	return (false);
}

bool	add_num(t_stack *stack, char **strs, char *str)
{
	long nbr;

	nbr = ft_atol((const char *)str); 
	if (nbr > INT_MAX || nbr < INT_MIN || !add_node(stack, (int)nbr))
	{
		free_list(stack);
		if (strs)
			free_matrix(strs);
		return (false);
	}
	return (true);
}
bool	get_num(t_stack *stack, int ac, char **av)
{
	int i;
	int j;
	char **str;
	
	i = 1;
	j = 0;
	while (i < ac)
	{
		if (ft_strchr((const char*)av[i], ' '))
		{
			str = ft_split(av[i], ' ');
			j = 0;
			while (str[j])
			{
				if (!add_num(stack, str, str[j]))
					return (false);
				j++;
			}
			free_matrix(str);
			str = 0;
		}
		else 
			if (!add_num(stack, str, av[i]))
				return (false);
		i++;
	}
	return (true);
}

bool	is_nbr(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]) &&
				av[i][j] != ' ' && av[i][j] != '+' && av[i][j] != '-')
				return (false);
			j++;
		}	
		i++;
	}
	return (true);
}
