/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 03:08:31 by rcuminal          #+#    #+#             */
/*   Updated: 2022/05/20 05:22:11 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_scotchredir(t_list *cmd, char *path, char **split, char **ev)
{
	if (cmd->redir)
		ft_redir(cmd->redir, cmd);
	execve(path, split, ev);
	perror("minishell");
}

void	ft_scotchsign(t_cmd *cmd, pid_t pid)
{
	waitpid(pid, &cmd->status, 0);
	if (WIFEXITED(cmd->status))
		cmd->dernierfork = WEXITSTATUS(cmd->status);
	else
		cmd->dernierfork = 1;
}

void	ft_redir(t_list *lst, t_list *cmd)
{
	int		fd;
	t_list	*list;

	list = lst;
	cmd->fdout = dup(1);
	while (list)
	{
		if (ft_strncmp(list->key, ">", ft_strlen(list->key)) == 0)
		{
			fd = open(ft_nobackpossiblee(list->content),
					O_WRONLY | O_CREAT | O_TRUNC, 0644);
			cmd->fdout = dup(1);
			dup2(fd, 1);
		}
		else if (ft_strncmp(list->key, ">>", ft_strlen(list->key)) == 0)
		{
			fd = open(ft_nobackpossiblee(list->content),
					O_WRONLY | O_CREAT | O_APPEND, 0644);
			cmd->fdout = dup(1);
			dup2(fd, 1);
		}
		else if (ft_strncmp(list->key, "<", ft_strlen(list->key)) == 0)
		{
			fd = open(ft_nobackpossiblee(list->content), O_WRONLY, 0644);
			cmd->fdin = dup(0);
			dup2(fd, 0);
		}
		else if (ft_strncmp(list->key, "<<", ft_strlen(list->key)) == 0)
		{
			fd = open(list->content, O_RDONLY, 0644);
			dup2(fd, 0);
		}
		list = list->next;
	}
}

void	ft_execcmdpipe(t_list *cmd, char **ev, int	*pfd, t_env *ennv)
{
	char	*path;
	char	**split;
	pid_t	p;

	if (ft_isitbuiltin(cmd->key) == 1)
		return (ft_execbuiltinpipe(cmd, pfd, ennv));
	split = ft_split(cmd->key, ' ', 0);
	ft_nobackpossible(split);
	path = ft_path(split[0], ev, 0);
	if (ft_strncmp(cmd->key, path, ft_strlen(path)) == 0
		&& !(cmd->key[0] == '/' || cmd->key[0] == '.'))
		return ((void)printf("command not found : %s\n", path));
	pipe(pfd);
	p = fork();
	if (p == -1)
		return (perror("error fork"));
	if (p)
	{
		dup2(pfd[0], 0);
		close(pfd[1]);
		close(pfd[0]);
	}
	else
	{
		dup2(pfd[1], 1);
		close(pfd[0]);
		close(pfd[1]);
		if (cmd->key[0] != '\0')
			ft_scotchredir(cmd, path, split, ev);
		exit (EXIT_FAILURE);
	}
}

void	ft_execcmdd(t_cmd *cmd, char **env, int	*pfd, t_env *ennv)
{
	char	*path;
	char	**split;
	pid_t	pid;

	if (ft_isitbuiltin(cmd->listcmd->key) == 1)
		return (ft_execbuiltinn(cmd->listcmd, pfd, cmd, ennv));
	split = ft_split(cmd->listcmd->key, ' ', 0);
	ft_nobackpossible(split);
	if (cmd->listcmd->key[0] != '\0')
	{
		path = ft_path(split[0], env, 0);
		if (ft_strncmp(cmd->listcmd->key, path, ft_strlen(path)) == 0
			&& !(cmd->listcmd->key[0] == '/' || cmd->listcmd->key[0] == '.'))
			return ((void)printf("command not found : %s\n", path));
	}
	else
		return ((void)printf("command not found\n"));
	pid = fork();
	if (pid == -1)
		return (perror("error fork"));
	if (pid)
	{
		dup2(cmd->fdin, 0);
		ft_scotchsign(cmd, pid);
	}
	else
	{
		if (cmd->listcmd->key[0] != '\0')
		{
			dup2(cmd->fdout, 1);
			ft_scotchredir(cmd->listcmd, path, split, env);
			perror("minishell");
		}
		exit (EXIT_FAILURE);
	}
}

void	ft_execcmd(t_cmd *cmd, char **env, int	*pfd, t_env *ennv)
{
	char	*path;
	char	**split;
	pid_t	pid;

	if (ft_isitbuiltin(cmd->listcmd->key) == 1)
		return (ft_execbuiltin(cmd->listcmd, pid, pfd, ennv));
	split = ft_split(cmd->listcmd->key, ' ', 0);
	ft_nobackpossible(split);
	path = ft_path(split[0], env, 0);
	if (ft_strncmp(cmd->listcmd->key, path, ft_strlen(path)) == 0
		&& !(cmd->listcmd->key[0] == '/' || cmd->listcmd->key[0] == '.'))
		return ((void)printf("command not found : %s\n", path));
	pid = fork();
	if (pid == -1)
		return (perror("error fork"));
	if (pid)
		ft_scotchsign(cmd, pid);
	else
	{
		if (cmd->listcmd->key[0] != '\0')
			ft_scotchredir(cmd->listcmd, path, split, env);
		exit (EXIT_FAILURE);
	}
}

void	ft_exec(t_env *env, t_cmd *cmd, t_list *tmp)
{
	char	**ev;
	int		pfd[2];

	ev = ft_trad(env);
	tmp = cmd->listcmd;
	if (ft_checkifredir(&cmd->listcmd) != 0)
		ft_prepheredoc(&cmd->listcmd, cmd);
	if (!cmd->listcmd->next)
		ft_execcmd(cmd, ev, pfd, env);
	else
	{
		while (cmd->listcmd->next)
		{
			ft_execcmdpipe(cmd->listcmd, ev, pfd, env);
			cmd->listcmd = cmd->listcmd->next;
		}
		ft_execcmdd(cmd, ev, pfd, env);
		dup2(cmd->listcmd->fdout, 1);
	}
	while (waitpid(-1, NULL, 0) != -1)
		;
	cmd->listcmd = tmp;
	if (ft_checkifredir(&cmd->listcmd) != 0)
		ft_unlink(&cmd->listcmd);
	ft_freetab(ev);
}
