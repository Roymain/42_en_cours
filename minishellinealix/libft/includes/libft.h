/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:13:48 by rcuminal          #+#    #+#             */
/*   Updated: 2022/03/16 04:56:16 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_track
{
	void	**mem;
	int		len;
}			t_track;

typedef struct s_list
{
	char			*key;
	char			*content;
	struct s_list	*redir;
	struct s_list	*prev;
	struct s_list	*next;
}			t_list;

void	ft_freetab(char **tab);
char	*ft_strndup(const char *src, int size);
int		ft_strichr(const char *str, int to_find);
void	*ft_memalloc(size_t size);
int		ft_atoi(const char *str, int *i);
void	*ft_calloc( size_t elementCount, size_t elementSize);
char	*ft_strdup(const char *src);
char	*ft_strnndup(const char *src, int size, int start);
int		ft_isalnum(int c);
int		ft_isprint(int c);
int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strchr(const char *str, int to_find);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *str, const char *to_find, size_t n);
char	*ft_strrchr(const char *str, int to_find);
int		ft_toupper(int character);
int		ft_tolower(int character);

void	ft_bzero(void *s, size_t n);
int		ft_strlen( const char *theString );
//P2
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c, int i);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

t_list	*ft_lstnew(char *key, char *content, t_track *tracker);
void	ft_lstadd_front(t_list **alst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

void	*ft_error_mal(void *mem, t_track **track);
void	**ft_error_malt(void **mem, t_track **track);
void	**ft_add_malloc(t_track **track, int len);
void	*ft_track(void *src, t_track **track);
void	**ft_track_tab(void **src, t_track **track);
void	**ft_track_free(t_track **track, void *mem);
void	**ft_track_free_all(t_track **track);
void	**ft_track_free_tab(t_track **track, void **mem);
#endif