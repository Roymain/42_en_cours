/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_single_quote.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:28:29 by mathmart          #+#    #+#             */
/*   Updated: 2022/05/26 19:20:11 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_simple(char *str, int *i, t_track *tracker)
{
	char	*tmp;
	int		j;

	j = -1;
	tmp = ft_track(malloc((ft_strlen(str) - 1) * sizeof(char)), tracker);
	while (str[++j] && j < *i)
		tmp[j] = str[j];
	j++;
	while (str[j] && str[j] != '\'')
	{
		tmp[j - 1] = str[j];
		j++;
	}
	*i = j - 2;
	j++;
	while (str[j] != '\0')
	{
		tmp[j - 2] = str[j];
		j++;
	}
	tmp[j - 2] = '\0';
	return (tmp);
}
