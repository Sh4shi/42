/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 22:21:20 by sdell-un          #+#    #+#             */
/*   Updated: 2022/02/07 04:16:34 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "./libft2/libft.h"

typedef	struct s_doortyle
{
	void		*open;
	void		*dalf;
	void		*exit;
	void		*closed;
}				t_doortyle;

typedef	struct s_enemytyle
{
	void	*move1;
	void	*move2;
	void	*move3;	
}				t_enemytyle;

typedef struct s_playerdeath
{
	void	*death1;
	void	*death2;
	void	*death3;
	void	*death4;
	void	*death5;
}				t_playerdeath;

typedef struct s_collectanimation
{
	void	*collect1;
	void	*collect2;
	void	*collect3;
}				t_collectanimation;

typedef struct s_walkanimation
{
	void	*step1;
	void	*step2;
	void	*step3;
}				t_walkanimation;

typedef struct	s_standanimation
{
	void	*stand1;
	void	*stand2;
	void	*stand3;
	void	*stand4;
	void	*stand5;
	void	*stand6;
}				t_standanimation; 

typedef	struct s_playertyle
{
	t_standanimation		*pstand;
	t_walkanimation			*pwalk;
	t_collectanimation		*pcollect;
	t_playerdeath			*pdeath;
}				t_playertyle;

typedef struct s_collecttyle
{
	void	*collectable1;
	void	*collectable2;
	void	*collectable3;
}				t_collecttyle;

typedef struct s_walltyle
{
	void	*frame;
	void	*wall;
}				t_walltyle;

typedef struct s_tyle
{
	t_walltyle		*imgwall;
	t_collecttyle	*imgcollectlable;
	t_playertyle	*imgplayer;
	t_enemytyle		*imgenemy;
	t_doortyle		*imgdoor;
}				t_tyle;

typedef struct s_vector
{
	int y;
	int x;
}				t_vector;

typedef enum e_map
{
	empty = '0',
	wall = '1',
	collectable = 'C',
	player = 'P',
	exit = 'E',
	enemy = 'M', 
}			t_map;

enum	e_keycode
{
	KEY_UP = 13,
	KEY_DOWN = 1,
	KEY_LEFT = 0,
	KEY_RIGHT = 2,
	RESET = 15,
	ESC = 53,	
};

typedef	struct s_game
{
	void		*mlx;
	void		*window;
	t_vector	*wndsize;
	t_map		*map;
	t_tyle		*tyle;
	int			counter;
}				t_game;

#endif