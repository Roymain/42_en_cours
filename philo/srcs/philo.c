/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:32:57 by Romain            #+#    #+#             */
/*   Updated: 2022/02/09 01:29:21 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// int    ft_checkarg(int argc, char **argv)
// {
	
// }

void	ft_printstate(t_philosopher philosopher, t_val *val)
{
	struct timeval  time;

	gettimeofday(&time, NULL);
	if (val->alive == 1)
	{
		if (philosopher.state == 0)
			fprintf(stderr, "%f philosopher %d is thinking \n", time_diff(&(val->startprog), &time ), philosopher.i);
		if (philosopher.state == 1)
			fprintf(stderr, "%f philosopher %d is eating \n", time_diff(&(val->startprog), &time ), philosopher.i);
		if (philosopher.state == 2)
			fprintf(stderr, "%f philosopher %d is taking forks \n", time_diff(&(val->startprog), &time ), philosopher.i);
		if (philosopher.state == 3)
			fprintf(stderr, "%f philosopher %d is sleeping \n", time_diff(&(val->startprog), &time ), philosopher.i);
	}
	// if (philosopher.state == 4)
	//     printf("philosopher %d returned forks", philosopher.i);
}

void    ft_parsarg(int argc, char **argv, t_val *val)
{
	int i;

	i = 0;
	val->tab = ft_calloc(argc - 1, sizeof(int));
	while (i < argc - 1)
	{
		val->tab[i] = ft_atoi(argv[1 + i]);
		i++;
	}
}

// void    ft_creathreads(t_val *val)
// {
//     pthread_create()
// }

void    ft_sleep(t_val *val)
{
	usleep(val->tab[3] * 1000);
	return;
}

// int ft_checkfork(t_val *val)
// {
//     if ()
//     return (0);
// }

int    ft_eat(t_val *val, int numerus)
{
	struct timeval	start;
	struct timeval	end;

	gettimeofday(&start, NULL);
	gettimeofday(&end, NULL);
	if (pthread_mutex_lock(&(val->philo[numerus - 1].forkette)) != 0)
		return (1);
	if (numerus != 1){
		if (pthread_mutex_lock(&(val->philo[numerus - 2].forkette)) != 0)
			return (1);}
	else 
		if (pthread_mutex_lock(&(val->philo[val->tab[0] - 1].forkette)) != 0)
			return (1);
	val->philo[numerus - 1].state = 2;
	if (val->alive == 1)
		ft_printstate(val->philo[numerus - 1], val);
	val->philo[numerus - 1].state = 1;
	if (val->alive == 1)
		ft_printstate(val->philo[numerus - 1], val);
	while (time_diff(&start, &end) < val->tab[2] / 1000 && val->alive == 1)
	{
		val->philo[numerus - 1].eating = 1;
		gettimeofday(&end, NULL);
	}

	val->philo[numerus - 1].eating = 0;
	if (numerus != 1)
		pthread_mutex_unlock(&(val->philo[numerus - 2].forkette));
	else
		pthread_mutex_unlock(&(val->philo[val->tab[0] - 1].forkette));
	pthread_mutex_unlock(&(val->philo[numerus - 1].forkette));
	return (0);
}

int ft_checksicagraille(t_val *val, int numerus)
{
	// if (numerus != 1 && numerus != val->tab[0])
	// {
	// 	if (val->philo[numerus - 2].eating == 0 && val->philo[numerus].eating == 0)
	// 		return (1);
	// 	else
	// 		return (0);
	// }
	// if (numerus == 1)
	// {
	// 	if (val->philo[numerus].eating == 0 && val->philo[val->tab[0] - 1].eating == 0)
	// 		return (1);
	// 	else
	// 		return (0);
	// }
	// if (numerus == val->tab[0])
	// {
	// 	if (val->philo[0].eating == 0 && val->philo[val->tab[0] - 2].eating == 0)
	// 		return (1);
	// 	else
	// 		return (0);
	// }
	return (1);
}

void    ft_initmutex(t_val *val)
{
	int	i;

	i = 0;
	while (i < val->tab[0])
	{
		if (pthread_mutex_init(&(val->philo[i].forkette), NULL) != 0)
			return ;
		i++;
	}
	if (pthread_mutex_init(&(val->write), NULL) != 0)
		return ;
	return ;
}

void    ft_destroyallmutex(t_val *val)
{
	int	i;

	i = 0;
	while (i < val->tab[0])
	{
		if (pthread_mutex_destroy(&(val->philo[i].forkette)) != 0)
			return ;
		i++;
	}
	return ;
}

void	*ft_recherche(void *arg)
{
	struct timeval	start;
	struct timeval	end;
	t_val			*val;
	int				numerus;

	val = arg;
	numerus = val->numerus + 1;
	val->philo[numerus - 1].i = numerus;
	val->philo[numerus - 1].dead = 0;
	val->philo[numerus - 1].eating = 0;
	gettimeofday(&val->startprog, NULL);
	gettimeofday(&(val->philo[numerus - 1].start), NULL);
  //  fprintf(stderr, "philo nb = %d ", numerus);
	val->philo[numerus - 1].state = 0;
	ft_printstate(val->philo[numerus - 1], val);
	while (time_diff(&(val->startprog),
			&(val->philo[numerus - 1].end)) <= val->tab[1] / 1000
		&& val->alive == 1 && val->tab[0] > 1)
	{
		if (ft_checksicagraille(val, numerus) == 1)
		{
			if (ft_eat(val, numerus) == 0)
			{
				val->philo[numerus - 1].state = 3;
				if (val->alive == 1)
					ft_printstate(val->philo[numerus - 1], val);
				ft_sleep(val);
				gettimeofday(&(val->philo[numerus - 1].start), NULL);
				gettimeofday(&(val->philo[numerus - 1].end), NULL);
				val->philo[numerus - 1].state = 0;
				if (val->alive == 1)
					ft_printstate(val->philo[numerus - 1], val);
			}
		}
		gettimeofday(&(val->philo[numerus - 1].end), NULL);
	}
	if (val->alive == 0)
		return (arg);
	val->alive = 0;
	if (time_diff(&(val->startprog),
			&(val->philo[numerus - 1].end)) >= val->tab[1] / 1000
		&& val->tab[0] > 1)
		val->philo[numerus - 1].dead = 1;
   //fprintf(stderr, "prout");
	if (val->philo[numerus - 1].dead == 1)
	{
		usleep(10);
		pthread_mutex_lock(&(val->write));
		ft_printstate(val->philo[numerus - 1], val);
		fprintf(stderr, "philo %d est mort", numerus);
		pthread_mutex_unlock(&(val->write));
	//	usleep(100);
	}
	return (arg);
}

int main(int argc, char **argv)
{
	t_val	*val;

	if (argc > 4 || argc < 7)
	{
		val = ft_memalloc(sizeof(t_val));
		val->numerus = 0;
		val->alive = 1;
		ft_parsarg(argc, argv, val);
		val->philo = ft_calloc(val->tab[0], sizeof(t_philosopher));
		ft_initmutex(val);
		while (val->numerus < val->tab[0] && val->alive == 1)
		{
			pthread_create(&(val->philo[val->numerus].philosopher),
				NULL, &ft_recherche, (void *)val);
			usleep(5);
			val->numerus++;
		}
		while (val->numerus != 0)
		{
			pthread_join(val->philo[val->numerus].philosopher, NULL);
			val->numerus--;
		}
		return (0);
	}
}






// pthread_create


//  creeer plusieurs threads, liste chaine ? pas de fork ou de pipe etc? comment interpreter la fonction "manger"