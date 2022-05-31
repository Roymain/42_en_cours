/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <mathmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:38:34 by mathmart          #+#    #+#             */
/*   Updated: 2022/05/30 17:43:27 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_builtin.h"

static char	*ft_pathuser(t_env *env)
{
	t_list	*tmp;

	tmp = env->list;
	while (ft_strncmp(tmp->key, "HOME", 4) != 0)
		tmp = tmp->next;
	return (tmp->content);
}

void	builtin_cd(t_env *env, char *dir)
{
	t_list	*tmp;
	char	*old;
	char	path[4096];

	tmp = env->list;
	old = ft_strdup(getcwd(path, 4096));
	if (dir[0] == '/' && dir[1] == '\0')
		dir = ft_pathuser(env);
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
}
