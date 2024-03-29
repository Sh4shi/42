#include "./../include/philo.h"

int init_fork(t_table *table)
{
    int	i;

    i = 0;
    table->forks = malloc(sizeof(pthread_mutex_t) * table->nbr_philos);
    if (!table->forks)
        return (0);
    while (i < table->nbr_philos)
    {
        pthread_mutex_init(&table->forks[i], 0);
        i++;
    }
    return (1);
}

int	init_philo(t_table *table)
{
	int	i;

	i = 0;
    if (!init_fork(table))
        return (0);
	while (i < table->nbr_philos - 1)
	{
		table->philo[i].id = i + 1;
        table->philo[i].alive = TRUE;
        if (table->philo[i].id % 2 == 0)
            table->philo[i].state = EAT;
        else
            table->philo[i].state = THINK;
		table->philo[i].l_fork.fork = table->forks[i];
        table->philo[i].l_fork.taken = FALSE;
        table->philo[i].l_fork.bywho = -1;
        if (i == 0)
            table->philo[i].r_fork.fork = table->forks[table->nbr_philos - 1];
        else
            table->philo[i].r_fork.fork = table->philo[i - 1].l_fork.fork;
        table->philo[i].r_fork.taken = FALSE;
        table->philo[i].r_fork.bywho = -1;
        table->philo[i].meal_did = 0;
        table->philo[i]->info = &table->input;
		i++;
	}
    return (1);
}

int init_struct(t_table *table, int ac, char **av)
{
	table->input.nbr_philos = ft_atoi(av[1]);
    table->input.expiration = ft_atoi(av[2]);
    table->input.eating_time = ft_atoi(av[3]);
    table->input.sleeping_time = ft_atoi(av[4]);
    if (av[5])
        table->input.nbr_meal = ft_atoi(av[5]);
    else
        table->input.nbr_meal = 1;
    table->input.barrier = CLOSED;
	table->philo = malloc(sizeof(t_philo) * table->nbr_philos);
	if (!table->philo)
		return (0);
	if (!init_philo(table))
        return (0);
    return (1);
}