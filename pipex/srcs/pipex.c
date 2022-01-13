/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 22:17:43 by rcuminal          #+#    #+#             */
/*   Updated: 2022/01/13 06:43:06 by rcuminal         ###   ########.fr       */
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

void	ft_free(t_val *val)
{
	ft_freetab(val->cmd1);
	ft_freetab(val->cmd2);
	free(val);
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
			val->path = ft_path(val->cmd1[0], env, val);
			execve(val->path, val->cmd1, NULL);
		//	dprintf(2, "prout");
			perror("error execve ");
		}	
	}	
}

int	main(int argc, char **argv, char **env)
{
	t_val	*val;

	if (argv[2][0] == '\0')
		return (write(2, "pipex: parse error near `|'\n", 29));
	if (argc == 5)
	{
		val = ft_memalloc(sizeof(t_val));
		val->fd1 = open(argv[1], O_RDONLY);
		val->fd2 = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (val->fd1 < 0 || val->fd2 < 0)
			return (write(2, "file doesnt exist", 18));
		val->cmd1 = ft_split(argv[2], ' ', 0);
		val->cmd2 = ft_split(argv[3], ' ', 0);
		 dup2(val->fd1, 0);
		 dup2(val->fd2, 1);
		if (argv[3][0] == '\0')
		{
			val->path = ft_path(val->cmd1[0], env, val);
			execve(val->path, val->cmd1, NULL);
			perror("error execve ");
			exit (0);
		}
		ft_pipex(val, env, val->fd2, val->pid[0]);
		pipe(val->pfd);
		val->pid[1] = fork();
		if (val->pid[1])
		{
			close(val->pfd[1]);
			dup2(val->pfd[0], 0);
		//	waitpid(val->pid[1], NULL, 0);
		}
		else
		{
			close(val->pfd[0]);
			dup2(val->fd2, 1);
			{
				val->path = ft_path(val->cmd2[0], env, val);
				execve(val->path, val->cmd2, NULL);
				ft_free(val);
				perror("error execve ");
			}	
		}
		waitpid(val->pid[1], NULL, 0);
		waitpid(val->pid[0], NULL, 0);
	
	}
	else
		write(2, "Invalid number of arguments.\n", 29);
	return (0);
}

//					AVANT

// void	ft_pipex(t_val *val, char **env)
// {
// 	int	status;

// 	val->pid1 = fork();
// 	if (val->pid1 < 0)
// 		return (perror("erorr"));
// 	if (val->pid1 == 0)
// 	{
// 		val->path = ft_path(val->cmd1[0], env, val);
// 		close(val->pfd[0]);
// 		dup2(val->pfd[1], 1);
// 		close(val->pfd[1]);
// 		//dup2(val->fd1, 0);
// 		execve(val->path, val->cmd1, NULL);
// 		perror("erorr execve ");
// 	}
// 	val->pid2 = fork();
// 	if (val->pid2 < 0)
// 		return (perror("error fork "));
// 	wait(&status);
// 	if (val->pid2 == 0)
// 	{
// 		val->path = ft_path(val->cmd2[0], env, val);
// 		close(val->pfd[1]);
// 		dup2(val->pfd[0], 0);
// 		close(val->pfd[0]);
// 		dup2(val->fd2, 1);
// 		execve(val->path, val->cmd2, NULL);
// 		perror("erorr execve ");
// 	}
// }

// int	main(int argc, char **argv, char **env)
// {
// 	t_val	*val;

// 	val = ft_memalloc(sizeof(t_val));
// 	if (argc == 5)
// 	{
// 		if (pipe(val->pfd) == -1)
// 			return (-1);
// 		if (val->pid1 < 0)
// 			return (-1);
// 		val->fd1 = open(argv[1], O_RDONLY);
// 		val->fd2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 		if (val->fd1 < 0 && val->fd2 < 0)
// 			return (-1);
// 		val->cmd1 = ft_split(argv[2], ' ');
// 		val->cmd2 = ft_split(argv[3], ' ');
// 		ft_pipex(val, env);
// 	}
// 	else
// 		write(2, "invalid number of arguments.\n", 29);
// 	ft_free(val);
// 	return (0);
// }
