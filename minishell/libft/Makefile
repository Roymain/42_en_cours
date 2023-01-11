
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mathmart <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/03 19:44:56 by rcuminal          #+#    #+#              #
#    Updated: 2022/05/07 21:52:39 by mathmart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

-include Config/Sources.mk
-include Config/Header.mk

#################################################################################
#									Colors										#
#################################################################################

GREY		= \033[4;34m
RED			= \033[1;31m
GREEN		= \033[3;32m
YELLOW		= \033[2;49;33m
BLUE		= \033[4;34m
BLUEE		= \033[3;34m
PURPLE		= \033[3;35m
CYAN		= \033[3;36m
RESET		= \033[0m
ICONOK		= \033[1;32m
ICONKO		= \033[1;31m
CO_DELET	= \033[4;31m
CO_A_OUT	= \033[96m
WHITE		= \033[1;49;97m

#################################################################################
#									Variables									#
#################################################################################

NAME		= libft.a
OBJ_DIR		= objs
OBJS		= $(SRCS:%.c=%.o)
OBJ_PATH	= $(addprefix $(OBJ_DIR)/, $(OBJS))
CFLAGS		= -Wall -Werror -Wextra -I ./includes
CONFIG		= $(shell find [0-9a-zA-Z]* -type d -name "Config")
MK_DIR		= Config 

#################################################################################
#									Compilation C								#
#################################################################################

all: gmk $(NAME)

$(NAME): $(OBJ_PATH)
	@ar rcs $(NAME) $(OBJ_PATH) $(NAME)
	@printf "\033[2K\r$(BLUE)$(NAME)$(RESET)$(BLUEE): $(ICONOK)Compiled [√]$(RESET)\n"

#################################################################################
#									Compilation Objects							#
#################################################################################

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@mkdir -p $(@D)
	@gcc $(CFLAGS) -c $< -o $@
	@printf "\033[2K\r$(PURPLE)$<: $(CYAN)loading..$(RESET)"

$(OBJ_DIR):
	@printf "\033[1;32mCreate OBJS_DIR $(CO_DELET)\033[3;32m [√]\033[0m\n"

#################################################################################
#									Clean										#
#################################################################################

clean:
	@-/bin/rm -rf $(OBJ_PATH)
	@printf "\033[1;31mDelete OBJS $(CO_DELET)$(NAME)\033[3;32m [√]\033[0m\n"

fclean: clean
	@-/bin/rm -rf $(OBJ_DIR) $(NAME) $(CONFIG)
	@printf "\033[1;31mDelete $(CO_DELET)$(NAME)\033[3;32m [√]\033[0m\n"

#################################################################################
#									Gen MK										#
#################################################################################

$(MK_DIR):
ifneq ($(CONFIG), Config)
	@mkdir Config
endif

gmk: $(MK_DIR)
	@echo "SRCS += " > ./Config/Sources.mk
	@find srcs -name '*.c' | sed 's/^/SRCS += /' >> ./Config/Sources.mk
	@echo "HEADER += " > ./Config/Header.mk
	@find Includes -name '*.h' | sed 's/^/HEADER += /' >> ./Config/Header.mk

#################################################################################
#									Clena & Compilation							#
#################################################################################

re: fclean all

.PHONY: all clean fclean gmk re
