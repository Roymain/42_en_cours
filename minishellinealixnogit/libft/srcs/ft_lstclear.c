/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 00:32:28 by rcuminal          #+#    #+#             */
/*   Updated: 2022/03/18 08:10:41 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	while (*lst)
	{
		if ((*lst)->redir != NULL)
			ft_lstclear(&(*lst)->redir, (&free));
		next = (*lst)->next;
		ft_lstdelone(*lst, del);
		(*lst) = next;
	}
}
