/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                                    +:+ +:+         +:+     */
/*   pipex.c                                            :+:      :+:    :+:   */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 22:17:43 by rcuminal          #+#    #+#             */
/*   Updated: 2022/01/13 23:35:14 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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
			perror("error execve ");
		}	
	}	
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

int	ft_missing(char **argv, t_val *val, char **env)
{
	if (argv[3][0] == '\0')
	{
		ft_pipexalone(val, env, val->cmd1, val->pid[0]);
		waitpid(val->pid[0], NULL, 0);
		ft_freealone(val->cmd1, val->cmd2, val);
		return (0);
	}
	else
	{
		ft_pipexalone(val, env, val->cmd2, val->pid[0]);
		waitpid(val->pid[0], NULL, 0);
		ft_freealone(val->cmd2, val->cmd1, val);
		return (0);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_val	*val;

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
		if (argv[3][0] == '\0' || argv[2][0] == '\0')
			return (ft_missing(argv, val, env));
		ft_pipex(val, env, val->fd2, val->pid[0]);
		ft_pipexalone(val, env, val->cmd2, val->pid[1]);
		waitpid(val->pid[1], NULL, 0);
		waitpid(val->pid[0], NULL, 0);
		ft_free(val);
	}
	else
		write(2, "Invalid number of arguments.\n", 29);
	return (0);
}
