/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decote.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 00:47:03 by rcuminal          #+#    #+#             */
/*   Updated: 2022/04/01 00:49:53 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// void	ft_cleanlistkey(char *str, t_list **list)
// {
// 	int		i;
// 	char **cmd;
// 	t_list	*tmp;
	
// 	i = 0;
// 	cmd = ft_split(str, ' ', 0);
// 	tmp = list;
// 	while (cmd[i])
// 	{
// 		if ()
// 		i++;
// 	}
// }

// int	ft_redirentry(char *str)
// {
// 	int	i;

// 	i = 0;
// 	if (ft_strichr(str, "<") < -1)
// 	{
// 		if (ft_strichr(str, "<") == 0 && (!str[1] || str[1] == "<" && !str[2]))
// 			return (-2);
// 		if (ft_strichr(str, "<") > 0 && !str[1])
// 	}
// }

int	ft_strposnonalpha(const char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (ft_isalpha(str[i]) == 0)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strrnndup(const char *src, int size)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc((sizeof(char) * size) + 1);
	if (str == NULL)
		return (0);
	while (i < size)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_printoneenv(t_env *env, char *var)
{
	while (ft_strncmp(env->list->key, var, 7) != 0)
	{
		env->list = env->list->next;
	}
	printf("%s", env->list->content);
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

int	ft_sorted(t_list *list)
{
	while (list->next)
	{
		if (ft_compare(list->key, list->next->key) == -1)
			return (0);
		list = list->next;
	}
	return (1);
}