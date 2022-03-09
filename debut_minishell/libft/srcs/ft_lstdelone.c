/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 00:20:57 by rcuminal          #+#    #+#             */
/*   Updated: 2022/03/09 11:49:38 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (del)
	{
		lst->content = NULL;
		del(lst->content);
		lst->key = NULL;
		del(lst->key);
	}
	if (lst->next && lst->prev)
		lst->prev->next = lst->next;
	if (lst->next && !lst->prev)
		lst = lst->next;
	if (!lst->next && lst->prev)
		lst->prev->next = NULL;
	free(lst);
}
