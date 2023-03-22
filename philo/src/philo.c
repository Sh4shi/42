#include "./../include/philo.h"

void *philo(void *arg)
{
    t_philo         *philo;
    __thread int    *routine;

    routine = define_routine();
    philo = (t_philo *)arg;
    while (philo->info->barrier == CLOSED)
        continue ;
    while (philo->alive == TRUE)
        execute(routine[philo->state], arg);
}

void *monitor(void *arg)
{
    t_table *table;

    table = (t_table *)arg;
    table->start_time = get_time();
    delay(table->start_time, table->input.nbr_philos * 2 * 10);
    table->input.barrier = OPEN;
    while (DINNING)
    {

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
