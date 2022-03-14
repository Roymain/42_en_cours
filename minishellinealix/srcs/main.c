/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 22:44:20 by rcuminal          #+#    #+#             */
/*   Updated: 2022/03/14 20:37:15 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_parse_redir(t_list	*tmp)
{
	
	
	return;
}

void	ft_printoneenv(t_env *env, char *var)
{
	while (ft_strncmp(env->list->key, var, 7) != 0)
	{
		env->list = env->list->next;
	}
	printf("%s", env->list->content);
}

int	ft_compare(char *prev, char *next)
{
	int	i;

	i = 0;
	while (prev[i] && next[i])
	{
		if (prev[i] < next[i])
			return (1);
		if (prev[i] > next[i])
			return (-1);
		i++;
	}
	if (!prev[i])
		return (1);
	return (-1);
}

int	ft_sorted(t_list *list)
{
	while (list->next)
	{
		if (ft_compare(list->key, list->next->key) == -1)
			return (0);
		list = list->next;
	}
	return (1);
}

void	ft_showexport(t_env *env)
{
	t_list	*tmp;
	t_list	*tmp2;
	int	i;

	i = 0;
	tmp = env->list;
	tmp2 = tmp;
	while (i++ < 10)
	{
		while (tmp)
		{
			if (ft_compare(tmp->key, tmp->next->key) == -1)
			{
				tmp->next = tmp2;
				tmp = tmp->next;
			}
		}
	}
	while (tmp2)
	{
		dprintf(2, "%s   ", tmp2->key);
		dprintf(2, "%s", tmp2->content);
		dprintf(2, "\n");
		tmp2 = tmp2->next;
	}
	return ;
}

int	contentequal(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_export(t_env *env, char *export)
{
	t_list	*tmp;

	if (contentequal(export, '=') == 1)
	{
		tmp = ft_lstnew(ft_strndup(export, ft_strichr(export, '=')),
				ft_strnndup(export, ft_strichr(export, '\0'),
					ft_strichr(export, '=') + 1));
		ft_lstadd_back(&env->list, tmp);
	}
	else
	{
		tmp = ft_lstnew(ft_strndup(export, ft_strichr(export, '\0')),
				"\0");
		ft_lstadd_back(&env->list, tmp);
	}
	return ;
}

void	ft_showenv(t_env *env)
{
	t_list	*tmp;

	tmp = env->list;
	while (env->list)
	{
		if (env->list->content)
		{
			dprintf(2, "%s   ", env->list->key);
			dprintf(2, "%s", env->list->content);
			dprintf(2, "\n");
		}
		env->list = env->list->next;
	}
	env->list = tmp;
}

void	ft_parsenv(t_list **list, char **ev)
{
	int		i;
	t_list	*tmp;

	i = 0;
	while (ev[i])
	{
		tmp = ft_lstnew(ft_strndup(ev[i], ft_strichr(ev[i], '=')),
				ft_strnndup(ev[i], ft_strichr(ev[i], '\0'),
					ft_strichr(ev[i], '=') + 1));
		ft_lstadd_back(list, tmp);
		i++;
	}
	return ;
}

void	ft_builtin(char *line, t_env	*env)
{
	char	*export;
	int		i;
	int		len;
	char	path[4096];

	i = 0;
	len = ft_strlen(line);
	if (!ft_strncmp(line, "env", len))
		ft_showenv(env);
	if (!ft_strncmp(line, "export", len))
		ft_showexport(env);
	if (!ft_strncmp(line, "export ", 7))
	{
		i = 7;
		while (i <= len && line[i] != ' ' && line[i])
			i++;
		export = ft_strndup(line + 7, i - 7);
		ft_export(env, export);
	}
	if (!ft_strncmp(line, "unset ", 6))
	{
		i = 6;
		while (i <= len && line[i] != ' ' && line[i])
			i++;
		export = ft_strndup(line + 6, i - 6);
		builtin_unset(env, export);
	}
	if (!ft_strncmp(line, "pwd", 4))
		builtin_pwd(path);
	if (!ft_strncmp(line, "cd", 3))
		builtin_cd(env, "/", path);
	if (!ft_strncmp(line, "cd ", 3))
	{
		i = 3;
		while (i <= len && line[i] != ' ' && line[i])
			i++;
		export = ft_strndup(line + 3, i - 3);
		builtin_cd(env, export, path);
	}
}

int	parsingline(char *line, t_cmd	*cmd)
{
	t_list	*tmp;
	size_t	i;
	size_t	start;
	char	quote;

	i = 0;
	start = 0;
	quote = 0;
	while (line[i])
	{
		if (quote == 0 && line[i + 1] != '\0' && (line[i] == '"' || line[i] == '\''))
			quote = line[i];
		else if (line[i + 1] != '\0' && line[i] == quote)
			quote = 0;
		else if ((!quote && line[i] == '|') || line[i + 1] == '\0')
		{
			if (line[i + 1] == '\0')
				i++;
			tmp = ft_lstnew(ft_strndup(line + start, (i - start)), "0");
			ft_lstadd_back(&(cmd->listcmd), tmp);
			ft_parse_redir(tmp);
			start = i + 1;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv, char **ev)
{
	t_env	*env;
	t_cmd	*cmd;
	t_track	*tracker;
	char	*line;

	tracker = ft_memalloc(sizeof(t_track));
	cmd = ft_track(ft_memalloc(sizeof(t_cmd)), &tracker);
	env = ft_track(ft_memalloc(sizeof(t_env)), &tracker);
	ft_parsenv(&env->list, ev);
	line = readline("minishell ~ ");
	while (line && ft_strncmp(line, "exit", ft_strlen(line)))
	{
		ft_builtin(line, env);			//renvoie pointeur vers le repertoire (NULL (0x0) si ca echoue)
		parsingline(line, cmd);
		add_history(line);
		while (cmd->listcmd)
		{
			printf("%s \n", cmd->listcmd->key);
			cmd->listcmd = cmd->listcmd->next;
		}
		free(line);
		line = readline("minishell ~ ");
	}
	ft_track_free_all(&tracker);
	printf("exit\n");
	return (0);
}
