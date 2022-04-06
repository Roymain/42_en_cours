/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built-in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 22:41:06 by rcuminal          #+#    #+#             */
/*   Updated: 2022/04/06 02:24:27 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	builtin_export(t_env *env, char *export)
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

void	builtin_env(t_env *env)
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

void	builtin_cd(t_env *env, char *dir, char *path)							//naze        utilse get env mais je vois pas encorem comment se deplacer
{
	t_list	*tmp;
	char	*old;

	tmp = env->list;
	old = ft_strdup(getcwd(path, 4096));
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
	}
	else
		write (2, "innaccessible \n", 14);
	return ;
}

void	builtin_pwd(char *path)							//ajouter fd?
{
	printf("=>%s \n", getcwd(path, 4096));
}

void	builtin_unset(t_env *env, char *key)
{
	t_list *tmp;
	
	tmp = env->list;
	while (ft_strncmp(tmp->next->key, key, ft_strlen(key)))
		tmp = tmp->next;
	dprintf(1, "KEY = %s\n", tmp->key); 
	tmp = tmp->next->next;
}

//void	builtin_echo