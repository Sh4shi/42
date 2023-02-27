#include  "./../include/philo.h"

int	main(int ac, char **av)
{
	t_table	table;

	memset(&table, 0, sizeof(t_table));
	if (ac != 5 && ac != 6)
		return (-1);
	else if (!check_args(&table, ac, av))
		return (-1);
	else
		return (0);
}
