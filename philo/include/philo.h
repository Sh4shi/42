
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

#define WRONG_ARG "Error!\nWrong arguments"
#define INIT_ERR "Error!\nImpossible reserve space for structs"
#define THRD_CREATE_ERR "Error!\nImpossible create thread"
#define THRD_DETACH_ERR "Error!\nSomething went wrong while detatching thread"
#define THRD_JOIN_ERR "Error\nMain thread get issue while joining monitor thread"

// philo's state
#define EAT 1
#define THINK 2
#define SLEEP 3
#define DIE 4

#define DINNING 1

typedef struct s_forks
{
	pthread_mutex_t 	*left;
	pthread_mutex_t 	*right;
    pthread_mutex_t     *locked;
}				t_forks;

typedef struct  s_input
{
    int expiration;
    int	eating_time;
    int	sleeping_time;
    int nbr_meal;
}               t_input;

typedef struct s_philo
{
    pthread_t   thread;
	int		    id;
    int         state;
	t_forks	    fork;
    t_input     *info;
	int		    meal_did;
}				t_philo;

typedef struct s_table
{
	int             nbr_philos;
	t_philo         *philo;
    pthread_mutex_t *forks;
    pthread_t       monitor;
    uint64_t        start_time;
    t_input         input;
    int             some_die;
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
int         end(char *msg);
void        *philo(void *arg);
void        *monitor(void *arg);

#endif