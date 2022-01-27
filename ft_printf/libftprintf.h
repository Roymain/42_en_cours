/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:ft_printf/libftprintf.h
/*   Created: 2021/11/19 19:30:58 by rcuminal          #+#    #+#             */
/*   Updated: 2021/11/20 02:26:32 by rcuminal         ###   ########.fr       */
=======
/*   Created: 2022/01/03 22:20:56 by rcuminal          #+#    #+#             */
/*   Updated: 2022/01/19 03:13:18 by Romain           ###   ########.fr       */
>>>>>>> 99685bb2725f3bdad439ff611718074a0630efa9:pipex_finito/includes/pipex.h
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

void				ft_putunsnbr_base(unsigned int nbr, char *base, int *ct);
void				ft_putunslongnbr_base(unsigned long nbr,
						char *base, int *ct);
int					ft_printf(const char *print, ...);
void				ft_tri(char c, va_list ap, int *ct);
void				ft_putchar_fd(char c, int fd, int *ct);
void				ft_putstr_fd(char *s, int fd, int *ct);
void				ft_putnbr_fd(int n, int fd, int *ct);
unsigned long long	ft_strlen(const char *theString);

#endif