/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilss.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:03:31 by rcuminal          #+#    #+#             */
/*   Updated: 2022/05/04 21:53:16 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	setval(t_philosopher *philo, t_val *val)
{
	int	i;

	i = 0;
	philo->val = val;
	val->philo = philo;
	val->numerus = 0;
	val->allalive = 1;
	while (i < val->tab[0])
	{
		val->philo[i].id = i + 1;
		val->philo[i].meal = 0;
		val->philo[i].val = val;
		i++;
	}
	return ;
}

void	ft_parsarg(int argc, char **argv, t_val *val)
{
	int	i;

	i = 0;
	val->tab = ft_calloc(argc - 1, sizeof(int));
	while (i < argc - 1)
	{
		val->tab[i] = ft_atoi(argv[1 + i]);
		i++;
	}
}
