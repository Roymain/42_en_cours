/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:32:57 by Romain            #+#    #+#             */
/*   Updated: 2022/02/16 22:02:47 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_pattern(t_val *val, t_philosopher *philo)
{
	if (philo->id % 2 == 0)
	{
		philo->state = 3;
		ft_printstate(philo, val);
		usleep(5);
	}
	philo->state = 0;
	ft_printstate(philo, val);
	while (time_diff(&(philo->start), &(philo->end)) <= val->tab[1]
		- val->tab[3] && val->allalive == 1 && val->tab[0] > 1)
	{
		if (ft_eat(val, philo) == 0)
		{
			philo->state = 3;
			if (val->allalive == 1)
				ft_printstate(philo, val);
			ft_sleep(val);
			gettimeofday(&(philo->end), NULL);
			philo->state = 0;
			if (val->allalive == 1)
				ft_printstate(philo, val);
		}
		usleep(10);
		gettimeofday(&(philo->end), NULL);
	}
}

void	ft_setthread(t_val *val, t_philosopher *philo)
{
	gettimeofday(&(philo->start), NULL);
	philo->dead = 0;
}

void	ft_patternmeal(t_val *val, t_philosopher *philo)
{
	if (philo->id % 2 == 0)
	{
		philo->state = 3;
		ft_printstate(philo, val);
		usleep(5);
	}
	philo->state = 0;
	ft_printstate(philo, val);
	while (time_diff(&(philo->start), &(philo->end)) <= val->time
		&& val->allalive == 1 && val->tab[0] > 1 && philo->meal < val->tab[4])
	{
		if (ft_eat(val, philo) == 0)
		{
			philo->state = 3;
			if (val->allalive == 1)
				ft_printstate(philo, val);
			ft_sleep(val);
			gettimeofday(&(philo->end), NULL);
			philo->state = 0;
			if (val->allalive == 1)
				ft_printstate(philo, val);
		}
		usleep(10);
		gettimeofday(&(philo->end), NULL);
	}
}

void	*ft_recherche(void *arg)
{
	t_philosopher	*philo;
	t_val			*val;
	int				numerus;

	philo = (t_philosopher *)arg;
	val = philo->val;
	ft_setthread(val, philo);
	if (val->tab[4] != 0)
		ft_patternmeal(val, philo);
	else
		ft_pattern(val, philo);
	if (val->allalive == 0)
	{
		numerus += 1;
		return (arg);
	}
	if (time_diff(&(philo->start), &(philo->end)) >= val->tab[1] - val->tab[3])
	{
		val->allalive = 0;
		philo->dead = 1;
	}
	if (philo->dead == 1)
		ft_dead(val, philo);
	return (arg);
}

int	main(int argc, char **argv)
{
	t_val			*val;
	t_philosopher	*philo;

	if (argc > 4 && argc < 7)
	{
		val = ft_memalloc(sizeof(t_val));
		ft_parsarg(argc, argv, val);
		philo = ft_memalloc(sizeof(t_philosopher) * val->tab[0]);
		setval(philo, val);
		ft_initmutex(val);
		gettimeofday(&val->startprog, NULL);
		while (val->numerus < val->tab[0])
		{
			pthread_create(&(val->philo[val->numerus].philosopher),
				NULL, &ft_recherche, (void *)&(val->philo[val->numerus]));
			val->numerus++;
		}
		while (val->numerus != 0)
		{
			pthread_join(val->philo[val->numerus].philosopher, NULL);
			val->numerus--;
		}
		return (0);
	}
	return (write(1, "Invalid number of arguments.", 29));
}

// void	*ft_recherche(void *arg)
// {
// 	struct timeval	start;
// 	struct timeval	end;
// 	t_philosopher	*philo;
// 	t_val			*val;
// 	int				numerus;

// 	philo = (t_philosopher *)arg;
// 	val = philo->val;
// //	philo->start = val->startprog;
// 	gettimeofday(&(philo->start), NULL);
// 	philo->dead = 0;
// 	if (philo->id % 2 == 0)
// 	{
// 		philo->state = 3;
// 		ft_printstate(philo, val);
// 		usleep(5);
// 	}
// 	philo->state = 0;
// 	ft_printstate(philo, val);
// 	while (time_diff(&(philo->start), &(philo->end)) <= val->tab[1]
// 		- val->tab[3] && val->allalive == 1 && val->tab[0] > 1)
// 	{
// 		if (ft_eat(val, philo) == 0)
// 		{
// 			philo->state = 3;
// 			if (val->allalive == 1)
// 				ft_printstate(philo, val);
// 			ft_sleep(val);
// 			gettimeofday(&(philo->end), NULL);
// 			philo->state = 0;
// 			if (val->allalive == 1)
// 				ft_printstate(philo, val);
// 		}
// 		usleep(10);
// 		gettimeofday(&(philo->end), NULL);
// 	}
// 	if (val->allalive == 0)
// 	{
// 		numerus += 1;
// 		return (arg);
// 	}
// 	val->allalive = 0;
// 	if (time_diff(&(philo->start),
// 			&(philo->end)) >= val->tab[1] - val->tab[3])
// 		philo->dead = 1;
// 	if (philo->dead == 1)
// 	{
// 		while (philo->val->numerus < val->tab[0] - 1)
// 		{
// 			printf("");
// 		}
// 		pthread_mutex_lock(&(philo->val->write));
// 		fprintf(stderr, "%d %d died\n", time_diff(&(val->startprog),
// 				&(philo->end)), philo->id);
// 		pthread_mutex_unlock(&(philo->val->write));
// 	}
// 	return (arg);
// }