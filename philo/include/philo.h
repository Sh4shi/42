
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
# include <stdbool.h>
# include <stdio.h>

#define WRONG_ARG "Error!\nWrong arguments"
#define INIT_ERR "Error!\nImpossible reserve space for structs"
#define THRD_CREATE_ERR "Error!\nImpossible create thread"
#define THRD_DETACH_ERR "Error!\nSomething went wrong while detatching thread"
#define THRD_JOIN_ERR "Error\nMain thread get issue while joining monitor thread"

// philo's state
#define EAT 0
#define THINK 1
#define SLEEP 2
#define DIE 3

// barrier state
#define CLOSED 0
#define OPEN 1

#define DINNING 1

typedef struct s_fork
{
	pthread_mutex_t 	*fork;
    bool                taken;
    int                 bywho;
}				t_fork;

typedef struct  s_input
{
    int nbr_philos;
    int expiration;
    int	eating_time;
    int	sleeping_time;
    int nbr_meal;
    int barrier;
}               t_input;

typedef struct s_philo
{
    pthread_t   thread;
	int		    id;
    bool        alive;
    int         state;
	t_fork	    l_fork;
    t_fork      r_fork;
    t_input     *info;
	int		    meal_did;
}				t_philo;

typedef struct s_table
{
	t_philo         *philo;
    pthread_mutex_t *forks;
    pthread_t       monitor;
    uint64_t        start_time;
    t_input         input;
}				t_table;

bool		    check_args(t_table *table, int ac, char **av);
bool		    is_digit(char *str);
int			    ft_atoi(const char *str);
int             init_struct(t_table *table, int ac, char **av);
int		        init_fork(t_table *table);
int		        init_philo(t_table *table);
uint64_t	    get_time(void);
int             end(char *msg);
void            *philo(void *arg);
void            *monitor(void *arg);
__thread int    *define_routine();
int             execute(int (*routine)(void *arg));
void            take_fork(t_fork *l_fork, t_fork *r_fork);
void            delay(uint64_t start_time, int delay);

#endif