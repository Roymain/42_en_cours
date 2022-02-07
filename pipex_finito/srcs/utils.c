/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 23:29:11 by rcuminal          #+#    #+#             */
/*   Updated: 2022/01/14 01:47:51 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_catpath(char	*cmd, char *dir)
{
	char	*str;
	int		len;

	len = ft_strlen(dir);
	str = (char *)malloc(sizeof(char) * len + ft_strlen(cmd) + 2);
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

void	ft_freealone(char **good, char **wrong, t_val *val)
{
	if (good[0])
		ft_freetab(good);
	free(wrong);
	free(val);
}

void	ft_free(t_val *val)
{
	if (val->cmd1[0])
		ft_freetab(val->cmd1);
	if (val->cmd2[0])
		ft_freetab(val->cmd2);
	free(val);
}
