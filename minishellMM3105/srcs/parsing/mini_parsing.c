/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:25:39 by mathmart          #+#    #+#             */
/*   Updated: 2022/05/31 03:36:43 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	mini_in_quote(const char *line, int i)
{
	char	quote;

	quote = 0;
	if (line[i + 1] != '\0' && (line[i] == '"'
			|| line[i] == '\''))
		quote = line[i];
	else if (line[i + 1] != '\0' && line[i] == quote)
		quote = 0;
	return (quote);
}

static void	mini_init_parsing_line(int *i, int *start, char *quote)
{
	*i = -1;
	*start = 0;
	*quote = 0;
}

void	mini_parsing_line(char *line, t_mini *mini)
{
	t_list	*tmp;
	int		i;
	int		start;
	char	quote;

	mini_init_parsing_line(&i, &start, &quote);
	while (line[++i] != '\0')
	{
		quote = mini_in_quote(line, i);
		if ((!quote && line[i] == '|') || line[i + 1] == '\0')
		{
			if (line[i + 1] == '\0')
				i++;
			tmp = ft_lstnew(ft_track(ft_strndup(line + start, (i - start)),
						mini->track_cmd), "");
			tmp->key = ft_quotes(tmp->key, mini);
			ft_track(tmp, mini->track_cmd);
			ft_lstadd_back(&(mini->cmd->listcmd), tmp);
			start = i + 1;
			if (line[i] == '\0')
				break ;
		}
	}
	ft_parse_redir(mini->cmd->listcmd, mini);
}
