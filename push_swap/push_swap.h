/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 04:02:03 by sdell-un          #+#    #+#             */
/*   Updated: 2022/04/15 15:58:15 by sdell-un         ###   ########.fr       */
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

typedef struct s_list
{
	struct s_node	*head;
	struct s_node	*tail;
	struct s_node	*max_val;
	struct s_node	*min_val;
	int				len;
}				t_list;

typedef struct s_ptr
{
	struct s_list	*stack_a;
	struct s_list	*stack_b;
}				t_ptr;

//utility.c
void	set_list(t_ptr *ptr, t_node *node);
bool	check_index_value(t_ptr *ptr);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
void	set_list_circular(t_ptr *ptr);

//check_value.c
void	add_index(t_ptr *ptr);

//input_checker.c
int		get_numbers(char **argv);
bool	are_numbers(char **argv);
bool	is_string(char **argv);
//ft_split.c
int		get_num_el(char const *s, char c);
char	**memall(char *s, char c, int nbr, char **new);
char	**ft_split(char const *s, char c);
//start
void	change_type(int argc, char **argv, t_ptr *ptr);
void	add_node(int num, t_ptr *ptr, int first_num);
#endif
