/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built-in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 22:41:06 by rcuminal          #+#    #+#             */
/*   Updated: 2022/04/23 05:00:17 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"



int already_in(t_list	*list, char *key)
{
	t_list	*tmp;

	tmp = list;
	while(tmp)
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
	printf("PROUT");
	while(tmp)
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

void	builtin_export(t_env *env, char *export)    /// AJOUTER CHECK si deja dedans
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
	else if (contentequal(export, '=') == 1 && !export[ft_strichr(export, '=') + 1])
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

char	*ft_pathuser(t_env *env, char *dir)
{
	t_list	*tmp;
	
	tmp = env->list;
	while (ft_strncmp(tmp->key, "HOME", 4) != 0)
		tmp = tmp->next;
	return(tmp->content);
}

void	builtin_cd(t_env *env, char *dir)							//naze        utilse get env mais je vois pas encorem comment se deplacer
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
		{
			env->list = env->list->next;
		}
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

void	builtin_pwd()							//ajouter fd?
{
	char	path[4096];
	
	printf("%s\n", getcwd(path, 4096));
}

void	builtin_unset(t_env *env, char *key)
{
	t_list *tmp;
	
	tmp = env->list;
	while (ft_strncmp(tmp->next->key, key, ft_strlen(key)) != 0)
		tmp = tmp->next;
	if (tmp->next->next)
		tmp->next = tmp->next->next;
	else
		tmp->next = NULL;
}

//void	builtin_echo