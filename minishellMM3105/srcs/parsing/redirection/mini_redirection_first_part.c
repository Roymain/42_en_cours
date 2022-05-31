/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_redirection_first_part.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 20:37:38 by mathmart          #+#    #+#             */
/*   Updated: 2022/05/31 05:21:32 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	first_cut(char **cmd, int *i, t_list *tmp, t_mini *mini)
{
	if (cmd[*i][ft_strichr(cmd[*i], '<') + 1] == '<')
	{
		if (!cmd[*i][ft_strichr(cmd[*i], '<') + 2] && cmd[*i + 1])
		{
			tmp = ft_lstnew("<<", ft_track(ft_strdup(cmd[*i + 1]), \
					mini->track_cmd));
			ft_track(tmp, mini->track_cmd);
			ft_lstadd_back(&(mini->cmd->listcmd->redir), tmp);
			*i += 1;
		}
		else if (cmd[*i + 1])
		{
			tmp = ft_lstnew("<<", ft_track(ft_strnndup(cmd[*i], \
					ft_strlen(cmd[*i]) - (ft_strichr(cmd[*i], '<') - 2), \
					ft_strichr(cmd[*i], '<') + 2), mini->track_cmd));
			ft_track(tmp, mini->track_cmd);
			ft_lstadd_back(&(mini->cmd->listcmd->redir), tmp);
		}
		else
		{
			write(2, "minishell: syntax error near unexpected token `newline'\n", 57);
			mini->cmd->listcmd = NULL;
		}
	}
	else
	{
		tmp = ft_lstnew("<", cmd[*i] + (ft_strichr(cmd[*i], '<') + 1));
		ft_track(tmp, mini->track_cmd);
		ft_lstadd_back(&(mini->cmd->listcmd->redir), tmp);
	}
}

static int	second_cut(char **cmd, int i, t_mini *mini, t_list *tmp)
{
	if (!cmd[i][ft_strichr(cmd[i], '>') + 2])
	{
		tmp = ft_lstnew(ft_track(ft_strndup(cmd[i], \
			(ft_strichr(cmd[i], '>') + 2)), mini->track_cmd), cmd[i + 1]);
		ft_track(tmp, mini->track_cmd);
		ft_lstadd_back(&(mini->cmd->listcmd->redir), tmp);
		i++;
	}
	else
	{
		tmp = ft_lstnew(ft_track(ft_strndup(cmd[i], \
			(ft_strichr(cmd[i], '>') + 2)), mini->track_cmd), ft_track(\
			ft_strnndup(cmd[i], ft_strlen(cmd[i]) - (\
			ft_strichr(cmd[i], '>') - 2), ft_strichr(cmd[i], '>') + 2), \
			mini->track_cmd));
		ft_track(tmp, mini->track_cmd);
		ft_lstadd_back(&(mini->cmd->listcmd->redir), tmp);
	}
	return (i);
}

static int	third_cut(char **cmd, int i, t_mini *mini, t_list *tmp)
{
	char	*help;

	if (!cmd[i][ft_strichr(cmd[i], '>') + 1])
	{
		help = ft_strndup(cmd[i], ft_strichr(cmd[i], '>') + 1);
		ft_track(help, mini->track_cmd);
		tmp = ft_lstnew(help, cmd[i + 1]);
		ft_track(tmp, mini->track_cmd);
		ft_lstadd_back(&(mini->cmd->listcmd->redir), tmp);
		i++;
	}
	else
	{
		help = ft_strndup(cmd[i], (ft_strichr(cmd[i], '>') + 1));
		ft_track(help, mini->track_cmd);
		tmp = ft_lstnew(help, cmd[i] + (ft_strichr(cmd[i], '>') + 1));
		ft_track(tmp, mini->track_cmd);
		ft_lstadd_back(&(mini->cmd->listcmd->redir), tmp);
	}
	return (i);
}

int	mini_redirection_first_part(char **cmd, t_mini *mini, int i)
{
	t_list	*tmp;

	tmp = NULL;
	if (ft_strichr(cmd[i], '<') > -1)
		first_cut(cmd, &i, tmp, mini);
	else if (ft_strichr(cmd[i], '>') > -1)
	{
		if (cmd[i][ft_strichr(cmd[i], '>') + 1] == '>')
		{
			if (!cmd[i][ft_strichr(cmd[i], '>') + 2])
				i = second_cut(cmd, i, mini, tmp);
		}
		else
			i = third_cut(cmd, i, mini, tmp);
	}
	return (i);
}
