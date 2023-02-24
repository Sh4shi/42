/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 20:54:18 by sdell-un          #+#    #+#             */
/*   Updated: 2023/02/23 23:57:58 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/so_long.h"

int	moovements(int next_x, int next_y, t_game *game)
{
	if (game->map.map_matrix[next_y][next_x] == '1')
		return (0);
	else if (game->map.map_matrix[next_y][next_x] == 'E')
	{
		if (game->nbr_colls == 0)
			exit_game(game);
	}
	else
	{
		if (game->map.map_matrix[next_y][next_x] == 'C')
			game->nbr_colls--;
		game->map.map_matrix[game->p_pos.y][game->p_pos.x] = '0';
		game->map.map_matrix[next_y][next_x] = 'P';
		ft_bzero(game->img[0].pixels, IMG_SIZE);
		draw_new_image(game, 1);
		mlx_clear_window(game->mlx, game->win_ptr);
		mlx_put_image_to_window(game->mlx, game->win_ptr,
			game->img[0].img_ptr, 0, 0);
	}
	game->steps += 1;
	ft_printf("You're away from your darkside:%d steps\n", game->steps);
	return (0);
}

int	event_handler(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit_game(game);
	else if (keycode == KEY_W || keycode == KEY_UP)
		moovements(game->p_pos.x, game->p_pos.y - 1, game);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		moovements(game->p_pos.x, game->p_pos.y + 1, game);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		moovements(game->p_pos.x - 1, game->p_pos.y, game);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		moovements(game->p_pos.x + 1, game->p_pos.y, game);
	return (0);
}

int	wait_event(t_game *game)
{
	int	animation;

	animation = 0;
	game->frame++;
	if (game->frame == ANIMATION)
		animation = 1;
	else
		animation = 0;
	ft_bzero(game->img[0].pixels, IMG_SIZE);
	draw_new_image(game, animation);
	mlx_clear_window(game->mlx, game->win_ptr);
	mlx_put_image_to_window(game->mlx, game->win_ptr,
		game->img[0].img_ptr, 0, 0);
	game->frame = 0;
	return (0);
}