/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 22:06:25 by rcuminal          #+#    #+#             */
/*   Updated: 2022/05/04 00:55:46 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACKER_H
# define TRACKER_H

# include <stdlib.h>



typedef struct s_track
{
	void			*content;
	struct s_track	*next;
}				t_track;

void	*ft_track_tab(void **tab, t_track *list);
void	*ft_track(void *address, t_track *list);
int		ft_free_all(t_track *tracker);

void	ft_lstcleartracker(t_track **lst, void (*del)(void *));
void	ft_lstadd_backtotrack(t_track **alst, t_track *new);

void	*ft_memallocc(size_t size);
t_track	*ft_lstnewtracker(void **content);

#endif