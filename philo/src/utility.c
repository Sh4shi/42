#include "./../include/philo.h"

uint64_t	get_time(void)
{
    struct timeval	tv;

    gettimeofday(&tv, 0);
    return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}