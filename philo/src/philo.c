#include "./../include/philo.h"

uint64_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, 0);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	start_lunch(t_table *table)
{
	
}

int	main(int ac, char **av)
{
	t_table	table;

	memset(&table, 0, sizeof(t_table));
	if (!check_args(&table, ac, av))
		return (1);
	if (!init_struct(&table, ac, av))
        return (1);
	start_lunch(&table);
	return (0);
}
