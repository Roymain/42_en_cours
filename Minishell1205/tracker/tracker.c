/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 00:29:31 by rcuminal          #+#    #+#             */
/*   Updated: 2022/05/03 23:59:33 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracker.h"

void	ft_bzerotracker(void *s, size_t n)
{
	unsigned char	*z;
	size_t			i;

	z = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		z[i] = 0;
		i++;
	}
}

void	*ft_memallocc(size_t size)
{
	void	*mem;

	mem = malloc(size);
	if (mem)
	{
		ft_bzerotracker(mem, size);
		return (mem);
	}
	else
		return (NULL);
}


void	*ft_track_tab(void **tab, t_track *list)
{
	int	i;

	i = 0;
	if (tab)
		ft_lstadd_backtotrack(&list, ft_lstnewtracker(tab));
	while (tab[i])
	{
		if (tab[i])
			ft_lstadd_backtotrack(&list, ft_lstnewtracker(tab[i]));
		i++;
	}
	return ((void *)tab);
}

void	*ft_track(void *address, t_track *list)
{
	if (address)
		ft_lstadd_backtotrack(&list, ft_lstnewtracker(address));
	return (address);
}

int	ft_free_all(t_track *tracker)
{
	ft_lstcleartracker(&tracker, &(free));
	return (0);
}

// size_t	ft_strlen( const char *theString )
// {
// 	int	i;

// 	i = 0;
// 	while (theString[i])
// 	{
// 		i++;
// 	}
// 	return (i);
// }

// char	*ft_strdup(const char *src)
// {
// 	int		i;
// 	int		len;
// 	char	*str;

// 	i = 0;
// 	len = ft_strlen(src);
// 	str = (char *)malloc((sizeof(char) * len + 1));
// 	if (str == NULL)
// 		return (0);
// 	while (i < len)
// 	{
// 		str[i] = src[i];
// 		i++;
// 	}
// 	str[i] = '\0';
// 	return (str);
// }

// void	*ft_calloc( size_t elementCount, size_t elementSize)
// {
// 	unsigned char		*tab;
// 	size_t				i;

// 	i = 0;
// 	tab = (void *)malloc(elementCount * elementSize);
// 	if (!tab)
// 		return (NULL);
// 	while (i < elementCount * elementSize)
// 	{
// 		tab[i] = 0;
// 		i++;
// 	}
// 	return (tab);
// }

// static int	ft_count_c(char c, const char *s)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (s[i])
// 	{
// 		while (s[i] != c && s[i])
// 		{
// 			i++;
// 			if (s[i] == c || s[i] == '\0')
// 			{
// 				j++;
// 			}
// 		}
// 		if (s[i])
// 			i++;
// 	}
// 	if (j == 0)
// 		return (2);
// 	return (j + 1);
// }

// static int	ft_check_c(char c, char s)
// {
// 	if (c == s)
// 		return (1);
// 	return (0);
// }

// static char	*ft_strdupp(char const *s, char c, int *i)
// {
// 	char	*str;
// 	int		size;
// 	int		j;

// 	str = 0;
// 	size = 0;
// 	j = 0;
// 	while (ft_check_c(s[*i], c) == 0 && s[*i])
// 	{
// 		size++;
// 		*i += 1;
// 	}
// 	str = (char *)malloc(sizeof(char) * (size + 1));
// 	if (!str)
// 		return (ft_calloc(1, 0));
// 	*i = *i - size;
// 	while (ft_check_c(s[*i], c) == 0 && s[*i])
// 	{
// 		str[j] = s[*i];
// 		*i += 1;
// 		j++;
// 	}
// 	str[j] = '\0';
// 	return (str);
// }

// static int	freeall(char *str, char **dstr, int i)
// {
// 	if (!str)
// 	{
// 		while (i >= 0)
// 		{
// 			free(dstr[i]);
// 			i--;
// 		}
// 		free(dstr);
// 		return (1);
// 	}
// 	return (0);
// }

// char	**ft_split(char const *s, char c)
// {
// 	int		i;
// 	char	**str;
// 	int		j;

// 	j = 0;
// 	i = 0;
// 	if (!s)
// 		return (NULL);
// 	str = (char **)malloc(sizeof(char *) * (ft_count_c(c, s)));
// 	if (!str)
// 		return (NULL);
// 	while (s[i])
// 	{
// 		if (ft_check_c(c, s[i]) == 0)
// 		{
// 			str[j] = ft_strdupp(s, c, &i);
// 			if (j < ft_count_c(c, s) && freeall(str[j], str, j) == 1)
// 				return (NULL);
// 			j++;
// 		}
// 		else
// 			i++;
// 	}
// 	str[j] = 0;
// 	return (str);
// }

// int main()
// {
// 	char *str1;
// 	char *str2;
// 	char **tab;
// 	char **tab2;
// 	t_track *tracker;

// 	tracker = ft_memallocc(sizeof(t_track));
	
// 	str1 = ft_track(ft_strdup("merci bien"), tracker);
// 	str2 = ft_track(ft_strdup("merci roger"), tracker);
// 	tab = ft_track_tab((void **)ft_split("jean de la noe", ' '), tracker);
// 	tab2 = ft_track_tab((void **)ft_split("jean de la fontaine", ' '), tracker);

// 	ft_free_all(tracker);
// }