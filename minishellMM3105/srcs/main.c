/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 22:44:20 by rcuminal          #+#    #+#             */
/*   Updated: 2022/05/31 04:32:56 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	mini_init(t_mini *mini, int argc, char **argv)
{
	t_env	env;
	t_cmd	cmd;
	t_track	trackenv;
	t_track	trackcmd;

	(void)argc;
	(void)argv;
	mini->cmd = &cmd;
	mini->track_cmd = &trackcmd;
	mini->env = &env;
	mini->track_env = &trackenv;
	mini->track_env = ft_memalloc(sizeof(t_track));
	mini->env = ft_track(ft_memalloc(sizeof(t_env)), mini->track_env);
}

static void	mini_init_cmd(t_mini *mini)
{
	mini->track_cmd = ft_memalloc(sizeof(t_track));
	mini->cmd = ft_track(ft_memalloc(sizeof(t_cmd)), mini->track_cmd);
	mini->cmd->fdin = dup(0);
	mini->cmd->fdout = dup(1);
}

int	main(int argc, char **argv, char **envp)
{
	t_mini	mini;
	char	*line;

	mini_init(&mini, argc, argv);
	ft_parsenv(&mini.env->list, envp, &mini.track_env);
	signal(SIGINT, mini_handler);
	line = readline("minishell ~ ");
	while (line && ft_strncmp(line, "exit", ft_strlen("exit")))
	{
		signal(SIGQUIT, mini_quit);
		mini_init_cmd(&mini);
		add_history(line);
		mini_parsing_line(line, &mini);
		if (line[0])
			ft_exec(&mini, NULL);
		ft_free_all(mini.track_cmd);
		free(line);
		line = readline("minishell ~ ");
	}
	ft_free_all(mini.track_env);
	free(line);
	rl_clear_history();
	printf("exit\n");
	return (0);
}
