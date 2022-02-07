/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:22:58 by Romain            #+#    #+#             */
/*   Updated: 2022/01/29 21:35:54 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philosopher
{
    pthread_t			philosopher;
    struct timeval             start;
    struct timeval             end;
	int     state;
    int     eating;
	int		i;
	
    pthread_mutex_t		forkette;
}           t_philosopher;

typedef struct s_val
{
	int				numerus;
    
    int             alive;
	
	struct timeval startprog;
	
    t_philosopher *philo;
	pthread_mutex_t		write;
    int             *tab;
}			t_val;

float   time_diff(struct timeval *start, struct timeval *end);
void	*ft_calloc( size_t elementCount, size_t elementSize);
void	*ft_memalloc(size_t size);
int	    ft_atoi(char *str);


#endif

//// peut etre rajoyter start et end dans philo pr pouvoir reset une fois qu ils ont mange
