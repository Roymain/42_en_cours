/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 22:44:20 by rcuminal          #+#    #+#             */
/*   Updated: 2022/03/31 02:30:04 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// int	ft_redirentry(char *str)
// {
// 	int	i;

// 	i = 0;
// 	if (ft_strichr(str, "<") < -1)
// 	{
// 		if (ft_strichr(str, "<") == 0 && (!str[1] || str[1] == "<" && !str[2]))
// 			return (-2);
// 		if (ft_strichr(str, "<") > 0 && !str[1])
// 	}
// }

int	ft_strposnonalpha(const char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (ft_isalpha(str[i]) == 0)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strrnndup(const char *src, int size)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc((sizeof(char) * size) + 1);
	if (str == NULL)
		return (0);
	while (i < size)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	free((void *)src);
	return (str);
}

void	ft_parse_redir(t_list	*list)
{
	int	i;
	int	j;
	char **cmd;
	t_list	*tmp;

	j = 0;
	i = 0;
	while (list)
	{
		list->redir = ft_memalloc(sizeof(t_list));
		cmd = ft_split(list->key, ' ', 0);
		while (cmd[i])
		{
			if (ft_strichr(cmd[i], '<') > -1)
			{
			//	list->redir = ft_memalloc(sizeof(t_list));
				if (cmd[i][ft_strichr(cmd[i], '<') + 1] == '<')
				{
					if (!cmd[i][ft_strichr(cmd[i], '<') + 2])
					{
						tmp = ft_lstnew("<<", ft_strdup(cmd[i + 1]));
						ft_lstadd_back(&(list->redir), tmp);
						i++;
					}
					else
					{
						tmp = ft_lstnew("<<", ft_strnndup(cmd[i], ft_strlen(cmd[i]) - (ft_strichr(cmd[i], '<') - 2), ft_strichr(cmd[i], '<') + 2));
						ft_lstadd_back(&(list->redir), tmp);
					}
				}
				else
				{
					tmp = ft_lstnew("<", ft_strndup(cmd[i], ft_strichr(cmd[i], '<')));
					ft_lstadd_back(&(list->redir), tmp);
				}
			}
			else if (ft_strichr(cmd[i], '>') > -1)
			{
			//	list->redir = ft_memalloc(sizeof(t_list));
				if (cmd[i][ft_strichr(cmd[i], '>') + 1] == '>')
				{
					if (!cmd[i][ft_strichr(cmd[i], '>') + 2])
					{
						tmp = ft_lstnew(ft_strndup(cmd[i], (ft_strichr(cmd[i], '>') + 2)), ft_strdup(cmd[i + 1]));
						ft_lstadd_back(&(list->redir), tmp);
						i++;
					}
					else
					{
						tmp = ft_lstnew(ft_strndup(cmd[i], (ft_strichr(cmd[i], '>') + 2)), ft_strnndup(cmd[i], ft_strlen(cmd[i]) - (ft_strichr(cmd[i], '>') - 2), ft_strichr(cmd[i], '>') + 2));
						ft_lstadd_back(&(list->redir), tmp);
					}
				}
				else
				{
					if (!cmd[i][ft_strichr(cmd[i], '>') + 1])
					{
						tmp = ft_lstnew(ft_strndup(cmd[i], ft_strichr(cmd[i], '>') + 1), ft_strdup(cmd[i + 1]));
						ft_lstadd_back(&(list->redir), tmp);
						i++;
					}
					else
					{
						tmp = ft_lstnew(ft_strndup(cmd[i], (ft_strichr(cmd[i], '>') + 1)), ft_strnndup(cmd[i], ft_strlen(cmd[i]) - (ft_strichr(cmd[i], '>') - 1), ft_strichr(cmd[i], '>') + 1));
						ft_lstadd_back(&(list->redir), tmp);
					}
				}
			}
			i++;
			while (cmd[j])
			{
				if (ft_strichr(cmd[j], '-') > -1 && j == 0)
				{
					free(list->key);		
					list->key = ft_strdup(cmd[j]);     //faire fonction aui marche proprement
				}
				else if (ft_strichr(cmd[j], '>') == -1 && j == 0)
				{
					free(list->key);
					list->key = ft_strdup(cmd[j]);
				}
				// if (ft_strichr(cmd[j], '>') > -1 && j == 0)
				// {
				// //	free(list->key);
				// 	list->key = ft_strndup(cmd[j], ft_strichr(cmd[j], '>'));
				// }
				else if (ft_strichr(cmd[j], '-') > -1 && j != 0)
				{
				//	free(list->key);
					list->key = ft_strjoin(list->key, ft_strnndup(cmd[j], ft_strlen(cmd[j]) - ft_strposnonalpha(cmd[j]), ft_strichr(cmd[j], '-')));     //faire fonction aui marche proprement
				}
				// if (ft_strichr(cmd[j], '>') != ft_strlen(cmd[j]) && j != 0)
				// 	list->key = ft_strjoin(list->key,ft_strdup(cmd[j]));

				else if (ft_strichr(cmd[j], '-') == -1 && ft_strichr(cmd[j], '>') == -1 && ft_strichr(cmd[j], '<') == -1 && j != 0)
				{
				//	free(list->key);
					list->key = ft_strjoin(list->key, cmd[j]);     //faire fonction aui marche proprement
				}
				else if (ft_strichr(cmd[j], '>') > -1)
					list->key = ft_strjoin(list->key, ft_strndup(cmd[j], ft_strichr(cmd[j], '>') - 1));
				else if (ft_strichr(cmd[j], '<') > -1)
				{
					list->key = ft_strjoin(list->key, ft_strndup(cmd[j], ft_strichr(cmd[j], '<') - 1));
				}
				j++;
			}
		}
		list = list->next;
		j = 0;
		i = 0;
	ft_freetab(cmd);
	}
	while (list)
		list = list->prev;
	return ;
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
	int		i;

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
			tmp = ft_lstnew(ft_strndup(line + start, (i - start)), "");
			ft_lstadd_back(&(cmd->listcmd), tmp);
			start = i + 1;
		}
		i++;
	}
	ft_parse_redir(cmd->listcmd);
	return (0);
}

int	main(int argc, char **argv, char **ev)
{
	t_env	*env;
	t_cmd	*cmd;
	t_track	*tracker;
	char	*line;

	cmd = ft_memalloc(sizeof(t_cmd));
	env = ft_memalloc(sizeof(t_env));
	ft_parsenv(&env->list, ev);
	line = readline("minishell ~ ");
	while (line && ft_strncmp(line, "exit", ft_strlen(line)))
	{
	//	ft_builtin(line, env);			//renvoie pointeur vers le repertoire (NULL (0x0) si ca echoue)
		add_history(line);
		parsingline(line, cmd);
		while (cmd->listcmd)
		{
			while (cmd->listcmd->redir)
			{
				if (cmd->listcmd->redir->key)
					printf("%s \n", cmd->listcmd->redir->key);
				if (cmd->listcmd->redir->content)
					printf("%s \n", cmd->listcmd->redir->content);
				cmd->listcmd->redir = cmd->listcmd->redir->next;
			}
			printf("->>%s .\n", cmd->listcmd->key);
			cmd->listcmd = cmd->listcmd->next;
		}
		free(line);
		// while (cmd->listcmd)
		// {
		// 	while (cmd->listcmd->redir)
		// 	{
		// 		cmd->listcmd->redir = cmd->listcmd->redir->next;
		// 	}
		// 	printf("+1");
		// 	cmd->listcmd = cmd->listcmd->next;
		// }
		// while (cmd->listcmd)
		// 	cmd->listcmd = cmd->listcmd->prev;
		
		ft_lstclear(&cmd->listcmd, (&free));
		line = readline("minishell ~ ");
	}
	ft_lstclear(&env->list, (&free));
	free(cmd->listcmd);
	free(cmd);
	free(env);
	free(line);
	// while (cmd->listcmd)
	// 	cmd->listcmd = cmd->listcmd->prev;
	// while (cmd->listcmd)
	// {
	// 	ft_lstclear(&cmd->listcmd->redir, (&free));
	// 	cmd->listcmd = cmd->listcmd->next;
	// }
	// while (cmd->listcmd)
	// 	cmd->listcmd = cmd->listcmd->prev;
	// ft_lstclear(&cmd->listcmd, (&free));
//	ft_track_free_all(&tracker);
//	free(line);
	rl_clear_history();
	
	printf("exit\n");
	return (0);
}
