/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:32:57 by Romain            #+#    #+#             */
/*   Updated: 2022/02/25 17:12:55 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// int    ft_checkarg(int argc, char **argv)
// {
    
// }

void	ft_printstate(t_val *val)
{
	
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
    usleep(val->tab[3]);
    return;
}

int ft_checkfork(t_val *val)
{
    
    return (0);
}

void    ft_eat(t_val *val, int numerus)
{
	struct timeval start;
    struct timeval end;
    
    gettimeofday(&start, NULL);
    pthread_mutex_lock(&(val->philo[numerus].forkette));
	if (numerus != 1)
		pthread_mutex_lock(&(val->philo[numerus-1].forkette));
	else
		pthread_mutex_lock(&(val->philo[val->tab[0] - 1].forkette));
    while (time_diff(&start, &end) < val->tab[2])
        gettimeofday(&end, NULL);
	if (numerus != 1)
		pthread_mutex_unlock(&(val->philo[numerus-1].forkette));
	else
		pthread_mutex_unlock(&(val->philo[val->tab[0] - 1].forkette));
    pthread_mutex_unlock(&(val->philo->forkette));
    return ;
}

void    ft_initmutex(t_val *val)
{
    int i;

    i = 0;
    while (i < val->tab[1])
    {
        if (pthread_mutex_init(&(val->philo[i].forkette), NULL) != 0)
            return ;
        i++;
    }
    return ;
}

void	*ft_recherche(void *arg)
{
    struct timeval start;
    struct timeval end;
    t_val           *val;
	int				numerus;

    val = arg;
	numerus = val->numerus;
    gettimeofday(&start, NULL);

    while(time_diff(&start, &end) < val->tab[1])
    {
        ft_eat(val, numerus);
        fprintf(stderr, "%f \n", time_diff(&start, &end));
        gettimeofday(&end, NULL);
    }

    return NULL;
}

int main(int argc, char **argv)
{
    t_val           *val;
    char    *str;

    str = 
    val->numerus = 1;
    if (argc > 4 || argc < 7)
    {
        val = ft_memalloc(sizeof(t_val));
        ft_parsarg(argc, argv, val);
        val->philo = ft_calloc(val->tab[0], sizeof(t_philosopher));
        ft_initmutex(val);
        while(val->numerus <= val->tab[0])
        {
            pthread_create(&(val->philo[val->numerus].philosopher), NULL, &ft_recherche, (void *)val);
			usleep(10);
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