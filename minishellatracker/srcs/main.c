/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 22:44:20 by rcuminal          #+#    #+#             */
/*   Updated: 2022/04/13 04:43:26 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
		ft_track(ft_strdup("ok"), &trackcmd);
		add_history(line);
		parsingline(line, cmd, trackcmd, env);
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
		// 	printf("==>>%s .\n", cmd->listcmd->key);
		// 	cmd->listcmd = cmd->listcmd->next;
		// }		
		ft_exec(env, cmd);		
		ft_track_free_all(&(trackcmd));		
		free(line);
		line = readline("minishell ~ ");
	}
	ft_track_free_all(&trackenv);
	free(line);
	rl_clear_history();
	printf("exit\n");
	return (0);
}
