/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built-inutils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 02:25:13 by rcuminal          #+#    #+#             */
/*   Updated: 2022/05/12 23:42:57 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	already_in(t_list	*list, char *key)
{
	t_list	*tmp;

	tmp = list;
	while (tmp)
	{
		if (ft_strncmp(key, tmp->key, ft_strichr(key, '=')) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	export_modif(t_list *list, char *content)
{
	t_list	*tmp;

	tmp = list;
	while (tmp)
	{
		if (ft_strncmp(content, tmp->key, ft_strichr(content, '=')) == 0)
		{
			if (tmp->content)
			{
				tmp->content = ft_strnndup(content, ft_strichr(content, '\0'),
						ft_strichr(content, '=') + 1);
			}
			else
				tmp->content = NULL;
		}
		tmp = tmp->next;
	}
}

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

char	*ft_pathuser(t_env *env, char *dir)
{
	t_list	*tmp;

	tmp = env->list;
	while (ft_strncmp(tmp->key, "HOME", 4) != 0)
		tmp = tmp->next;
	return (tmp->content);
}
