/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built-in2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 23:37:56 by rcuminal          #+#    #+#             */
/*   Updated: 2022/05/19 21:37:56 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_optionecho(char *str)
{
	int	i;
	int	alpha;

	i = 0;
	alpha = 0;
	while (str[i])
	{
		if (str[i] == '-' && str[i + 1] == 'n'
			&& str[i + 2] == ' ' && alpha == 0)
			return (1);
		if (ft_isprint(str[i]) == 1 && str[i] != ' ')
			alpha++;
		i++;
	}
	return (0);
}

void	builtin_echo(char *str)
{
	int	option;

	option = ft_optionecho(str + 4);
	if (option == 0)
		printf("%s\n", str + 5);
	else
		printf("%s", str + ft_strichr(str, '-') + 3);
}
