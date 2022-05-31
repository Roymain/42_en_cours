/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_redirection_second_part.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <mathmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 20:37:19 by mathmart          #+#    #+#             */
/*   Updated: 2022/05/26 20:37:19 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	first_j_cut(int j, t_mini *mini, t_list *list, char **cmd)
{
	if (ft_strichr(cmd[j], '-') > -1 && j == 0)
		list->key = cmd[j];
	if (ft_strichr(cmd[j], '<') > 0)
	{
		list->key = ft_track(mini_strjoin(ft_strndup(list->key, \
		ft_strichr(cmd[j], '<')), list->key + ft_strichr(cmd[j], '>')), \
		mini->track_cmd);
	}
	else if (ft_strichr(cmd[j], '>') == -1 && j == 0)
		list->key = cmd[j];
	return (j);
}

static int	second_j_cut(int j, char **cmd, t_list *list, t_mini *mini)
{
	if (ft_strichr(cmd[j], '>') > -1 && j == 0)
	{
		if (!cmd[j][ft_strichr(cmd[j], '>') + 1])
			j++;
		else if (cmd[j][ft_strichr(cmd[j], '>') + 1] == '>' )
		{
			if (!cmd[j][ft_strichr(cmd[j], '>') + 2])
				j++;
		}
		list->key = ft_track(ft_strdup(""), mini->track_cmd);
	}
	else if (ft_strichr(cmd[j], '-') > -1 && j != 0)
		list->key = ft_track(ft_strjoin(list->key, cmd[j] + \
			(ft_strichr(cmd[j], '-'))), mini->track_cmd);
	return (j);
}

static int	third_j_cut(int j, char **cmd, t_list *list, t_mini *mini)
{
	if (ft_strichr(cmd[j], '-') == -1 && ft_strichr(cmd[j], '>') \
		== -1 && ft_strichr(cmd[j], '<') == -1 && j != 0)
		list->key = ft_track(ft_strjoin(list->key, cmd[j]), mini->track_cmd);
	else if (ft_strichr(cmd[j], '>') > -1)
	{
		if (!cmd[j][ft_strichr(cmd[j], '>') + 1])
			j++;
		else if (cmd[j][ft_strichr(cmd[j], '>') + 1] == '>')
			if (!cmd[j][ft_strichr(cmd[j], '>') + 2])
				j++;
	}
	else if (ft_strichr(cmd[j], '<') > -1)
		if (!cmd[j][ft_strichr(cmd[j], '<') + 2])
			j++;
	return (j);
}

void	mini_do_loop(char **cmd, int j, t_mini *mini, t_list *list)
{
	while (cmd[j])
	{
		j = first_j_cut(j, mini, list, cmd);
		j = second_j_cut(j, cmd, list, mini);
		j = third_j_cut(j, cmd, list, mini);
		j++;
	}
}
