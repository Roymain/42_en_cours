/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 22:44:20 by rcuminal          #+#    #+#             */
/*   Updated: 2022/04/01 04:40:09 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_parse_redir(t_list	*list, t_track *tracker)
{
	int	i;
	int	j;
	char **cmd;
	char *help;
	t_list	*tmp;

	j = 0;
	i = 0;
	while (list)
	{
		cmd = ft_split(list->key, ' ', 0);
		while (cmd[i])
		{
			if (ft_strichr(cmd[i], '<') > -1)
			{
			//	ft_track(list->redir, &tracker);
				if (cmd[i][ft_strichr(cmd[i], '<') + 1] == '<')
				{
					if (!cmd[i][ft_strichr(cmd[i], '<') + 2])
					{
						tmp = ft_lstnew("<<", ft_strdup(cmd[i + 1]));
						ft_track(tmp, &tracker);
						ft_lstadd_back(&(list->redir), tmp);
						i++;
					}
					else
					{
						tmp = ft_lstnew("<<", ft_strnndup(cmd[i], ft_strlen(cmd[i]) - (ft_strichr(cmd[i], '<') - 2), ft_strichr(cmd[i], '<') + 2));
						ft_track(tmp, &tracker);
						ft_lstadd_back(&(list->redir), tmp);
					}
				}
				else
				{
					tmp = ft_lstnew("<", ft_strndup(cmd[i], ft_strichr(cmd[i], '<')));
					ft_lstadd_back(&(list->redir), tmp);
				}
				//ft_track(list->redir, &tracker);
			}
			else if (ft_strichr(cmd[i], '>') > -1)
			{
				//ft_track(list->redir, &tracker);
				if (cmd[i][ft_strichr(cmd[i], '>') + 1] == '>')
				{
					if (!cmd[i][ft_strichr(cmd[i], '>') + 2])
					{
						tmp = ft_lstnew(ft_strndup(cmd[i], (ft_strichr(cmd[i], '>') + 2)), cmd[i + 1]);
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
						help = ft_strndup(cmd[i], ft_strichr(cmd[i], '>') + 1);
						ft_track(help, &tracker);
						tmp = ft_lstnew(help, cmd[i + 1]);
						ft_lstadd_back(&(list->redir), tmp);
					//	free(help);
						i++;
					}
					else
					{
						help =ft_strndup(cmd[i], (ft_strichr(cmd[i], '>') + 1));
						ft_track(help, &tracker);
						tmp = ft_lstnew(help, cmd[i] + (ft_strichr(cmd[i], '>') + 1));
						ft_lstadd_back(&(list->redir), tmp);
					//	free(help);
					}
				}
				//ft_track(list->redir, &tracker);
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
				else if (ft_strichr(cmd[j], '-') > -1 && j != 0)
				{
					help = ft_strdup(list->key);
					free(list->key);
					list->key = ft_strjoin(list->key, cmd[j] + (ft_strichr(cmd[j], '-')));     //faire fonction aui marche proprement
					free(help);
				}
				else if (ft_strichr(cmd[j], '-') == -1 && ft_strichr(cmd[j], '>') == -1 && ft_strichr(cmd[j], '<') == -1 && j != 0)
				{
					help = ft_strdup(list->key);
					free(list->key);
					list->key = ft_strjoin(help, cmd[j]);     //faire fonction aui marche proprement
					free(help);
				}
				else if (ft_strichr(cmd[j], '>') > -1)
				{
					if (!cmd[j][ft_strichr(cmd[j], '>') + 1])
						j++;
					// else
					// {
					// 	help = ft_strdup(list->key);
					// 	free(list->key);
					// 	list->key = ft_strjoin(help, cmd[j] + (ft_strichr(cmd[j], '>') - 1));
					// 	free(help);
						
					// }
				}
				else if (ft_strichr(cmd[j], '<') > -1)
				{
					if (!cmd[j][ft_strichr(cmd[j], '<') + 2])
						j++;
					else
					{
						help = ft_strdup(list->key);
						free(list->key);
						list->key = ft_strjoin(help, cmd[j] + (ft_strichr(cmd[j], '<') - 1));
						free(help);
						
					}
				}
				
				j++;
			}
		}
		ft_track(list, &tracker);
		list = list->next;
		j = 0;
		i = 0;
		ft_freetab(cmd);
		ft_track(list, &tracker);
	}
	return ;
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

void	ft_parsenv(t_list **list, char **ev, t_track **t)
{
	int		i;
	t_list	*tmp;
	char	*content;
	char	*key;

	i = 0;
	while (ev[i])
	{
		key = ft_track(ft_strndup(ev[i], ft_strichr(ev[i], '=')), t);
		content = ft_track(ft_strnndup(ev[i], ft_strichr(ev[i], '\0'),
					ft_strichr(ev[i], '=') + 1), t);
		tmp = ft_lstnew(key, content);
		ft_track(tmp, t);
		ft_lstadd_back(list, tmp);
		i++;
	}
	ft_track(list, t);
	return ;
}

int	parsingline(char *line, t_cmd	*cmd, t_track *track)
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
	ft_track(cmd->listcmd, &track);
	ft_parse_redir(cmd->listcmd, track);
	return (0);
}

int	main(int argc, char **argv, char **ev)
{
	t_env	*env;
	t_cmd	*cmd;
	t_track	*trackenv;
	t_track	*trackcmd;
	char	*line;

	trackenv = ft_memalloc(sizeof(t_track));
	env = ft_track(ft_memalloc(sizeof(t_env)), &(trackenv));
	ft_parsenv(&env->list, ev, &(trackenv));
	line = readline("minishell ~ ");
	while (line && ft_strncmp(line, "exit", ft_strlen("exit")))
	{                                                                    //renvoie pointeur vers le repertoire (NULL (0x0) si ca echoue)
		trackcmd = ft_memalloc(sizeof(t_track));
		cmd = ft_track(ft_memalloc(sizeof(t_cmd)), &(trackcmd));
		add_history(line);
		parsingline(line, cmd, trackcmd);
		// while (cmd->listcmd)
		// {
		// 	while (cmd->listcmd->redir)
		// 	{
		// 		if (cmd->listcmd->redir->key)
		// 			printf("%s \n", cmd->listcmd->redir->key);
		// 		if (cmd->listcmd->redir->content)
		// 			printf("%s \n", cmd->listcmd->redir->content);
		// 		cmd->listcmd->redir = cmd->listcmd->redir->next;
		// 	}
		// 	printf("->>%s .\n", cmd->listcmd->key);
		// 	cmd->listcmd = cmd->listcmd->next;
		// }
		ft_track_free_all(&trackcmd);
		free(line);
	//	ft_lstclear(&cmd->listcmd, (&free));
		line = readline("minishell ~ ");
	}
//	free(cmd->listcmd);
//	free(cmd);
	ft_track_free_all(&trackenv);
//	ft_track_free_all(&trackcmd);
	free(line);
	rl_clear_history();
	printf("exit\n");
	return (0);
}
