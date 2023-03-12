#include "./../include/philo.h"

void    kronos(t_table *table)
{
    
}

void	start_lunch(t_table *table)
{
    pthread_t   pthread;
    int         i;

    i = 0;
    table->start_time = get_time();
    /*while (table->some_die == 0 && table->all_eat < (table->nbr_meal * table->nbr_philos))
    {
        pthread_create();
    }*/
    pthread_create(&table->monitor, NULL, kronos, &table);
}

int	main(int ac, char **av)
{
	t_table	table;

	memset(&table, 0, sizeof(t_table));
	if (!check_args(&table, ac, av))
		return (-1);
	if (!init_struct(&table, ac, av))
        return (-1);
	start_lunch(&table);
	return (0);
}
