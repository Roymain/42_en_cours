/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 03:08:31 by rcuminal          #+#    #+#             */
/*   Updated: 2022/04/14 05:23:55 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// deuxieme triche pr " vwerv v   ""vwe" voir nonackpossible executils2
int	ft_redir(t_list *lst, t_list *cmd)
{
	int	fd;
	t_list	*list;
	int	i;
	
	i = 0;
	list = lst;
	cmd->fdout = dup(1);
	while (list)
	{
		if (ft_strncmp(list->key, ">", ft_strlen(list->key)) == 0)
		{
			fd = open(ft_nobackpossiblee(list->content), O_WRONLY | O_CREAT | O_TRUNC, 0644);
			cmd->fdout = dup(1);
			dup2(fd, 1);	
		}
		else if (ft_strncmp(list->key, ">>", ft_strlen(list->key)) == 0)
		{
			fd = open(ft_nobackpossiblee(list->content), O_WRONLY | O_CREAT | O_APPEND, 0644);
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
			i = 1;
		
		list = list->next;
	}
	return (i);
}

void	ft_execcmdpipe(t_list *cmd, char **env, pid_t pid, int	*pfd)
{
	char	*path;
	char **split;
	
	split = ft_split(cmd->key, ' ', 0);
	ft_nobackpossible(split);
	if (cmd->key[0] != '\0')
	{
		path = ft_path(split[0], env, 0);
		if (ft_strncmp(cmd->key, path, ft_strlen(path)) == 0)
			return ((void)printf("command not found : %s", path));
	}
	else
		return ((void)printf("command not found"));
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
			execve(path, split , env);
			perror("error execve ");
			exit (EXIT_FAILURE);
		}
	}
}

void	ft_execcmdd(t_list *cmd, char **env, pid_t pid, int	*pfd, int save, int savee)
{
	char	*path;
	char **split;
	
	split = ft_split(cmd->key, ' ', 0);
	ft_nobackpossible(split);
	if (cmd->key[0] != '\0')
	{
		path = ft_path(split[0], env, 0);
		if (ft_strncmp(cmd->key, path, ft_strlen(path)) == 0)
			return ((void)printf("command not found : %s", path));
	}
	else
		return ((void)printf("command not found"));
	pid = fork();
	if (pid == -1)
		exit(printf("error fork"));
	if (pid)
		dup2(savee, 0);
	else
	{
		if (cmd->key[0] != '\0')
		{
			dup2(save, 1);
			if (cmd->redir)
				ft_redir(cmd->redir, cmd);
			execve(path, split , env);
			perror("error execve ");
			exit (EXIT_FAILURE);
		}
	}
}

void	ft_execcmd(t_list *cmd, char **env, pid_t pid, int	*pfd)
{
	char	*path;
	char **split;
	
	split = ft_split(cmd->key, ' ', 0);
	ft_nobackpossible(split);
	if (cmd->key[0] != '\0')
	{
		path = ft_path(split[0], env, 0);
		if (ft_strncmp(cmd->key, path, ft_strlen(path)) == 0)
			return ((void)printf("command not found : %s", path));
	}
	else
		return ((void)printf("command not found"));
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
			execve(path, split , env);
			perror("error execve ");
			exit (EXIT_FAILURE);
		}
	}
}



void	ft_exec(t_env *env, t_cmd *cmd)
{
	char	**ev;
	int		pfd[2];
	pid_t	pid;
	int		save;
	int		savee;
	
	ev = ft_trad(env);
	if (!env)
		return;
	save = dup(1);
	savee = dup(0);
	if (!cmd->listcmd->next)
	{
		ft_execcmd(cmd->listcmd, ev, pid, pfd);
	}
	else 
	{
		while (cmd->listcmd->next)
		{
			ft_execcmdpipe(cmd->listcmd, ev, pid, pfd);
			cmd->listcmd = cmd->listcmd->next;
		}
		ft_execcmdd(cmd->listcmd, ev, pid, pfd, save, savee);
		dup2(cmd->listcmd->fdout, 1);
	}
	while (waitpid(-1, NULL, 0) != -1)
		;
	ft_freetab(ev);
	return;
}

// void	ft_execcmdpipe(char *cmd, char **env, pid_t pid, int	*pfd)
// {
// 	char	*path;
// 	char **split;
	
// 	split = ft_split(cmd, ' ', 0);
// 	if (cmd[0] != '\0')
// 	{
// 		path = ft_path(split[0], env, 0);
// 		if (ft_strncmp(cmd, path, ft_strlen(path)) == 0)
// 			return ((void)printf("command not found : %s", path));
// 	}
// 	else
// 		return ((void)printf("command not found"));
// 	pipe(pfd);
// 	pid = fork();
// 	if (pid == -1)
// 		exit(printf("error fork"));
// 	if (pid)
// 		ft_pid(pfd);
// 	else
// 	{
// 		if (cmd[0] != '\0')
// 		{
// 			dup2(pfd[1], 1);
// 			execve(path, split , env);
// 			perror("error execve ");
// 		//	exit (EXIT_FAILURE);
// 		}
// 	}
// }

// void	ft_execcmd(char *cmd, char **env, pid_t pid, int	*pfd)
// {
// 	char	*path;
// 	char **split;
	
// 	split = ft_split(cmd, ' ', 0);
// 	if (cmd[0] != '\0')
// 	{
// 		path = ft_path(split[0], env, 0);
// 		if (ft_strncmp(cmd, path, ft_strlen(path)) == 0)
// 			return ((void)printf("command not found : %s", path));
// 	}
// 	else
// 		return ((void)printf("command not found"));
// 	pipe(pfd);
// 	pid = fork();
// 	if (pid == -1)
// 		exit(printf("error fork"));
// 	if (pid)
// 		;
// 	// 	ft_pid(pfd);
// 	else
// 	{
// 		if (cmd[0] != '\0')
// 		{

// 			execve(path, split , env);
// 			perror("error execve ");
// 		//	exit (EXIT_FAILURE);
// 		}
// 	}
// }