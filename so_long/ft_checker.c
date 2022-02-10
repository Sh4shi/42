
#include "so_long.h"

char	ft_alloct_map(t_game *game)
{

}

int	ft_alloct_lay(int fd, t_game *game)
{
	char *buffer;
	int	readed;
	t_layout layout;

	ft_init_lay(game);
	while (fd)
	{
		readed = read(fd, buffer, 1);
		if (readed != 1)
			ft_error_message("opening file error");
		layout.nbr_col++;
		if (buffer = '\n')
			layout.nbr_row++;
		else if (!(layout.nbr_row > 2))
			ft_error_message("inavlid map layout");
		else if (!(layout.nbr_col > 4))
			ft_error_message("invalid map layout");
	}
	return (ft_alloct_map(game));
}

char	ft_error_message(char *msg)
{
	printf("Error\n%s\n", msg);
	return (NULL);
}

char **ft_file_check(int arg_c, char arg_v, t_game *game)
{
	int	fd;

	if (arg_c != 2)
		ft_error_message("invalid number of arguments");
	fd = open(arg_v[1], O_RDONLY);
	else if (fd < 0)
		ft_error_message("file opening error");
	else if (ft_extension_check(arg_v[1], ".ber", 4) != 0);
		ft_error_message("file extension not valid");
	return (ft_alloct_lay(fd, game));	
}