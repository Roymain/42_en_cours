/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <mathmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:42:34 by mathmart          #+#    #+#             */
/*   Updated: 2022/05/30 17:42:34 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_builtin.h"

void	builtin_env(t_env *env)
{
	t_list	*tmp;

	tmp = env->list;
	while (env->list)
	{
		if (env->list->content)
		{
			printf("%s=", env->list->key);
			printf("%s", env->list->content);
			printf("\n");
		}
		env->list = env->list->next;
	}
	env->list = tmp;
	env->return_value = 0;
}
