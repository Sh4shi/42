#include "./../include/philo.h"

void    delay(uint64_t start_time, int delay)
{
    while (get_time_in_ms() < start_time + delay)
        continue ;
}

__thread int *define_routine()
{
    __thread int *routine;

    routine = malloc(sizeof(int *) * 4);
    routine[EAT] = &philo_eat;
    routine[THINK] = &philo_think;
    routine[SLEEP] = &philo_sleep;
    routine[DIE] = &philo_die;
    return (routine);
}

int end(char *msg)
{
    printf("\n%s", msg);
    return (0);
}

uint64_t	get_time(void)
{
    struct timeval	tv;

    gettimeofday(&tv, 0);
    return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}