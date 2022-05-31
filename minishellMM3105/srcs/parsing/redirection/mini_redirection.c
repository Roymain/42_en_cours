/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_redirection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:45:39 by mathmart          #+#    #+#             */
/*   Updated: 2022/05/31 03:51:20 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_parse_redir(t_list *list, t_mini *mini)
{
	int		i;
	int		j;
	char	**cmd;

	j = 0;
	i = 0;
	while (list)
	{
		list->redir = NULL;
		cmd = ft_split(list->key, ' ', 0);
		ft_track_tab((void *)cmd, mini->track_cmd);
		while (cmd[i])
		{
			i = mini_redirection_first_part(cmd, mini, i);
			i++;
			mini_do_loop(cmd, j, mini, list);
		}
		list = list->next;
		j = 0;
		i = 0;
	}
}
