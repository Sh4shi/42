/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 04:02:03 by sdell-un          #+#    #+#             */
/*   Updated: 2022/03/22 16:41:08 by sdell-un         ###   ########.fr       */
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
	int				nbr;
	struct s_node	*next;
	struct s_node	*prev;	
}				t_node;
//input_checker.c
bool	are_numb0rs(char **argv);
bool	is_string(char **argv);
//ft_split.c
int		get_num_el(char const *s, char c);
char	**memall(char *s, char c, int nbr, char **new);
char	**ft_split(char const *s, char c);

#endif
