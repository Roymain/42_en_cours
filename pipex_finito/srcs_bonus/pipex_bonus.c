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

char	*ft_here_doc(t_val *val, char **argv, int argc)
{
	char	*fn;
	char	*line;

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

void	ft_freefn(char *fn)
{
	unlink(fn);
	free(fn);
}

void	ft_pipexalone(t_val *val, char **env, char **cmd, pid_t pid)
{
	pipe(val->pfd);
	pid = fork();
	if (pid)
	{
		close(val->pfd[1]);
		dup2(val->pfd[0], 0);
	}
	else
	{
		close(val->pfd[0]);
		dup2(val->fd2, 1);
		val->path = ft_path(cmd[0], env, val);
		execve(val->path, cmd, NULL);
		perror("error execve ");
	}	
}

void	ft_pipex(t_val *val, char **env, int fd, pid_t pid)
{
	pipe(val->pfd);
	pid = fork();
	if (pid)
	{
		close(val->pfd[1]);
		dup2(val->pfd[0], 0);
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
			perror("error execve ");
		}	
	}	
}

void	ft_waitallpid(t_list *lst)
{
	while (lst)
	{
		waitpid(lst->pid, NULL, 0);
		lst = lst->next;
	}
}

int	main(int argc, char **argv, char **env)
{
	t_val		*val;
	t_list		*tmp;
	int			i;
	char		*fn;
	

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
	ft_parsargv(argv, &val->list, argc, i);
	tmp = val->list;
	dup2(val->fd1, 0);
	dup2(val->fd2, 1);
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
	{	
		ft_freefn(fn);
		if (!val->list->next)
		{
			ft_pipexalone(val, env, val->list->cmd, val->list->pid);
			waitpid(val->list->pid, NULL, 0);
			ft_lstclear(&tmp, &free);
			free(val);
			return (0);
		}
	}
	while (val->list->next && argv[i + 1][0] != '\0')
	{
		ft_pipex(val, env, val->fd1, val->list->pid);
		val->list = val->list->next;
		i++;
	}
	ft_pipexalone(val, env, val->list->cmd, val->list->pid);
	ft_waitallpid(tmp);
	ft_lstclear(&tmp, &free);
	free(val);
	return (0);
}






					///// MURAILLE /////


// 	ft_pipex(val, env, val->fd1);
// 	val->list = val->list->next;
// 	while (val->list->next && argv[i + 2][0] != '\0')
// 	{
// 		ft_pipex(val, env, val->fd1);
// 		val->list = val->list->next;
// 		i++;
// 	}
// 	val->path = ft_path(val->list->cmd[0], env, val);
// 	execve(val->path, val->list->cmd, NULL);
// 	val->list = tmp;
// 	// while (val->list->next)
// 	// {
// 	// 	if (val->list->cmd[0] != 0)
// 	// 		ft_freetabb(val);
// 	// 	// if (val->list->cmd[0][0] != '\0')
// 	// 	// 	free(val->list->cmd[0]);
// 	// 	// free(val->list->cmd[1]);
// 	// 	// free(val->list->cmd[1]);
// 	// 	val->list = val->list->next;
// 	// }
// 	dprintf(2, "prout");
// //	 ft_lstclear(&tmp, &(free));
// //	 free(val->path);
// //	 free(val);
// 	// while (val->list)
// 	// {
// 	// 	ft_freetab(val->list->cmd);
// 	// 	val->list = val->list->next;
// 	// }
// //	dprintf(2, "%s", val->pid);
// 	perror("error execve ");
// 	return (0);
// }

	// if (ft_strncmp(val->list->cmd[0], "sleep", 6) == 0)
	// {
	// 	val->sleep += 1;
	// 	return ;
	// }





// void	ft_pipex(t_val *val, char **env, int fd)
// {
// 	pipe(val->pfd);
// 	val->pid = fork();
// 	if (val->pid)
// 	{
// 		close(val->pfd[1]);
// 		dup2(val->pfd[0], 0);
// 		waitpid(val->pid, NULL, 0);
// 	}
// 	else
// 	{
// 		close(val->pfd[0]);
// 		dup2(val->pfd[1], 1);
// 		if (fd == 1)
// 			exit(1);
// 		else
// 		{
// 			val->path = ft_path(val->list->cmd[0], env, val);
// 			execve(val->path, val->list->cmd, NULL);
// 			perror("error execve ");
// 		}	
// 	}
// }