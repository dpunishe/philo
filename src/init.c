/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpunishe <dpunishe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:33:10 by dpunishe          #+#    #+#             */
/*   Updated: 2021/12/14 15:33:11 by dpunishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_join_thread(t_data *data)
{
	int	i;

	if (data->error)
		return ;
	i = 0;
	while (i < data->num_phil)
	{
		pthread_join(data->philo_t[i], NULL);
		i++;
	}
}

void	ft_init_forks_time(t_data *data)
{
	int				i;
	struct timeval	time;

	if (data->error)
		return ;
	i = 0;
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
	* data->num_phil);
	if (!data->forks)
		return (ft_set_error(data, 1, "Error malloc for data.forks\n"));
	while (i < data->num_phil)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
			return (ft_set_error(data, 2, "Error mutex forks init\n"));
		i++;
	}
	if (gettimeofday(&time, NULL))
		ft_set_error(data, 2, "Error gettimeofday time\n");
	data->time_start = (time.tv_sec * 1000 + time.tv_usec / 1000);
	if (pthread_mutex_init(&data->time_dead_m, NULL))
		return (ft_set_error(data, 2, "Error mutex init time_dead\n"));
}

void	ft_init_philo(t_data *data, t_philo *arg)
{
	int		i;

	if (data->error)
		return ;
	data->philo_t = (pthread_t *)malloc(sizeof(pthread_t) * data->num_phil);
	if (!data->philo_t)
		return (ft_set_error(data, 3, "Error malloc for data.philo\n"));
	i = 0;
	while (i < data->num_phil)
	{
		if (!pthread_create(&data->philo_t[i], NULL, philo_live, &arg[i]))
			i++;
		else
			return (ft_set_error(data, 4, "Error pthread_create\n"));
	}
}
