/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_utility.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 22:24:28 by sdell-un          #+#    #+#             */
/*   Updated: 2022/02/13 20:40:26 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_type_check(t_game *game, char *buffer)
{
	t_layout layout;

	if (buffer == '\n' || buffer == '\0')
		layout.nbr_row++;
	else if (buffer == 'C')
		layout.nbr_collect++;
	else if (buffer == 'P')
		layout.nbr_player++;
	else if (buffer == 'E')
		layout.nbr_exit++;
	else if (buffer == 'M')
		layout.nbr_enemy++;
	if (layout.nbr_collect != 1 || layout.nbr_player != 1 || layout.nbr_exit != 1)
		ft_error_message("invalid map layout");
}

int	ft_extension_check(const char *s1, const char *s2, int n)
{
	int	i;

	i = ft_strlen(s1) - n;
	while (s1[i] && s2[i] && n != 0 && (s1[i] == s2[i]))
	{
		i++;
		n--;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}