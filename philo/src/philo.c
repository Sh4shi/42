#include "./../include/philo.h"

void *philo(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    if (philo->state == EAT)
        philo->state = philo_eat(philo);
    if (philo->state == THINK)
        philo->state = philo_think(philo);
    if (philo->state == SLEEP)
        philo->state = philo_sleep(philo);
    if (philo->state == DIE)
        philo->state = philo_die(philo);
}

void *monitor(void *arg)
{
    (uint64_t *)arg->start_time = get_time();
    while (DINNING)
    {
        if (arg->start_time >)
    }
}

int	main(int ac, char **av)
{
	t_table	table;
    int i;

    i = 0;
	memset(&table, 0, sizeof(t_table));
	if (!check_args(&table, ac, av))
		end( WRONG_ARG);
	if (!init_struct(&table, ac, av))
        end(INIT_ERR);
    pthread_create(&table.monitor, NULL, &monitor, &table);
    while(i < table.nbr_philos - 1;)
    {
        if (pthread_create(&table.philo[i]->thread, NULL, &philo, (void *)&table.philo[i]) != 0)
            end(THRD_CREATE_ERR);
        if (pthread_detach(&table.philo[i]->thread != 0))
            end(THRD_DETACH_ERR);
        i++;
    }
    if (pthread_join(table.monitor, NULL) != 0)
        end(THRD_JOIN_ERR);
	return (0);
}
