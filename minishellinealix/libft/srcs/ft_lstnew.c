/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 22:45:15 by rcuminal          #+#    #+#             */
/*   Updated: 2022/03/16 05:56:58 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstnew(char *key, char *content, t_track *tracker)
{
	t_list	*new;

	new = ft_track(malloc(sizeof(t_list)), &tracker);
	ft_track((void *)content, &tracker);
	ft_track((void *)key, &tracker);
	if (!new)
		return (NULL);
	if (content[0] != '\0')
		new->content = content;
	else
		new->content = NULL;
	new->key = key;
	new->next = NULL;
	new->prev = NULL;
	new->redir = NULL;
	return (new);
}
