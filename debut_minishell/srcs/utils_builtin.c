/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 09:44:14 by rcuminal          #+#    #+#             */
/*   Updated: 2022/03/09 11:00:56 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_push(t_list **pilea, t_list **pileb)
{
	t_list	*tmp;

	tmp = *pileb;
	*pileb = *pilea;
	if (tmp)
		(*pileb)->next = tmp;
	else
		(*pileb)->next = NULL;
}

void	ft_rotatepile(t_list **pile)
{
	t_list	*tmp;

	tmp = *pile;
	*pile = (*pile)->next;
	tmp->next = NULL;
	ft_lstadd_back(pile, tmp);
	return ;
}

char	ft_lowerchar(t_list	*list)
{
	char	c;

	c = ft_toupper(list->key[0]);
	list = list->next;
	while (list)
	{
		if (ft_toupper(list->key[0]) > c)
			c = ft_toupper(list->key[0]);
		list = list->next;
	}
	return (c);
}

void	ft_showexport(t_env *env)      
{
	t_list	*tmp;
	t_list	*tmp2;
	char	low;
	int		i;

	i = 0;
	tmp = env->list;
	low = ft_lowerchar(tmp);
	tmp = env->list;     //ajouter un while et un nombre de tour minimum
	while (tmp)
	{
		
	}

	
	// t_list	*tmp2;
	// int	i;

	// i = 0;
	// tmp = env->list;
	// tmp2 = tmp;
	// while (i++ < 10)
	// {
	// 	while (tmp)
	// 	{
	// 		if (ft_compare(tmp->key, tmp->next->key) == -1)
	// 		{
	// 			tmp->next = tmp2;
	// 			tmp = tmp->next;
	// 		}
	// 	}
	// }
	// while (tmp2)
	// {
	// 	dprintf(2, "%s   ", tmp2->key);
	// 	dprintf(2, "%s", tmp2->content);
	// 	dprintf(2, "\n");
	// 	tmp2 = tmp2->next;
	// }
	// return ;
}