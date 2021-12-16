/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpunishe <dpunishe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:32:41 by dpunishe          #+#    #+#             */
/*   Updated: 2021/12/14 15:32:42 by dpunishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

//for memset
# include <string.h>
//for printf
# include<stdio.h>
//for malloc, free
# include<stdlib.h>
//for write, usleep,
# include<unistd.h>
//for gettimeofday
# include <sys/time.h>
//for	pthread_create, pthread_detach, pthread_join,
//		pthread_mutex_lock, pthread_mutex_unlock,
//		pthread_mutex_init, pthread_mutex_destroy
# include <pthread.h>
# define TAKE_FORK "has taken a fork\n"
# define EATING "is eating\n"
# define SLEEPING "is sleeping\n"
# define THINKING "is thinking\n"
# define DEID "died\n"
# define START_MS 2

typedef struct s_data
{
	int				num_phil;
	unsigned long	t_die;
	int				t_eat;
	int				t_sleep;
	int				max_eat;
	pthread_mutex_t	*forks;
	pthread_t		*philo_t;
	pthread_mutex_t	time_dead_m;
	int				death;
	int				error;
	unsigned long	time_start;
}	t_data;

typedef struct s_philo
{
	t_data			*data;
	int				id;
	int				death;
	unsigned long	last_eat;
	int				num_eat;
	int				l_fork;
	int				r_fork;
	int				max_fork;
	int				min_fork;
}	t_philo;

//philo.c
void			ft_philo(int argc, char **argv);
void			*philo_live(void *arg);
//get_param.c
void			init_data(t_data *data, int argc, char **argv);
//error_exit.c
void			ft_end_cleaner(t_data *data, t_philo *philo);
void			ft_destroy_forks(t_data *data);
int				ft_exit_philo(t_data *data, t_philo *philo);
void			ft_set_error(t_data *data, int error, char *message);
void			*ft_set_error2(t_data *data, int error, char *message);
//init.c
void			ft_init_philo(t_data *data, t_philo *arg);
void			ft_init_forks_time(t_data *data);
void			ft_join_thread(t_data *data);
//time.c
void			ft_usleep(t_data *data, int sleep_time_ms);
void			ft_wait_start(t_philo *phl);
void			ft_wait_to_time(t_philo *data, int sleep_to_time_ms);
unsigned long	get_time_ms(void);
//action.c
int				ft_take_forks(t_philo *philo);
int				ft_eat(t_philo *philo);
int				ft_philo_sleep(t_philo *philo);
int				ft_think(t_philo *philo);
//utilit.c
int				ft_get_min_fork(t_philo *philo);
int				ft_get_max_fork(t_philo *philo);
int				ft_get_r_fork(int i, t_data *data);
int				ft_write_status(t_philo *philo, char *str);

#endif
