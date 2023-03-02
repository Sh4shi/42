#include "./../include/philo.h"

void	init_philo(t_table *table, int ac, char **av)
{
	int	i;

	i = 0;
	while (i < table->nbr_philos)
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
		if (av[5])
			table->philo[i].nbr_meal = ft_atoi(av[5]);
		else
			table->philo[i].nbr_meal = -1;
		i++;
	}
}

void	init_fork(t_table *table)
{
	int	i;

	i = 0;
	table->fork = malloc(sizeof(mutex_t) * table->nbr_philos);
	while (i < table->nbr_philos)
	{
		pthread_mutex_init(&table->fork[i], 0);
		i++;
	}
}

void	init_struct(t_table *table, int ac, char **av)
{
	table->nbr_philos = ft_atoi(av[1]);
	table->philo = malloc(sizeof(t_philo) * table->nbr_philos);
	if (!table->philo)
		return (0);
	init_fork(table);
	init_philo(table, ac, av);
}