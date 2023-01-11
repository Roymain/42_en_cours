/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <mathmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:39:23 by mathmart          #+#    #+#             */
/*   Updated: 2022/05/30 17:39:23 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_builtin.h"

void	builtin_unset(t_env *env, char *key)
{
	t_list	*tmp;

	tmp = env->list;
	while (tmp)
	{
		if (tmp->next)
		{
			if (ft_strncmp(tmp->next->key, key, ft_strlen(key)) == 0)
			{
				free(tmp->next->key);
				free(tmp->next->content);
				free(tmp->next);
				if (tmp->next->next)
					tmp->next = tmp->next->next;
				else
					tmp->next = NULL;
			}
		}
		tmp = tmp->next;
	}
	env->return_value = 0;
}
