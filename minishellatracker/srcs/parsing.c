/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 02:27:25 by rcuminal          #+#    #+#             */
/*   Updated: 2022/04/23 02:11:13 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_strrichr(const char *str, int to_find, int start)
{
	int	i;

	i = start;
	while (str[i])
	{
		if (str[i] == (char)to_find)
			return (i);
		i++;
	}
	if (str[i] == (char)to_find)
		return (i);
	return (-1);
}


char	*ft_strjoinnospace(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1)
				+ ft_strlen(s2) + 4));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_simple(char *str, t_env *env, int *i, t_track *tracker)
{
	char	*tmp;
	int		j;
	int		count;

	count = 0;
	j = 0;
	tmp = ft_track(malloc((ft_strlen(str) - 1) * sizeof(char)), &tracker);
	while (str[j] && j < *i)
	{
		tmp[j] = str[j];
		j++;
	}
	j++;
	while (str[j] && str[j] != '\'')
	{
		tmp[j - 1] = str[j];
		j++;
	}
	*i = j - 2;
	j++;
	while (str[j] != '\0')
	{
		tmp[j - 2] = str[j];
		j++;
	}
	tmp[j - 2] = '\0';
	return (tmp);
}

char	*ft_returncontent(char *arg, t_env *env)
{
	t_list	*tmp;


	tmp = env->list;
	while (ft_strncmp(tmp->key, arg + 1, ft_strlen(arg)) != 0)
		tmp = tmp->next;
	return (tmp->content);
}

char	*ft_joinarg(char *str, t_env *env, int *i, t_track *tracker, char *tmp)
{
	char *arg;
	int	j;
	int	save;
	
	j = *i;
	while (str[j] != '"')
		j++;
	arg = ft_track(malloc((j - *i + 3) * sizeof(char)), &tracker);
	j = 0;
	while (str[*i + j] != '"' && str[*i + j] != ' ')
	{
		
		
			arg[j] = str[*i + j];
		j++;
		
	}
	if (arg[j - 1] == '\'')
		arg[j - 1] = 0;
	arg[j] = 0;
	*i = *i + j;
	tmp = ft_strjoinnospace(tmp, ft_returncontent(arg, env));
	if (str[*i - 1] == '\'')
	{
		while (tmp[j])
			j++;
		tmp[j] = '\'';
		tmp[j + 1] = '\0';
		if (str[*i + 2])
			tmp = ft_strjoinnospace(tmp, str + *i + 1);
		*i = j - 1;
		return (tmp);
	}
	j = 0;
	while (tmp[j])
		j++;
	tmp = ft_strjoinnospace(tmp, str + *i + 1);
	*i = j - 1;
	return (tmp);
}

char	*ft_double(char *str, t_env *env, int *i, t_track *tracker)
{
	char	*tmp;
	int		j;
	int		count;
	int		k;

	count = 0;
	j = 0;
	k = 0;
	
	tmp = ft_track(malloc((ft_strlen(str) + 2) * sizeof(char)), &tracker);
	while (str[j] && j < *i)
	{
	
			tmp[j] = str[j];
		j++;
	}
	j++;
	while (str[j] && str[j] != '"')
	{
		if (str[j] == '$' && str[j-2] != '<' && str[j-3] != '<')
		{
			tmp[j - 1] = 0;
			tmp = ft_joinarg(str, env, &j, tracker, tmp);
			*i = j - 2;
			return (tmp);
		}
		else
		{
			if (str[j] == ' ')
				tmp[j - 1] = '\\';
			else
				tmp[j - 1] = str[j];
		}
		j++;
		
	}
	j++;
	while (str[j])
	{
		tmp[j] = str[j];
		j++;
		
	}
	tmp[j] = 0;
	return (tmp);
}

char	*ft_quotes(char *str, t_env *env, t_track *tracker)
{
	char *tmp;
	int		i;
	char	q;

	q = 'q';
	i = 0;
	while(str[i])
	{
		if (str[i] == '\'' || str[i] == '"')
		{
			
			q = str[i];
			if (q == '\'')
				str = ft_simple(str, env, &i, tracker);
			else if (q == '"')
				str = ft_double(str, env, &i, tracker);
		}
		q = 'q';
		i++;
	}
	return (str);
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
	while (line[i] != '\0')
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
			tmp->key = ft_quotes(tmp->key, env, track);
			ft_track(tmp, &(track));
			ft_lstadd_back(&(cmd->listcmd), tmp);
			start = i + 1;
			if (line[i] == '\0')
				break;
		}
		i++;
	}
	ft_parse_redir(cmd->listcmd, track);
	return ;
}
