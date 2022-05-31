/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <mathmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:40:42 by mathmart          #+#    #+#             */
/*   Updated: 2022/05/30 17:55:45 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_builtin.h"

static int	contentequal(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static void	export_modif(t_list *list, char *content)
{
	t_list	*tmp;

	tmp = list;
	while (tmp)
	{
		if (ft_strncmp(content, tmp->key, ft_strichr(content, '=')) == 0)
		{
			if (tmp->content)
			{
				tmp->content = ft_strnndup(content, ft_strichr(content, '\0'),
						ft_strichr(content, '=') + 1);
			}
			else
				tmp->content = NULL;
		}
		tmp = tmp->next;
	}
}

static int	already_in(t_list	*list, char *key)
{
	t_list	*tmp;

	tmp = list;
	while (tmp)
	{
		if (ft_strncmp(key, tmp->key, ft_strichr(key, '=')) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	builtin_export(t_env *env, char *export)
{
	t_list	*tmp;

	if (already_in(env->list, export) == 1)
		return (export_modif(env->list, export));
	if (contentequal(export, '=') == 1 && export[ft_strichr(export, '=') + 1])
	{
		tmp = ft_lstnew(ft_strndup(export, ft_strichr(export, '=')),
				ft_strnndup(export, ft_strichr(export, '\0'),
					ft_strichr(export, '=') + 1));
		ft_lstadd_back(&env->list, tmp);
	}
	else if (contentequal(export, '=') == 1
		&& !export[ft_strichr(export, '=') + 1])
	{
		tmp = ft_lstnew(ft_strndup(export, ft_strichr(export, '=')), " ");
		ft_lstadd_back(&env->list, tmp);
	}
	else
	{
		tmp = ft_lstnew(ft_strndup(export, ft_strichr(export, '\0')),
				"\0");
		ft_lstadd_back(&env->list, tmp);
	}
}
