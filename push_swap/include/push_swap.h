/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:54:11 by sdell-un          #+#    #+#             */
/*   Updated: 2022/05/16 20:51:57 by sdell-un         ###   ########.fr       */
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
# define SIZE_ARR(arr) sizeof(arr) / sizeof(arr[0])

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
bool	is_ordered(t_stack *stack);
bool	duplicated(t_stack *stack);

//------------------------------------main
//
//      push_swap.c

//------------------------------------utility
//
//      utility.c
long	ft_atol(const char *str);
void	free_matrix(char **str);
int		*list_copy(t_stack *stack);
int 	*radix_sort(int *arr, t_stack *stack);

//------------------------------------list menagement
//
//       set_list.c
bool	add_node(t_stack *source, int nbr);
t_node	*new_node(int nbr);
bool	add_index(t_stack *stack);
//
//
//       list_utility.c
void	free_list(t_stack *stack);
void	set_circular(t_stack *stack);
void	set_linear(t_stack *stack);
int		list_len(t_stack *stack);

#endif