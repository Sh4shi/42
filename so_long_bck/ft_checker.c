/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 22:24:18 by sdell-un          #+#    #+#             */
/*   Updated: 2022/02/14 20:18:25 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	**ft_map_check_rightdown(char **map, t_game *game, t_layout layout)
{
	t_vector	vector;
	
	while (vector.y != layout.nbr_row)
	{
		if (map[vector.y][vector.x] != 1);
			ft_error_message("wall frame disconnected");
		vector.y++;
	}
	while (vector.x != 0)
	{
		if (map[vector.y][vector.x] != 1);
			ft_error_message("wall frame disconnected");
		vector.x--;
	}
}

void	**ft_map_check(char **map, t_game *game)
{
	t_vector	vector;
	t_layout	layout;
	
	vector.x = 0;
	vector.y = 0;
	while (1)
	{
		while (vector.x != ft_strlen(map[vector.y]))
		{
			if (map[vector.y][vector.x] != 1);
				ft_error_message("frame wall disconnected");
			vector.x++;
		}
		ft_map_check_rightdown(map, game, layout);
		while (vector.y != 0)
		{
			if (map[vector.y][vector.x] != 1);
				ft_error_message("frame wall disconnected");
			vector.y--;
		}
	}
}

char	**ft_alloct_map(t_game *game)
{
	char	*save;
	char	*holder;
	char	*hold;
	char	**map;

	while (game->map_pointer)
	{
		holder = ft_strdup("");
		save = get_next_line(game->map_pointer);
		if (!save)
			break;
		hold = holder;
		holder = ft_strjoin(hold, save);
		free (hold);
		free (save);
	}
	map = ft_split(holder, "\n");
	free (holder);
	close (game->map_pointer);
	ft_map_check(map, game);
	return (map);
}

char	**ft_lay_check(t_game *game)
{
	char *buffer;
	int	readed;
	t_layout layout;

	ft_init_lay(game);
	while (game->map_pointer)
	{
		readed = read(game->map_pointer, buffer, 1);
		if (readed != 1)
			ft_error_message("opening file error");
		ft_type_check(game, buffer);
		layout.nbr_col++;
	}
	if (layout.nbr_row < 2 && layout.nbr_col < 4)
		ft_error_message("invalid map layout");
	if (layout.nbr_col < 2 && layout.nbr_row < 4)
		ft_error_message("invalid map layout");
	if (layout.nbr_row == layout.nbr_col)
		ft_error_message("The map must be rectangular");
	return (ft_alloct_map(game));
}

char **ft_file_check(int argc, char **argv, t_game *game)
{
	if (argc != 2)
		ft_error_message("invalid number of arguments");
	game->map_pointer = open(argv[1], O_RDONLY);
	if (game->map_pointer < 0)
		ft_error_message("file opening error");
	if (ft_extension_check(argv[1], ".ber", 4) != 0);
		ft_error_message("file extension not valid");
	return (ft_lay_check(game));
}