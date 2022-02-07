/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 03:59:59 by sdell-un          #+#    #+#             */
/*   Updated: 2022/02/07 04:14:22 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	ft_checkmap(char *file, t_game)
{
	int	fd;
	
	fd = open(file, O_RDONLY);
	while (get_next_line(fd))
	{
		
	}
}