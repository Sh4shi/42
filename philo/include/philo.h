
#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <thread.h>
# include <pthread.h>
# include <synch.h>
# include <sys/time.h>

typedef struct  s_fork
{
    mutex_t *left;
    mutex_t *right;
}               t_fork;

typedef struct s_philo
{
    int         id;
    int	        expiration;
    int	        eating_time;
    int	        sleeping_time;
    t_fork      fork;
    int         nbr_meal;
    //int     status[3];
}				t_philo;

typedef struct s_table
{
	int      nbr_philos;
    t_philo     *philo;
    mutex_t     *fork;

}				t_table;

/*-------------------------check*/
/*--check.c--*/
bool	    check_args(t_table *table, int ac, char **av);
bool	    is_digit(char *str);
int         ft_atoi(const char *str);
void        init_fork(t_table *table);
void        init_philo(t_table *table);
uint64_t    get_time(void);
#endif