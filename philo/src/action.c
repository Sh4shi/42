#include "./../include/philo.h"

void execute(int (*routine)(void *arg))
{
    arg->state = routine(arg));
}

int philo_die(t_philo *philo)
{
    return ();
}

int philo_think(t_philo *philo)
{
    return ();
}

int philo_sleep(t_philo *philo)
{
    return ();
}

int philo_eat(t_philo *philo)
{
    take_fork(philo->l_fork, philo->r_fork);
    return ();
}