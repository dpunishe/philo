/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpunishe <dpunishe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:33:28 by dpunishe          #+#    #+#             */
/*   Updated: 2021/12/14 15:33:29 by dpunishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_get_min_fork(t_philo *philo)
{
	if (philo->l_fork < philo->r_fork)
		return (philo->l_fork - 1);
	else
		return (philo->r_fork - 1);
}

int	ft_get_max_fork(t_philo *philo)
{
	if (philo->l_fork > philo->r_fork)
		return (philo->l_fork - 1);
	else
		return (philo->r_fork - 1);
}

int	ft_get_r_fork(int i, t_data *data)
{
	if (i == 1)
		return (data->num_phil);
	else
		return (i - 1);
}

int	ft_write_status(t_philo *philo, char *str)
{
	unsigned long	time;

	time = get_time_ms();
	if (time - philo->last_eat <= philo->data->t_die)
	{
		if (philo->data->death == 1)
			return (0);
		printf("%lu %d %s", \
		time - philo->data->time_start - philo->data->num_phil * START_MS, \
		philo->id, str);
		return (1);
	}
	return (0);
}
