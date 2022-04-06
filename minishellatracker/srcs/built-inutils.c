/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built-inutils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 02:25:13 by rcuminal          #+#    #+#             */
/*   Updated: 2022/04/06 02:25:52 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	contentequal(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_compare(char *prev, char *next)
{
	int	i;

	i = 0;
	while (prev[i] && next[i])
	{
		if (prev[i] < next[i])
			return (1);
		if (prev[i] > next[i])
			return (-1);
		i++;
	}
	if (!prev[i])
		return (1);
	return (-1);
}