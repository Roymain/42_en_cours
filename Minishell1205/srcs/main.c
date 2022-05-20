/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 22:44:20 by rcuminal          #+#    #+#             */
/*   Updated: 2022/05/20 05:25:50 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	handler(int num)
{
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	quit(int num)
{
	printf("\n");
	rl_replace_line("", 0);
	rl_redisplay();
}

int	main(int argc, char **argv, char **ev)
{
	t_env	*env;
	t_cmd	*cmd;
	t_track	*trackenv;
	t_track	*trackcmd;
	char	*line;

	trackenv = ft_memalloc(sizeof(t_track));
	env = ft_track(ft_memalloc(sizeof(t_env)), trackenv);
	ft_parsenv(&env->list, ev, &trackenv);
	signal(SIGINT, handler);
	line = readline("minishell ~ ");
	while (line && ft_strncmp(line, "exit", ft_strlen("exit")))
	{
		signal(SIGQUIT, quit);
		trackcmd = ft_memalloc(sizeof(t_track));
		cmd = ft_track(ft_memalloc(sizeof(t_cmd)), trackcmd);
		cmd->fdin = dup(0);
		cmd->fdout = dup(1);
		add_history(line);
		parsingline(line, cmd, trackcmd, env);
		if (line[0])
			ft_exec(env, cmd, NULL);
		ft_free_all(trackcmd);
		free(line);
		line = readline("minishell ~ ");
	}
	ft_free_all(trackenv);
	free(line);
	rl_clear_history();
	printf("exit\n");
	return (0);
}
