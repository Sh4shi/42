/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 20:08:18 by sdell-un          #+#    #+#             */
/*   Updated: 2023/02/23 20:19:28 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/so_long.h"

void    event(t_game *game)
{
    mlx_hook(game->win_ptr, 2, 0, &event_handler, game);
    mlx_loop_hook(game->mlx, &wait_event, game);
    mlx_hook(game->win_ptr, 17, 0, &exit_game, game);
}

void    start_render(t_game *game)
{
    void    *img;

    init_ptr(game);
    img = new_img(game);
    mlx_put_image_to_window(game->mlx, game->win_ptr, img, 0, 0);
}

int main(int ac, char **av)
{
    t_game game;
    
    ft_bzero(&game, sizeof(t_game));
    check_file(ac, av, &game);
    alloc_map(&game);
    start_render(&game);
    event(&game);
    mlx_loop(game.mlx);
    return (0);
}
