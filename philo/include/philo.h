
#ifndef PHILO_H
# define PHILO_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_philo
{

}				t_philo;

typedef struct s_table
{
	int	nbr_philos;
	int	expiration;
	int	eating_time;
	int	sleeping_time;
	int	nbr_meals;
}				t_table;

/*-------------------------check*/
/*--check.c--*/
bool	check_args(t_table *table, int ac, char **av);
bool	is_digit(char *str);
#endif