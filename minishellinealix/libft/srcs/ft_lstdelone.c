/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbejaoui <sbejaoui@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 00:20:57 by rcuminal          #+#    #+#             */
/*   Updated: 2022/03/09 11:13:57 by sbejaoui         ###   ########lyon.fr   */
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
		del(tmp->content);
		del(tmp->key);
	}
	free(tmp);
}
