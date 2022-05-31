/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 23:50:42 by rcuminal          #+#    #+#             */
/*   Updated: 2022/05/30 22:16:35 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_execbuiltin(t_list *cmd, pid_t pid, t_env *env)
{
	pid = fork();
	if (pid == -1)
		exit(printf("error fork"));
	if (pid)
		;
	else
	{
		if (cmd->key[0] != '\0')
		{
			if (cmd->redir)
				ft_redir(cmd->redir, cmd);
			ft_usebuiltin(cmd->key, env);
		}
	}
}

void	ft_execbuiltinpipe(t_list *cmd, int	*pfd, t_env *ennv)
{
	pid_t	pid;

	pipe(pfd);
	pid = fork();
	if (pid == -1)
		exit(printf("error fork"));
	if (pid)
	{
		close(pfd[1]);
		dup2(pfd[0], 0);
	}
	else
	{
		close(pfd[0]);
		dup2(pfd[1], 1);
		if (cmd->key[0] != '\0')
		{
			if (cmd->redir)
				ft_redir(cmd->redir, cmd);
			ft_usebuiltin(cmd->key, ennv);
			exit (1);
		}
	}
}

void	ft_execbuiltinn(t_list *cmd, int	*pfd, t_cmd *s, t_env *ennv)
{
	pid_t	pid;

	pipe(pfd);
	pid = fork();
	if (pid == -1)
		exit(printf("error fork"));
	if (pid)
		dup2(s->fdin, 0);
	else
	{
		if (cmd->key[0] != '\0')
		{
			dup2(s->fdout, 1);
			if (cmd->redir)
				ft_redir(cmd->redir, cmd);
			ft_usebuiltin(cmd->key, ennv);
			exit (1);
		}
	}
}
