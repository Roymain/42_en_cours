/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built-in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 22:41:06 by rcuminal          #+#    #+#             */
/*   Updated: 2022/05/12 23:40:53 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	builtin_export(t_env *env, char *export)
{
	t_list	*tmp;

	if (already_in(env->list, export) == 1)
		return (export_modif(env->list, export));
	if (contentequal(export, '=') == 1 && export[ft_strichr(export, '=') + 1])
	{
		tmp = ft_lstnew(ft_strndup(export, ft_strichr(export, '=')),
				ft_strnndup(export, ft_strichr(export, '\0'),
					ft_strichr(export, '=') + 1));
		ft_lstadd_back(&env->list, tmp);
	}
	else if (contentequal(export, '=') == 1
		&& !export[ft_strichr(export, '=') + 1])
	{
		tmp = ft_lstnew(ft_strndup(export, ft_strichr(export, '=')), " ");
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

void	builtin_env(t_env *env)
{
	t_list	*tmp;

	tmp = env->list;
	while (env->list)
	{
		if (env->list->content)
		{
			printf("%s=", env->list->key);
			printf("%s", env->list->content);
			printf("\n");
		}
		env->list = env->list->next;
	}
	env->list = tmp;
}

void	builtin_cd(t_env *env, char *dir)
{
	t_list	*tmp;
	char	*old;
	char	path[4096];

	tmp = env->list;
	old = ft_strdup(getcwd(path, 4096));
	if (dir[0] == '/' && dir[1] == '\0')
		dir = ft_pathuser(env, dir);
	if (chdir(dir) == 0)
	{
		while (ft_strncmp(env->list->key, "OLDPWD", 7) != 0)
			env->list = env->list->next;
		env->list->content = ft_strdup(old);
		env->list = tmp;
		while (ft_strncmp(env->list->key, "PWD", 3) != 0)
		{
			env->list = env->list->next;
		}
		env->list->content = ft_strdup(getcwd(path, 4096));
		env->list = tmp;
	}
	else
		printf("cd: %s: No such file or directory\n", dir);
	return ;
}

void	builtin_pwd(void)
{
	char	path[4096];

	printf("%s\n", getcwd(path, 4096));
}

void	builtin_unset(t_env *env, char *key)
{
	t_list	*tmp;

	tmp = env->list;
	while (tmp)
	{
		if (tmp->next)
		{
			if (ft_strncmp(tmp->next->key, key, ft_strlen(key)) == 0)
			{
				if (tmp->next->next)
					tmp->next = tmp->next->next;
				else
					tmp->next = NULL;
			}	
		}
		tmp = tmp->next;
	}
}
