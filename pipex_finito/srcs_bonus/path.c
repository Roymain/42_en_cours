/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 03:06:58 by Romain            #+#    #+#             */
/*   Updated: 2022/01/19 03:07:49 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/pipex_bonus.h"

char	*ft_catpath(char	*cmd, char *dir)
{
	char	*str;
	int		len;

	len = ft_strlen(dir);
	str = (char *)malloc(sizeof(char) * (len + ft_strlen(cmd) + 2));
	if (!str)
		return (NULL);
	str = ft_memcpy(str, dir, len);
	str[len] = '/';
	len++;
	while (*cmd)
		str[len++] = *cmd++;
	str[len] = '\0';
	return (str);
}

char	*ft_path(char *cmd, char **env, t_val *val)
{
	int		i;
	char	*path;
	char	*dir;
	char	*tmp;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	if (!env)
		return (cmd);
	path = ft_strdup(env[i] + 5);
	tmp = path;
	while (path && ft_strichr(path, ':') > -1)
	{
		dir = ft_strndup(path, ft_strichr(path, ':'));
		val->bin = ft_catpath(cmd, dir);
		free (dir);
		if (access(val->bin, F_OK) == 0)
			return (val->bin);
		free (val->bin);
		path += ft_strichr(path, ':') + 1;
	}
	free(tmp);
	return (cmd);
}

void	ft_waitallpid(t_list *lst)
{
	while (lst)
	{
		waitpid(lst->pid, NULL, 0);
		lst = lst->next;
	}
}

void	ft_redir(t_val *val)
{
	dup2(val->fd1, 0);
	dup2(val->fd2, 1);
}
