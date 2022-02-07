/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 21:22:50 by rcuminal          #+#    #+#             */
/*   Updated: 2022/01/24 20:36:12 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/pipex_bonus.h"

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

int	ft_prepare(t_val **val, char **argv, int argc)
{
	if (ft_checkarg(argv, argc) == 1)
		exit(write(2, "pipex: parse error near `|'\n", 29));
	(*val) = ft_memalloc(sizeof(t_val));
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		(*val)->fn = ft_here_doc((*val), argv, argc);
		(*val)->fd1 = open(".here_doc", O_RDONLY);
		return (3);
	}
	else
	{
		(*val)->fd1 = open(argv[1], O_RDONLY);
		(*val)->fd2 = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	if (((*val)->fd1 < 0)
		|| (*val)->fd2 < 0)
	{
		perror("file doesnt exist ");
		free(*val);
		exit (EXIT_FAILURE);
	}
	return (2);
}

int	main(int argc, char **argv, char **env)
{
	t_val		*val;
	t_list		*tmp;
	int			i;

	i = ft_prepare(&val, argv, argc);
	ft_parsargv(argv, &val->list, argc, i);
	tmp = val->list;
	ft_redir(val);
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		if (ft_preheredoc(val, argv, env, i) == 0)
			return (0);
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
