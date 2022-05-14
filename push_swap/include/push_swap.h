/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:54:11 by sdell-un          #+#    #+#             */
/*   Updated: 2022/05/14 05:17:51 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct s_stack
{
	struct s_node	*head;
	struct s_node	*tail;
	struct s_node	*max;
	struct s_node	*min;
}				t_stack;

typedef struct s_stacks
{
	struct s_stack	a;
	struct s_stack	b;
}				t_stacks;

//------------------------------------check
//
//      input_check.c
bool	is_nbr(int ac, char **av);
bool	get_num(t_stack *stack, int ac, char **av);
bool	add_num(t_stack *stack, char **strs, char *str);

//------------------------------------add numbers
//
//      push_swap.c

//------------------------------------utility
//
//      utility.c
long	ft_atol(const char *str);
void	free_matrix(char **str);

//------------------------------------list menagement
//
bool	add_node(t_stack *source, int nbr);
void	free_list(t_stack *stack);

#endif