# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Romain <Romain@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/09 21:22:18 by rcuminal          #+#    #+#              #
#    Updated: 2022/09/02 00:28:49 by Romain           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Setting Color
CCEND 		=   	\033[0m
CCYAN 		=   	\033[34m
CGREEN		=   	\033[33m
CCRED 		=   	\033[31m
CCPURPLE 	=   	\033[35m

#Get arguments pass
ARGV		=	$(filter-out $@,$(MAKECMDGOALS))
NAME 		= 	 cub3d.a
EXEC 		= 	 cub3d
CC 			= 	 gcc

PATH_SRC	=	./srcs/
PATH_OBJ	=	./objs/

SRC 		=   main.c 

		

OBJ_SRC		=	$(SRC:.c=.o)

SRC_O		=	$(addprefix $(PATH_SRC), $(SRC))
OBJ_S		=	$(addprefix $(PATH_OBJ), $(OBJ_SRC))

HEADER 		= 	./includes/
MK			= 	Makefile
SAN 		=
FLAGS 		=	 -Wall -Werror -Wextra  -fsanitize=address

$(PATH_OBJ)%.o : $(PATH_SRC)%.c $(MK)
	@mkdir $(PATH_OBJ) 2> /dev/null || true
	@-$(CC) -I Includes -Imlx -o $@ -c $<
	@printf "\r\t\033[K$(CCYAN)\t$< $(CCPURPLE)--> $(CCYAN)$@ $(CCEND)"
	@sleep 0.1

all: $(NAME)

$(NAME): $(OBJ_S) mlx tracker
	@printf "\r\t\033[K$(CCYAN)[✅]\t$(EXEC) $(CCPURPLE)--> $(CCYAN) Gen Objs$(CCEND)"
	@printf "\n$(CCYAN)[✅]\t$(CCPURPLE)Creation of Objs $(EXEC)...$(CCEND)\n"
	@printf "$(CCYAN)[✅]\t$(CCPURPLE)Creation of $(NAME)...$(CCEND)\n"
	@ar rc $(PATH_OBJ)$(NAME) $(OBJ_S)
	@$(CC)    -Llibmlx -lmlx -framework OpenGL -framework AppKit  $(PATH_OBJ)$(NAME)  -o $(EXEC)
	@printf "$(CCYAN)[✅]\t$(CCPURPLE)Compilation ./$(EXEC)...$(CCEND)\n"

clean:
	@printf "$(CCYAN)[✅]\t$(CCRED)Removal of $(EXEC) Object...$(CCEND)\n"
	@-/bin/rm -rf $(PATH_OBJ)*.o
	make -C libmlx clean
	make -C libft fclean
	make -C tracker fclean

tracker:
	make -C tracker

mlx :
	make -C libmlx 2>/dev/null		
		
lft :
	make -C libft
	

fclean: clean
	@printf "$(CCYAN)[✅]\t$(CCRED)Removal of $(NAME)...$(CCEND)\n"
	@-/bin/rm -f $(PATH_OBJ)*.a
	@-/bin/rm -rf $(PATH_OBJ)
	@-/bin/rm -f Tags
	@-/bin/rm -rf .ccls-cache
	@-/bin/rm -f $(EXEC)

.PHONY: all clean fclean re san
.SILENT :
re: fclean all




				
# 				%.o: %.c
# 	$(CC) -Imlx -c $< -o $@
	
# $(NAME): $(OBJS) mlx lft
# 	$(CC) -Llibmlx -lmlx -framework OpenGL -framework AppKit $(VERIF) $(LIBS_PERSO) $(OBJS) -o $(NAME)


#FLAGS 		=	 -Wall -Werror -Wextra  -Llibmlx -lmlx -framework OpenGL -framework AppKit $(VERIF) $(LIBS_PERSO) $(OBJS) -o $(NAME)

