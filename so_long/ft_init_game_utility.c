/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game_utility.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 19:43:21 by sdell-un          #+#    #+#             */
/*   Updated: 2022/02/21 00:46:18 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_put_img(t_game *game, void *img, int j, int i)
{
	mlx_put_immage_window(game->mlx, game->new_wnd, img, j * 32, i *32);
}

void	*ft_iteri_put(t_game *game, int i, int j)
{
	t_imgpl		*imgpl;
	t_imgcoll	*imgcoll;
	t_imgenemy	*imgenemy;
	t_vector	*vec;
	
	if (game->map[i][j] == 'P')
	{
		ft_lstiter(imgpl, ft_put_img);
		vec->x = j;
		vec->y = i;
	}
	else if (game->map[i][j] == 'C')
		ft_lstiter(imgcoll, ft_put_img);
	else if (game->map[i][j] == 'M')
		 ft_lstiter(imgenemy, ft_put_img);
}

void	*ft_check_img(t_game *game)
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
			else
				ft_iteri_put(game, i, j);
			j++;
		}
		i++;
	}
}