# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 18:34:26 by rcuminal          #+#    #+#              #
#    Updated: 2021/11/22 18:34:38 by rcuminal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = libftprintf.c \
		printf_utils.c \
		biputnbrbase.c


		

OBJS = ${SRCS:.c=.o}

CC = gcc
RM = rm -f

FLAGS = -Wall -Werror -Wextra

%.o : %.c libftprintf.h
	${CC} ${FLAGS} -I includes -c $< -o $@

$(NAME): ${OBJS}
	ar rcs ${NAME} ${OBJS}


all: ${NAME}

clean:
	${RM} ${OBJS} ${OBJSB}

fclean:	clean
	${RM} ${NAME}

re:	fclean all
         
.PHONY: all clean fclean re
