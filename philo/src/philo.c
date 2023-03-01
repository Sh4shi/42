#include  "./../include/philo.h"

uint64_t get_time(void)
{
    struct timeval tv;

    gettimeofday(&tv, 0);
    return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void    start_lunch(t_table *table)
{

}

void    init_philo(t_table *table, int ac, char **av)
{
    int i;

    i = 0;
    while(i < table->nbr_philos)
    {
        table->philo[i].id = i + 1;
        table->philo[i].expiration = ft_atoi(av[2]);
        table->philo[i].eating_time = ft_atoi(av[3]);
        table->philo[i].sleeping_time = ft_atoi(av[4]);
        if (i == table->nbr_philos - 1)
            table->philo[i].fork.right = table->fork[0];
        else
            table->philo[i].fork.right = table->fork[i + 1];
        table->philo[i].fork.left = table->fork[i];
        if(av[5])
            table->philo[i].nbr_meal = ft_atoi(av[5]);
        else
            table->philo[i].nbr_meal = -1;
        i++;
    }
}

void    init_fork(t_table *table)
{
    int i;

    i = 0;
    table->fork = malloc(sizeof(mutex_t) * table->nbr_philos);
    while (i < table->nbr_philos)
    {
        pthread_mutex_init(&table->fork[i], 0);
        i++;
    }
}

void    init_struct(t_table *table, int ac, char **av)
{
    table->nbr_philos = ft_atoi(av[1]);
    table->philo = malloc(sizeof(t_philo) * table->nbr_philos);
    if (!table->philo)
        return (0);
    init_fork(table);
    init_philo(table, ac, av);
}

int	main(int ac, char **av)
{
	t_table	table;

	memset(&table, 0, sizeof(t_table));
	if ((ac != 5 | ac != 6) | !check_args(&table, ac, av))
		return (-1);
    init_struct(&table, ac, av);
    start_lunch(&table);
    return (0);
}
