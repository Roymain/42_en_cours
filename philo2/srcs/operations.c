/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 11:49:17 by rcuminal          #+#    #+#             */
/*   Updated: 2022/05/05 00:48:00 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_sleep(t_philosopher *philo)
{
	struct timeval	start;
	struct timeval	end;

	gettimeofday(&start, NULL);
	gettimeofday(&end, NULL);
	while (time_diff(&start, &end) < philo->val->tab[3] && time_diff(&philo->start, &end) < philo->val->tab[1]
		&& philo->val->allalive == 1)
	{
	//	usleep(100);
		gettimeofday(&end, NULL);
	}
	return ;
}

void	philoeat(t_val *val, t_philosopher *philo)
{
	struct timeval	start;
	struct timeval	end;

	gettimeofday(&start, NULL);
	gettimeofday(&(philo->start), NULL);
	gettimeofday(&end, NULL);
	while (philo->val->allalive == 1 && time_diff(&start, &end) < val->tab[2] && time_diff(&philo->start, &end) < philo->val->tab[1])
	{
	//	usleep(100);
		gettimeofday(&end, NULL);
	}
	philo->meal += 1;
	return ;
}

int	ft_eat(t_val *val, t_philosopher *philo)
{
	if (pthread_mutex_lock(&(philo->forkette)) != 0)
		return (1);
	if (philo->id != 1)
	{
		 pthread_mutex_lock(&(philo->val->philo[philo->id - 2].forkette));

		
	}
	else
	{
		pthread_mutex_lock(&(philo->val->philo[val->tab[0] - 1].forkette));
	}
	philo->state = 2;
			if (philo->val->allalive == 1)
				ft_printstate(philo, val);
			philo->state = 1;
			if (philo->val->allalive == 1)
				ft_printstate(philo, val);
		 	philoeat(val, philo);
			if (philo->id != 1)
				pthread_mutex_unlock(&(philo->val->philo[philo->id - 2].forkette));
			else
				pthread_mutex_unlock(&(philo->val->philo[val->tab[0] - 1].forkette));
		 	pthread_mutex_unlock(&(philo->forkette));
	// if (pthread_mutex_lock(&(philo->forkette)) != 0)
	// 	return (1);
	// if (philo->id != 1)
	// {
	// 	if (pthread_mutex_lock(&(val->philo[philo->id - 2].forkette)) != 0)
	// 	{
	// 		fprintf(stderr, "PROUT");
	// 		pthread_mutex_unlock(&(philo->forkette));
	// 		return (1);
	// 	}
	// }
	// else
	// {
	// 	if (pthread_mutex_lock(&(val->philo[val->tab[0] - 1].forkette)) != 0)
	// 	{
	// 		fprintf(stderr, "PROUT");
	// 		pthread_mutex_unlock(&(philo->forkette));
	// 		return (1);
	// 	}
	// }
	return (0);
}
