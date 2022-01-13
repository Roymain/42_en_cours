/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 21:22:50 by rcuminal          #+#    #+#             */
/*   Updated: 2022/01/12 21:55:46 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/pipex_bonus.h"

void	ft_freetabb(t_val *val)
{
	int	i;

	i = 0;
	while (val->list->cmd[i])
	{
		free(val->list->cmd[i]);
		i++;
	}
	free(val->list->cmd);
}

void	ft_lstcleartab(t_list **lst)
{
	t_list	*next;

	while (*lst)
	{
		next = (*lst)->next;
		ft_freetab((*lst)->cmd);
		(*lst) = next;
	}
}

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

void	ft_pipex(t_val *val, char **env, int fd)
{
	pipe(val->pfd);
	val->pid = fork();
	if (val->pid)
	{
		close(val->pfd[1]);
		dup2(val->pfd[0], 0);
		waitpid(val->pid, NULL, 0);
	}
	else
	{
		close(val->pfd[0]);
		dup2(val->pfd[1], 1);
		if (fd == 1)
			exit(1);
		else
		{
			val->path = ft_path(val->list->cmd[0], env, val);
			execve(val->path, val->list->cmd, NULL);
		//	dprintf(2, "prout");
			perror("error execve ");
		}	
	}
}

char	*ft_here_doc(t_val *val, char **argv, int argc)
{
	char	*fn;
	char	*line;
	char	buffer;
	int		ret;

	fn = ft_strdup(".here_doc");
	val->fd1 = open(fn, O_RDONLY | O_WRONLY | O_CREAT | O_TRUNC, 0644);
	val->fd2 = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	while (1)
	{
		write(1, "here_doc> ", 11);
		line = get_next_line(0);
		line[ft_strlen(line) - 1] = '\0';
		if (ft_strncmp(argv[2], line, ft_strlen(line)) == 0)
		{
			free(line);
			return (fn);
		}
		line[ft_strlen(line)] = '\n';
		ft_putstr_fd(line, val->fd1);
		free (line);
	}
}

int	ft_checkarg(char **argv, int argc)
{
	int	i;

	i = 2;
	while (i < argc - 2)
	{
		if (argv[i][0] == '\0')
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_val	*val;
	int		i;
	char	*fn;
	int		status;
	t_list		*tmp;

	i = 2;
	if (ft_checkarg(argv, argc) == 1)
		return (write(2, "pipex: parse error near `|'\n", 29));
	val = ft_memalloc(sizeof(t_val));
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		fn = ft_here_doc(val, argv, argc);
		i = 3;
		val->fd1 = open(".here_doc", O_RDONLY);
	}
	else
	{
		val->fd1 = open(argv[1], O_RDONLY);
		val->fd2 = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	if ((val->fd1 < 0)
		|| val->fd2 < 0)
	{
		perror("file doesnt exist ");
		return (-1);
	}
	ft_parsargv(argv, &val->list, argc);
	tmp = val->list;
	dup2(val->fd1, 0);
	dup2(val->fd2, 1);
	unlink(fn);
	free(fn);
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		val->list = val->list->next;
		if (val->list->next->cmd[0] == '\0')
		{
			val->path = ft_path(val->list->cmd[0], env, val);
			execve(val->path, val->list->cmd, NULL);
		//	dprintf(2, "prout");
			perror("error execve ");
		}
	}
	ft_pipex(val, env, val->fd1);
	val->list = val->list->next;
	while (val->list->next && argv[i + 2][0] != '\0')
	{
		ft_pipex(val, env, val->fd1);
		val->list = val->list->next;
		i++;
	}
	val->path = ft_path(val->list->cmd[0], env, val);
	execve(val->path, val->list->cmd, NULL);
	val->list = tmp;
	// while (val->list->next)
	// {
	// 	if (val->list->cmd[0] != 0)
	// 		ft_freetabb(val);
	// 	// if (val->list->cmd[0][0] != '\0')
	// 	// 	free(val->list->cmd[0]);
	// 	// free(val->list->cmd[1]);
	// 	// free(val->list->cmd[1]);
	// 	val->list = val->list->next;
	// }
	dprintf(2, "prout");
	 ft_lstclear(&tmp, &(free));
//	 free(val->path);
	 free(val);
	// while (val->list)
	// {
	// 	ft_freetab(val->list->cmd);
	// 	val->list = val->list->next;
	// }
//	dprintf(2, "%s", val->pid);
	perror("error execve ");
	return (0);
}

	// if (ft_strncmp(val->list->cmd[0], "sleep", 6) == 0)
	// {
	// 	val->sleep += 1;
	// 	return ;
	// }