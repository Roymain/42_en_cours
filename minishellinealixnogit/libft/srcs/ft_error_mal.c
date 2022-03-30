/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_mal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:12:31 by jmilhas           #+#    #+#             */
/*   Updated: 2022/02/23 22:12:17 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_error_mal(void *mem, t_track **track)
{
	if (!mem)
	{
		ft_putstr_fd("Error allocation\n..", 2);
		if ((*track)->len > 0)
			ft_track_free_all(track);
	}
	return (mem);
}

void	**ft_error_malt(void **mem, t_track **track)
{
	if (!mem)
	{
		ft_putstr_fd("Error allocation\n..", 2);
		if ((*track)->len > 0)
			ft_track_free_all(track);
	}
	return (mem);
}
