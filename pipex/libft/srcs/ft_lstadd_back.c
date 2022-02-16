/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:56:50 by rcuminal          #+#    #+#             */
/*   Updated: 2022/01/12 02:54:56 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*var;

	if (*alst)
	{
		var = ft_lstlast(*alst);
		var->next = new;
	}
	else if (!*alst && new)
		*alst = new;
	else
		*alst = NULL;
}
