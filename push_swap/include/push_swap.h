/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:54:11 by sdell-un          #+#    #+#             */
/*   Updated: 2022/08/24 20:44:02 by sdell-un         ###   ########.fr       */
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
int		*list_to_array(t_stack *stack, int len);
int     max(int one, int two);

//
//
//       algorithms.c
void    bubble_sort(int *arr, int len);
int     *liss(t_stack *stack);

//
//
//       lis_utility.c
void    put_num(int *liss, int num, int len);
void    find_subsequence(int *liss, const int *arr, int len);
int    *get_subsequence(int *liss, int *arr, int len);
int     find_lis_len(int *liss, int len, int *pos);
void	rotate_arr(int len, int *arr, t_node *min);

//------------------------------------list menagement
//
//       set_list.c
bool	add_node(t_stack *source, int nbr);
t_node	*new_node(int nbr);
void	add_index(t_stack *stack);
void    set_index(t_stack *stack, int *arr);
int     search_num(int *arr, int num);

//
//
//       list_utility.c
void	free_list(t_stack *stack);
void	set_circular(t_stack *stack);
void	set_linear(t_stack *stack);
int		list_len(t_node *node);

#endif