/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 22:36:55 by rcuminal          #+#    #+#             */
/*   Updated: 2022/01/13 05:52:42 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/pipex_bonus.h"

int	ft_parsargv(char **argv, t_list **list, int argc)
{
	t_list	*tmp;
	int		i;

	i = 2;
	while (i < argc - 1)
	{
		tmp = ft_lstnew(ft_split(argv[i], ' ', 0));
		ft_lstadd_back(list, tmp);
		i++;
	}
	return (0);
}
