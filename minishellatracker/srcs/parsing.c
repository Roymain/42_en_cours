/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 02:27:25 by rcuminal          #+#    #+#             */
/*   Updated: 2022/04/06 05:55:35 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_simple(char *str, t_env *env, int *i, t_track *tracker)
{
	char	*tmp;
	int		j;
	int		count;

	count = 0;
	j = 0;
	tmp = ft_track(malloc((ft_strlen(str) - 1) * sizeof(char *)), &tracker);
	while (str[j] && count < 2)
	{
		if (str[j] == '\''  && count < 2)
		{
			count++;
			//if (count == 2)
				
		}
		else//{
			tmp[j] = str[j];//printf("%c", str[j]);printf("%c", tmp[j]);}
		j++;
	}
//	printf("str == %s\n", tmp);
	*i = j - 2;
	// while (str[j] != '\0')
	// {

	// 	tmp[j] = str[j + 1];
	// 	j++;
	// }
	return (tmp);
}

char	*ft_double(char *str, t_env *env, int *i)
{
	return (str);
}

void	ft_quotes(char *str, t_env *env, t_track *tracker)
{
	char *tmp;
	int		i;
	char	q;
//	int	count;

	q = 'q';
	i = 0;
//	count = 0;
	while(str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			q = str[i];
			if (q == '\'')
			{
				//printf("i = %d", i);
				str = ft_simple(str, env, &i, tracker);
			//	printf("i = %d", i);
				printf("str == %s\n", str);
			}
			// else
			// 	ft_double(str, env, &i);
		}
		i++;
	}
	return ;
}

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
		ft_track_tab((void *)cmd, &(tracker));
		while (cmd[i])
		{
			if (ft_strichr(cmd[i], '<') > -1)
			{
				if (cmd[i][ft_strichr(cmd[i], '<') + 1] == '<')
				{
					if (!cmd[i][ft_strichr(cmd[i], '<') + 2])
					{
						tmp = ft_lstnew("<<", ft_track(ft_strdup(cmd[i + 1]), &(tracker)));
						ft_track(tmp, &tracker);
						ft_lstadd_back(&(list->redir), tmp);
						i++;
					}
					else
					{
						tmp = ft_lstnew("<<", ft_track(ft_strnndup(cmd[i], ft_strlen(cmd[i]) - (ft_strichr(cmd[i], '<') - 2), ft_strichr(cmd[i], '<') + 2), &tracker));
						ft_track(tmp, &tracker);
						ft_lstadd_back(&(list->redir), tmp);
					}
				}
				else
				{
					tmp = ft_lstnew("<", cmd[i] + (ft_strichr(cmd[i], '<') + 1));
					ft_track(tmp, &(tracker));
					ft_lstadd_back(&(list->redir), tmp);
				}
			}
			else if (ft_strichr(cmd[i], '>') > -1)
			{
				if (cmd[i][ft_strichr(cmd[i], '>') + 1] == '>')
				{
					if (!cmd[i][ft_strichr(cmd[i], '>') + 2])
					{
						tmp = ft_lstnew(ft_track(ft_strndup(cmd[i], (ft_strichr(cmd[i], '>') + 2)), &(tracker)), cmd[i + 1]);
						ft_track(tmp, &(tracker));
						ft_lstadd_back(&(list->redir), tmp);
						i++;
					}
					else
					{
						tmp = ft_lstnew(ft_track(ft_strndup(cmd[i], (ft_strichr(cmd[i], '>') + 2)), &(tracker)), ft_track(ft_strnndup(cmd[i], ft_strlen(cmd[i]) - (ft_strichr(cmd[i], '>') - 2), ft_strichr(cmd[i], '>') + 2), &(tracker)));
						ft_track(tmp, &(tracker));
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
						ft_track(tmp, &tracker);
						ft_lstadd_back(&(list->redir), tmp);
						i++;
					}
					else
					{
						help =ft_strndup(cmd[i], (ft_strichr(cmd[i], '>') + 1));
						ft_track(help, &tracker);
						tmp = ft_lstnew(help, cmd[i] + (ft_strichr(cmd[i], '>') + 1));
						ft_track(tmp, &tracker);
						ft_lstadd_back(&(list->redir), tmp);
					}
				}
			}
			i++;
			while (cmd[j])
			{
				if (ft_strichr(cmd[j], '-') > -1 && j == 0)						
					list->key = cmd[j];     //faire fonction aui marche proprement				
				else if (ft_strichr(cmd[j], '>') == -1 && j == 0)
					list->key = cmd[j];
				else if (ft_strichr(cmd[j], '>') > -1 && j == 0)
				{
					if (!cmd[j][ft_strichr(cmd[j], '>') + 1])
						j++;
					else if (cmd[j][ft_strichr(cmd[j], '>') + 1] == '>' )
					{
						if (!cmd[j][ft_strichr(cmd[j], '>') + 2])
							j++;
					}
					list->key = ft_track(ft_strdup(""), &tracker);
				}
				else if (ft_strichr(cmd[j], '-') > -1 && j != 0)
					list->key = ft_track(ft_strjoin(list->key, cmd[j] + (ft_strichr(cmd[j], '-'))), &(tracker));     //faire fonction aui marche proprement
				else if (ft_strichr(cmd[j], '-') == -1 && ft_strichr(cmd[j], '>') == -1 && ft_strichr(cmd[j], '<') == -1 && j != 0)					
					list->key = ft_track(ft_strjoin(list->key, cmd[j]), &tracker);     //faire fonction aui marche proprement			
				else if (ft_strichr(cmd[j], '>') > -1)
				{
					if (!cmd[j][ft_strichr(cmd[j], '>') + 1])
						j++;
					else if (cmd[j][ft_strichr(cmd[j], '>') + 1] == '>' )
					{
						if (!cmd[j][ft_strichr(cmd[j], '>') + 2])
							j++;
					}
				}
				else if (ft_strichr(cmd[j], '<') > -1)
				{
					if (!cmd[j][ft_strichr(cmd[j], '<') + 2])
						j++;
					else			
						list->key = ft_track(ft_strjoin(list->key, cmd[j] + (ft_strichr(cmd[j], '<') - 1)), &tracker);													
				}
				j++;
			}
		}
		list = list->next;
		j = 0;
		i = 0;
	}
	return ;
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
	return ;
}

void	parsingline(char *line, t_cmd	*cmd, t_track *track, t_env *env)
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
			tmp = ft_lstnew(ft_track(ft_strndup(line + start, (i - start)), &(track)), "");
			ft_quotes(tmp->key, env, track);
			ft_track(tmp, &(track));
			ft_lstadd_back(&(cmd->listcmd), tmp);
			start = i + 1;
		}
		i++;
	}
	ft_parse_redir(cmd->listcmd, track);
	return ;
}
