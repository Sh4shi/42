/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:54:11 by sdell-un          #+#    #+#             */
/*   Updated: 2022/05/09 19:04:37 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include "libft/libft.h"

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
	struct s_stack	*a;
	struct s_stack	*b;
}				t_stacks;

//------------------------------------check
//
//      input_check.c
bool	is_string(char *av);
bool	are_numbers(char **av);
bool	next_is_nbr(char *av);

//------------------------------------add numbers
//
//      push_swap.c
void	add_nbr(int ac, char **av, t_stacks *stacks);

//------------------------------------add numbers utility
//
//      utility.c
int		add_nbr_str(char *av, t_stacks *stacks);
void	add_nbr_ac(char *av, t_stacks *stacks);
void	add_nbr_multi_ac(char **av, t_stacks *stacks);

//------------------------------------list menagement
//
//      set_list.c

void	add_node(t_stacks *stacks, int num);
void	add_first_node(t_stacks *stacks, int num);
void	new_node(t_stacks *stacks, int num);
//void	add_index(t_stacks *stacks);

//      init_list.c
void	init_a(t_stacks *stacks);
void	init_b(t_stacks *stacks);
void	init_list(t_stacks *stacks);

#endif