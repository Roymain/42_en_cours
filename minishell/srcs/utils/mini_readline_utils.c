/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_readline_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:20:03 by mathmart          #+#    #+#             */
/*   Updated: 2022/06/22 15:19:22 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	mini_handler(int num)
{
	(void)num;
	if (waitpid(-1, NULL, 0) != -1)
	{
		printf("\n");
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	mini_quit(int num)
{
	(void)num;
	if (waitpid(-1, NULL, 0) != -1)
	{
		printf("\n");
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else
	{
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}
