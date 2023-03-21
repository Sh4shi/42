#include "./../include/philo.h"

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
    printf("\n%llu Philo %d is sleepping", get_time(), philo->id);
    usleep(philo->info->sleeping_time);
    return (EAT);
}

int philo_eat(t_philo *philo)
{
    pthread_mutex_lock(philo->fork.left);
    pthread_mutex_lock(philo->fork.right);
    printf("\n%llu Philo %d is eating", get_time(), philo->id);
    usleep(philo->info->eating_time);
    pthread_mutex_unlock(philo->fork.right);
    pthread_mutex_unlock(philo->fork.left);
    philo->meal_did += 1;
    return (SLEEP);
}