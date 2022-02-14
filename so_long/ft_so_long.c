/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 22:24:04 by sdell-un          #+#    #+#             */
/*   Updated: 2022/02/14 00:18:28 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void	ft_wnd_size(t_game *game)
{
	t_layout	layout;
	
	game->width = layout.nbr_col * 32;
	game->height = layout.nbr_row * 32;  	
}

char	ft_error_message(char *msg)
{
	printf("Error\n%s\n", msg);
	return (NULL);
}

t_layout ft_init_lay(t_game *game)
{
	t_layout layout;
	layout.nbr_row = 0;
	layout.nbr_col = 0;
	layout.nbr_collect = 0;
	layout.nbr_player = 0;
	layout.nbr_enemy = 0;
	layout.nbr_exit = 0;
}

int main(int argc, char **argv)
{
	char	**map;
	t_game	*g;

	map = ft_file_check(argc, argv, g);
	g->mlx = mlx_init();
	g->new_wnd = mlx_new_window(g->mlx, g->width, g->height, "so_long");
	
}