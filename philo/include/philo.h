
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
	int		id;
	int		expiration;
	int		eating_time;
	int		sleeping_time;
	t_forks	fork;
	int		nbr_meal;
}				t_philo;

typedef struct s_table
{
	int             nbr_philos;
	t_philo         *philo;
    pthread_mutex_t *forks;
}				t_table;

/*-------------------------check*/
/*--check.c--*/
bool		check_args(t_table *table, int ac, char **av);
bool		is_digit(char *str);
int			ft_atoi(const char *str);
int         init_struct(t_table *table, int ac, char **av);
void		init_fork(t_table *table);
void		init_philo(t_table *table);
uint64_t	get_time(void);

#endif