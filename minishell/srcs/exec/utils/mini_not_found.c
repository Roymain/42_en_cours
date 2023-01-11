/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_not_found.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 09:32:23 by mathmart          #+#    #+#             */
/*   Updated: 2022/06/22 09:33:36 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_exec.h"

void	mini_not_found(t_cmd *cmd, t_env *env, char *path)
{
	dup2(cmd->fdout, 1);
	dup2(cmd->fdin, 0);
	env->return_value = 127;
	dprintf(2, "minishell: %s: command not found\n", path);
}
