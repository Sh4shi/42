/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game_utility.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 19:43:21 by sdell-un          #+#    #+#             */
/*   Updated: 2022/02/17 00:30:43 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_put_img_player(t_game *game, void *img, int x, int y)
{
	t_vector vector;
		
	mlx_put_immage_window(game->mlx, game->new_wnd, img, x * 32, y *32);
	
}

void	*ft_put_img_coll(t_game *game, void *img, int x, int y)
{
	mlx_put_immage_window(game->mlx, game->new_wnd, img, x * 32, y *32);
}

void	ft_check_img(t_game *game)
{
	t_img	img;
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1')
				ft_put_img(game, img.img_wall, i, j);
			else if (game->map[i][j] == '0')
				ft_put_img(game, img.img_floor, i, j);
			else if (game->map[i][j] == 'E')
				ft_put_img(game, img.img_door, i, j);
			else if (game->map[i][j] == 'C')
				ft_put_img_coll(game, img. i, j);
			else if (game->map[i][j] == 'P')
				ft_put_img_player(game, img. i, j);
			j++;
		}
		i++;
	}
}