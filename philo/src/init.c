#include "./../include/philo.h"

void	init_fork(t_table *table)
{
    int	i;

    i = 0;
    table->forks = malloc(sizeof(pthread_mutex_t) * table->nbr_philos);
    while (i < table->nbr_philos)
    {
        pthread_mutex_init(&table->forks[i], 0);
        i++;
    }
}

void	init_philo(t_table *table, int ac, char **av)
{
	int	i;

	i = 0;
    init_fork(table);
	while (i < table->nbr_philos)
	{
		table->philo[i].id = i + 1;
		table->philo[i].expiration = ft_atoi(av[2]);
		table->philo[i].eating_time = ft_atoi(av[3]);
		table->philo[i].sleeping_time = ft_atoi(av[4]);
		table->philo[i].fork.left = table->forks[i];
        if (i == 0)
            table->philo[i].fork.right = table->forks[table->nbr_philos - 1];
        else
            table->philo[i].fork.right = table->philo[i - 1].fork.left;
		if (av[5])
			table->philo[i].nbr_meal = ft_atoi(av[5]);
		else
			table->philo[i].nbr_meal = 0;
		i++;
	}
}

int init_struct(t_table *table, int ac, char **av)
{
	table->nbr_philos = ft_atoi(av[1]);
	table->philo = malloc(sizeof(t_philo) * table->nbr_philos);
	if (!table->philo)
		return (0);
	init_philo(table, ac, av);
    return (1);
}