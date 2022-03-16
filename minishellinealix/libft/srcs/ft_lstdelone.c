/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 00:20:57 by rcuminal          #+#    #+#             */
/*   Updated: 2022/03/16 04:15:32 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	t_list *tmp;
	tmp = lst;
	if (lst->next && lst->prev)
		lst->prev->next = lst->next;
	if (lst->next && !lst->prev)
		lst = lst->next;
	if (!lst->next && lst->prev)
		lst->prev->next = NULL;
	if (del)
	{
		//if (tmp->content)
			del(tmp->content);
		//if (tmp->key)
			del(tmp->key);
	}
	free(tmp);
}
