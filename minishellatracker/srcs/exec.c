/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 03:08:31 by rcuminal          #+#    #+#             */
/*   Updated: 2022/04/13 05:54:15 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// ft_pid(int	*pfd, char *bin)
void	ft_pid(int	*pfd)
{
	// close(pfd[1]);
	// dup2(pfd[0], 0);
	// free(bin);
	// bin = NULL;
	return ;
}

void	ft_pipexalone(char *cmd, char **env, pid_t pid, int	*pfd)
{
	char	*path;
	char **split;
	
	split = ft_split(cmd, ' ', 0);
	if (cmd[0] != '\0')
	{
		path = ft_path(split[0], env, 0);
		if (ft_strncmp(cmd, path, ft_strlen(path)) == 0)
			return ((void)printf("command not found : %s", path));
	}
	else
		return ((void)printf("command not found"));
	pipe(pfd);
	pid = fork();
	if (pid == -1)
		exit(printf("error fork"));
	if (pid)
		ft_pid(pfd);
	else
	{
		if (cmd[0] != '\0')
		{

			execve(path, split , env);
			perror("error execve ");
		}
	}
}

char	*ft_strjoinequal(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1)
				+ ft_strlen(s2) + 2));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i++] = '=';  
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_lstsize_env(t_list *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		if (lst->content)
			i++;
		lst = lst->next;
	}
	return (i);
}

char	**ft_trad(t_env *env)
{
	char **ev;
	t_list	*list;
	int	i;

	i = 0;
	ev = ft_memalloc(sizeof(char *) * (ft_lstsize_env(env->list) + 1));
	if (!ev)
		return (NULL);
	list = env->list;
	while (list)
	{
		if (list->content)
		{
			ev[i] = ft_strjoinequal(list->key, list->content);
			if (!ev[i])
			{
				while (i != 0)
					free(ev[--i]);
				free(ev);
				return (NULL);
			}
			i++;
		}
		list = list->next;
	}
	
	return (ev);
}

void	ft_exec(t_env *env, t_cmd *cmd)
{
	char	**ev;
	int		pfd[2];
	pid_t	pid;
	
	ev = ft_trad(env);
	if (!env)
		return;
//	while (cmd->listcmd)
//	{
		
	ft_pipexalone(cmd->listcmd->key, ev, pid, pfd);
		
//	}
	while (waitpid(-1, NULL, 0) != -1)
		;
	ft_freetab(ev);
	return;
}