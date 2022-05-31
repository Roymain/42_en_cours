/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 03:08:31 by rcuminal          #+#    #+#             */
/*   Updated: 2022/05/31 05:12:46 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_scotchredir(t_list *cmd, char *path, char **split, char **ev)
{
	if (cmd->key[0] != '\0')
	{
		if (cmd->redir)
			ft_redir(cmd->redir, cmd);
		execve(path, split, ev);
		perror("minishell");
	}
}

void	ft_scotchsign(t_cmd *cmd, pid_t pid)
{
	waitpid(pid, &cmd->status, 0);
	if (WIFEXITED(cmd->status))
		cmd->dernierfork = WEXITSTATUS(cmd->status);
	else
		cmd->dernierfork = 1;
}

void	ft_closepfd(int *pfd)
{
	close(pfd[1]);
	close(pfd[0]);
}

int	ft_redirsimple(int fd, t_list *list, t_list *cmd)
{
	fd = open(ft_nobackpossiblee(list->content),
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	cmd->fdout = dup(1);
	dup2(fd, 1);
	return (fd);
}

int	ft_redirdouble(int fd, t_list *list, t_list *cmd)
{
	fd = open(ft_nobackpossiblee(list->content),
			O_WRONLY | O_CREAT | O_APPEND, 0644);
	cmd->fdout = dup(1);
	dup2(fd, 1);
	return (fd);
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
			fd = ft_redirsimple(fd, list, cmd);
		else if (ft_strncmp(list->key, ">>", ft_strlen(list->key)) == 0)
			fd = ft_redirdouble(fd, list, cmd);
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
	if (p && dup2(pfd[0], 0) != -1)
		ft_closepfd(pfd);
	else
	{
		dup2(pfd[1], 1);
		ft_closepfd(pfd);
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
	path = ft_path(split[0], env, 0);
	if (ft_strncmp(cmd->listcmd->key, path, ft_strlen(path)) == 0
		&& !(cmd->listcmd->key[0] == '/' || cmd->listcmd->key[0] == '.'))
		return ((void)printf("command not found : %s\n", path));
	pid = fork();
	if (pid == -1)
		return (perror("error fork"));
	if (pid && dup2(cmd->fdin, 0) != -1)
		ft_scotchsign(cmd, pid);
	else
	{
		if (cmd->listcmd->key[0] != '\0' && dup2(cmd->fdout, 1) != -1)
			ft_scotchredir(cmd->listcmd, path, split, env);
		exit (EXIT_FAILURE);
	}
}

void	ft_execcmd(t_cmd *cmd, char **env, t_env *ennv)
{
	char	*path;
	char	**split;
	pid_t	pid;

	pid = 0;
	if (ft_isitbuiltin(cmd->listcmd->key) == 1)
		return (ft_execbuiltin(cmd->listcmd, pid, ennv));
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

void	ft_exec(t_mini *mini, t_list *tmp)
{
	char	**ev;
	int		pfd[2];

	ev = ft_trad(mini->env);
	tmp = mini->cmd->listcmd;
	if (ft_checkifredir(&mini->cmd->listcmd) != 0)
		ft_prepheredoc(&mini->cmd->listcmd);
	if (mini->cmd->listcmd != NULL && !mini->cmd->listcmd->next)
		ft_execcmd(mini->cmd, ev, mini->env);
	if (mini->cmd->listcmd != NULL && mini->cmd->listcmd->next)
	{
		while (mini->cmd->listcmd->next)
		{
			ft_execcmdpipe(mini->cmd->listcmd, ev, pfd, mini->env);
			mini->cmd->listcmd = mini->cmd->listcmd->next;
		}
		ft_execcmdd(mini->cmd, ev, pfd, mini->env);
		dup2(mini->cmd->fdout, 1);
	}
	while (waitpid(-1, NULL, 0) != -1)
		;
	mini->cmd->listcmd = tmp;
	if (ft_checkifredir(&mini->cmd->listcmd) != 0)
		ft_unlink(&mini->cmd->listcmd);
	ft_freetab(ev);
}
