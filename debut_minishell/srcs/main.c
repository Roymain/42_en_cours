/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 22:44:20 by rcuminal          #+#    #+#             */
/*   Updated: 2022/03/09 11:59:00 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"



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

void	ft_export(t_env *env, char *export)   //checker avant si le nom de la var est bien un char (ft_alphanum)
{
	t_list	*tmp;

	if (contentequal(export, '=') == 1)
	{
		tmp = ft_lstnew(ft_strndup(export, ft_strichr(export, '=')),
				ft_strnndup(export, ft_strichr(export, '\0'),
					ft_strichr(export, '=') + 1));
		ft_lstadd_back(&env->list, tmp);
	}
	else
	{
		tmp = ft_lstnew(ft_strndup(export, ft_strichr(export, '\0')),
				"\0");
		ft_lstadd_back(&env->list, tmp);
	}
	return ;
}

void	ft_showenv(t_env *env)
{
	t_list	*tmp;

	tmp = env->list;
	while (env->list)
	{
		if (env->list->content)
		{
			dprintf(2, "%s   ", env->list->key);
			dprintf(2, "%s", env->list->content);
			dprintf(2, "\n");
		}
		env->list = env->list->next;
	}
	env->list = tmp;
}

void	ft_parsenv(t_list **list, char **ev)
{
	int		i;
	t_list	*tmp;

	i = 0;
	while (ev[i])
	{
		tmp = ft_lstnew(ft_strndup(ev[i], ft_strichr(ev[i], '=')),
				ft_strnndup(ev[i], ft_strichr(ev[i], '\0'),
					ft_strichr(ev[i], '=') + 1));
		ft_lstadd_back(list, tmp);
		i++;
	}
	return ;
}

int	main(int argc, char **argv, char **ev)
{
	t_env	*env;
	t_track	*tracker;
	char	*line;
	char	path[4096];

	tracker = ft_memalloc(sizeof(t_track));
	env = ft_track(ft_memalloc(sizeof(t_env)), &tracker);
	ft_parsenv(&env->list, ev);
	line = readline("minishell ~ ");
	ft_export(env, "LOOL=888");
	while (line)
	{
		builtin_pwd(path);
//		ft_printoneenv(env, "OLDPWD");			//renvoie pointeur vers le repertoire (NULL (0x0) si ca echoue)
		free(line);
		line = readline("minishell ~ ");
	}
	ft_track_free_all(&tracker);
	printf("exit\n");
	return (0);
}