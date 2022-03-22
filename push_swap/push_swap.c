/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 04:01:29 by sdell-un          #+#    #+#             */
/*   Updated: 2022/03/22 16:51:49 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	main(int argc, char **argv)
{
	t_node		*node;

	if (argc < 2)
		return (write(2, "Error\n", 6));
	if (!are_numbers(argv))
		return (write(2, "Error\n", 6));
	if (argc == 2 && !is_string(argv))
		return (write(2, "Error\n", 6));
	node->nbr = get_numbers(argv);
}
