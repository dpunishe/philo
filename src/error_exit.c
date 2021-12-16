/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpunishe <dpunishe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:33:01 by dpunishe          #+#    #+#             */
/*   Updated: 2021/12/15 15:46:29 by dpunishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_end_cleaner(t_data *data, t_philo *philo)
{
	if (data->error)
	{
		ft_exit_philo(data, philo);
		return ;
	}
	free(data->forks);
	free(data->philo_t);
	free(philo);
}

void	ft_destroy_forks(t_data *data)
{
	int	i;

	if (data->error)
		return ;
	i = 0;
	while (i < data->num_phil)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->time_dead_m);
}

int	ft_exit_philo(t_data *data, t_philo *philo)
{
	if (data->error >= 2)
		free(data->forks);
	if (data->error >= 4)
		free(data->philo_t);
	if (data->error >= 3 && philo)
		free(philo);
	return (0);
}

void	ft_set_error(t_data *data, int error, char *message)
{
	if (error)
	{
		data->error = error;
		printf("%s", message);
	}
	return ;
}

void	*ft_set_error2(t_data *data, int error, char *message)
{
	if (error)
	{
		data->error = error;
		printf("%s", message);
	}
	return (NULL);
}
