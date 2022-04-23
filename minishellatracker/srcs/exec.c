/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 03:08:31 by rcuminal          #+#    #+#             */
/*   Updated: 2022/04/23 00:22:35 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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

int	ft_usebuiltin(char *str, t_env *env)
{
//	printf("%s", str);
	if (ft_strncmp(str, "unset ", 5) == 0)
		builtin_unset(env, str + 6);
	if (ft_strncmp(str, "export ", 7) == 0)
		builtin_export(env, str + 7);
	// if (ft_strncmp(str, "export", 7) == 0)
	// 	builtin_export trie (env, str);
	if (ft_strncmp(str, "cd ", 3) == 0)
		builtin_cd(env, str + 3);
	if (ft_strncmp(str, "cd", ft_strlen(str)) == 0)
		builtin_cd(env, "/");
	if (ft_strncmp(str, "pwd", ft_strlen(str)) == 0)
		builtin_pwd();
	if (ft_strncmp(str, "env", ft_strlen(str)) == 0)
		builtin_env(env);
	return (1);
}

int	ft_isitbuiltin(char *str)
{
	if (ft_strncmp(str, "unset ", 6) == 0)
		return (1);
	if (ft_strncmp(str, "export", 6) == 0)
		return (1);
	// if (ft_strncmp(str, "export", 7) == 0)
	// 	builtin_export trie (env, str);
	if (ft_strncmp(str, "cd ", 4) == 0)
		return (1);
	if (ft_strncmp(str, "cd", 2) == 0)
		return (1);
	if (ft_strncmp(str, "pwd", ft_strlen(str)) == 0)
		return (1);
	if (ft_strncmp(str, "env", ft_strlen(str)) == 0)
		return (1);
//	printf("prout");	
	return (0);
}

void	ft_execbuiltin(t_list *cmd, pid_t pid, int	*pfd, t_env *env)
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

void	ft_execbuiltinpipe(t_list *cmd, pid_t pid, int	*pfd, t_env *ennv)
{
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
			exit (ft_usebuiltin(cmd->key, ennv));
		}
	}
}

void	ft_execbuiltinn(t_list *cmd, pid_t pid, int	*pfd, int save, int savee, t_env *ennv)
{
	pipe(pfd);
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
			exit (ft_usebuiltin(cmd->key, ennv));
		}
	}
}



void	ft_execcmdpipe(t_list *cmd, char **env, pid_t pid, int	*pfd, t_env *ennv)
{
	char	*path;
	char **split;
	
	if (ft_isitbuiltin(cmd->key) == 1)
		return (ft_execbuiltinpipe(cmd, pid, pfd, ennv));
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

void	ft_execcmdd(t_list *cmd, char **env, pid_t pid, int	*pfd, int save, int savee, t_env *ennv)
{
	char	*path;
	char **split;
	
	if (ft_isitbuiltin(cmd->key) == 1)
		return (ft_execbuiltinn(cmd, pid, pfd, save, savee, ennv));
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



void	ft_execcmd(t_list *cmd, char **env, pid_t pid, int	*pfd, t_env *ennv)
{
	char	*path;
	char **split;

	if (ft_isitbuiltin(cmd->key) == 1)
		return (ft_execbuiltin(cmd, pid, pfd, ennv));
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



int	ft_exec(t_env *env, t_cmd *cmd)
{
	char	**ev;
	int		pfd[2];
	pid_t	pid;
	int		save;
	int		savee;
	
	ev = ft_trad(env);
	if (!env)
		return (0);
	save = dup(1);
	savee = dup(0);
	if (!cmd->listcmd->next)
		ft_execcmd(cmd->listcmd, ev, pid, pfd, env);
	else 
	{
		while (cmd->listcmd->next)
		{
			ft_execcmdpipe(cmd->listcmd, ev, pid, pfd, env);
			cmd->listcmd = cmd->listcmd->next;
		}
		ft_execcmdd(cmd->listcmd, ev, pid, pfd, save, savee, env);
		dup2(cmd->listcmd->fdout, 1);
	}
	while (waitpid(-1, NULL, 0) != -1)
		;
	ft_freetab(ev);
	return (1);
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