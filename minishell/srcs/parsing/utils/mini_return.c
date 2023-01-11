/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_return.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:57:43 by mathmart          #+#    #+#             */
/*   Updated: 2022/05/30 22:21:35 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*mini_return(char *arg, t_env *env)
{
	t_list	*tmp;

	tmp = env->list;
	while (tmp)
	{
		if (ft_strncmp(tmp->key, arg + 1, ft_strlen(arg)) == 0)
			return (tmp->content);
		tmp = tmp->next;
	}
	return ("");
}
