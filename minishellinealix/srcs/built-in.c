/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built-in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 22:41:06 by rcuminal          #+#    #+#             */
/*   Updated: 2022/03/16 05:26:09 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*ft_realloc(char *strr, int i, char *buffer)			//reutilise pas checké
{
	char	*temp;
	int		j;
	int		k;

	temp = NULL;
	k = 0;
	j = ft_strlen(strr);
	temp = ft_calloc (j + i + 2, 1);
	while (strr[k] != '\0')
	{
		temp[k] = strr[k];
		k++;
	}
	temp[k + i + 1] = '\0';
	while (i >= 0)
	{
		temp[k + i] = buffer[i];
		i--;
	}
	free (strr);
	strr = NULL;
	return (temp);
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