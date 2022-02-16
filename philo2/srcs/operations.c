/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 11:49:17 by rcuminal          #+#    #+#             */
/*   Updated: 2022/02/16 21:50:43 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_sleep(t_val *val)
{
	struct timeval	start;
	struct timeval	end;

	gettimeofday(&start, NULL);
	gettimeofday(&end, NULL);
	while (time_diff(&start, &end) < val->tab[3]
		&& val->allalive == 1)
	{
		usleep(100);
		gettimeofday(&end, NULL);
	}
	return ;
}

void	philoeat(t_val *val, t_philosopher *philo)
{
	struct timeval	start;
	struct timeval	end;

	gettimeofday(&start, NULL);
	gettimeofday(&philo->start, NULL);
	gettimeofday(&end, NULL);
	while (time_diff(&start, &end) < val->tab[2]
		&& val->allalive == 1)
	{
		usleep(100);
		gettimeofday(&end, NULL);
	}
	philo->meal += 1;
	return ;
}

int	ft_eat(t_val *val, t_philosopher *philo)
{
	if (pthread_mutex_lock(&(philo->forkette)) != 0 && printf(" f1\n"))
		return (1);
	if (philo->id != 1)
	{
		if (pthread_mutex_lock(&(val->philo[philo->id - 2].forkette)) != 0)
			return (1);
	}
	else
		if (pthread_mutex_lock(&(val->philo[val->tab[0] - 1].forkette)) != 0)
			return (1);
	philo->state = 2;
	if (val->allalive == 1)
		ft_printstate(philo, val);
	philo->state = 1;
	if (val->allalive == 1)
		ft_printstate(philo, val);
	philoeat(val, philo);
	if (philo->id != 1)
		pthread_mutex_unlock(&(val->philo[philo->id - 2].forkette));
	else
		pthread_mutex_unlock(&(val->philo[val->tab[0] - 1].forkette));
	pthread_mutex_unlock(&(philo->forkette));
	return (0);
}
