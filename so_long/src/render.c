/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 22:59:54 by sdell-un          #+#    #+#             */
/*   Updated: 2023/02/23 23:58:04 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/so_long.h"

void	draw_new_image(t_game *game, int animation)
{
	uint32_t	*new_img;
	t_vector	pos;
	t_img		*tmp;

	pos.x = 0;
	pos.y = 0;
	new_img = (uint32_t *)game->img[0].pixels;
	while (pos.y < TOTAL_PIXEL_COL)
	{
		pos.x = 0;
		while (pos.x < TOTAL_PIXEL_ROW)
		{
			tmp = right_img(game, game->map.map_matrix, pos, animation);
			*new_img = get_pixel(tmp, pos.y % 32, pos.x % 32);
			new_img++;
			pos.x++;
		}
		pos.y++;
	}
}

void	*new_img(t_game *game)
{
	game->img[0].img_ptr = mlx_new_image(game->mlx, SIZE(game->map.n_col),
			SIZE(game->map.n_row));
	if (!game->img[0].img_ptr)
		error("Error\nimage issue: can't create new full image\n");
	game->img[0].pixels = mlx_get_data_addr(game->img[0].img_ptr,
			&game->img[0].pixel_bits, &game->img[0].line_size,
			&game->img[0].endian);
	draw_new_image(game, 0);
	return (game->img[0].img_ptr);
}

void	fill_image_storage(t_game *game)
{
	int	i;

	i = 1;
	define_path(game->img);
	while (i < MAX_IMG)
	{
		game->img[i].img_ptr = mlx_xpm_file_to_image(game->mlx,
				game->img[i].path, &(game->img[i].size.x),
				&(game->img[i].size.y));
		if (!game->img[i].img_ptr)
			error("Error\nimage issue: can't get xpm file\n");
		game->img[i].pixels = mlx_get_data_addr(game->img[i].img_ptr,
				&game->img[i].pixel_bits, &game->img[i].line_size,
				&game->img[i].endian);
		i++;
	}
}

void	init_ptr(t_game *game)
{
	game->mlx = mlx_init();
	fill_image_storage(game);
	game->win_ptr = mlx_new_window(game->mlx, SIZE(game->map.n_col),
			SIZE(game->map.n_row), "So_long");
}
