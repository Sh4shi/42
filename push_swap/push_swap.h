/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 04:02:03 by sdell-un          #+#    #+#             */
/*   Updated: 2022/03/21 04:37:05 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_node
{
	long int		data;
	struct t_node	*next;
	struct t_node	*prev;	
}				t_node;

typedef struct s_info
{
	
}				t_info;

void	check(int argc, char **argv, t_node *node);
int		change_type(char **argv, int i, int j, t_node *node);
void	add_node(long int num, t_node *node, int count);

#endif
