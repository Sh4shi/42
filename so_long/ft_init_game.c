/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 01:59:56 by sdell-un          #+#    #+#             */
/*   Updated: 2022/02/20 19:31:40 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_get_img(char *path, t_game *game)
{
	t_img	img;
	void	*new;

	new = mlx_xpm_file_to_image(game->mlx, path, &img.img_width, &img.img_height);
	return (new);
}

void	*ft_init_img(t_game *game)
{
	t_img		*img;
	t_imgcoll	*img1;
	t_imgenemy	*img2;
	t_imgpl		*img3;
	
	img->img_floor = ft_get_img(FLOOR, game);
	img->img_wall = ft_get_img(WALL, game);
	img->img_door = ft_get_img(DOOR, game);
	img1->img_coll1 = ft_get_img(COLL1, game);
	img1->img_coll2 = ft_get_img(COLL2, game);
	img2->img_enemy1 = ft_get_img(ENEMY1, game);
	img2->img_enemy2 = ft_get_img(ENEMY2, game);
	img2->img_enemy3 = ft_get_img(ENEMY3, game);
	img3->imgplf1 = ft_get_img(PLAYERF1, game);
}

void	ft_init_game(t_game *game)
{
	ft_init_img(game);
	ft_check_img(game);
}