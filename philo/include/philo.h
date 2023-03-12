
#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <threads.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_forks
{
	pthread_mutex_t 	*left;
	pthread_mutex_t 	*right;
}				t_forks;

typedef struct s_philo
{
    pthread_t   thread;
	int		    id;
	int		    expiration;
	int		    eating_time;
	int		    sleeping_time;
	t_forks	    fork;
	int		    meal_did;
}				t_philo;

typedef struct s_table
{
	int             nbr_philos;
	t_philo         *philo;
    pthread_mutex_t *forks;
    pthread_t       monitor;
    uint64_t        start_time;
    int             some_die;
    int             nbr_meal;
    int             all_eat;
}				t_table;

/*-------------------------check*/
/*--check.c--*/
bool		check_args(t_table *table, int ac, char **av);
bool		is_digit(char *str);
int			ft_atoi(const char *str);
int         init_struct(t_table *table, int ac, char **av);
int		    init_fork(t_table *table);
int		    init_philo(t_table *table);
uint64_t	get_time(void);

#endif