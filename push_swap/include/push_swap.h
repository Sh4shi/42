/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:54:11 by sdell-un          #+#    #+#             */
/*   Updated: 2022/08/29 00:04:18 by sdell-un         ###   ########.fr       */
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
    int     moves;
}				t_stacks;

//------------------------------------check
//
//      input_check.c
bool	is_nbr(int ac, char **av);
bool	get_num(t_stack *stack, int ac, char **av);
bool	add_num(t_stack *stack, char **strs, char *str);
bool	is_ordered(t_stack *stack);
bool	duplicated(t_stack *stack);

//------------------------------------source
//
//      push_swap.c
void    start(t_stacks *stack);

//
//
//       start_move.c
void    push_liss(t_stacks *stack, int *subseq, int lenght);
bool    data_is_in_lis(int data, int *subseq, int len);
void    check_bigger(t_stacks *stack, int *subseq, int lenght);

//
//
//       moving.c
int fix_b(t_stacks *stack);
int bigger_num(t_stack *stack);

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
int     *liss(t_stack *stack, int *lenght);

//
//
//       lis_utility.c
void    put_num(int *liss, int num, int len);
void    find_subsequence(int *liss, const int *arr, int len);
int     *get_subsequence(int *liss, int *arr, int len, int *lenliss);
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

//------------------------------------move
//
//        move.c
void    sa_sb(t_stack *stack);
void    ra_rb(t_stack *stack);
void    rra_rrb(t_stack *stack);
void    pa(t_stacks *stack);
void    pb(t_stacks *stack);
//
//
//        double_move.c
void    ss(t_stacks *stack);
void    rr(t_stacks *stack);
void    rrr(t_stacks *stack);
#endif