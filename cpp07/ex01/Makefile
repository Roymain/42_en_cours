# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/09 22:59:26 by rcuminal          #+#    #+#              #
#    Updated: 2022/10/09 23:09:44 by rcuminal         ###   ########.fr        #
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
NAME 		= 	 01
EXEC 		= 	 01
CC 			= 	 c++

PATH_SRC	=	./srcs/
PATH_OBJ	=	./objs/

SRC 		=   main.cpp

INC = ./includes/iter.hpp 


OBJ_SRC		=	$(SRC:.cpp=.o)

SRC_O		=	$(addprefix $(PATH_SRC), $(SRC))
OBJ_S		=	$(addprefix $(PATH_OBJ), $(OBJ_SRC))

HEADER 		= 	./includes/
MK			= 	Makefile
SAN 		=
FLAGS 		= -std=c++98 -Wall -Werror -Wextra


$(PATH_OBJ)%.o : $(PATH_SRC)%.cpp $(MK) $(INC)
	@mkdir $(PATH_OBJ) 2> /dev/null || true
	$(CC) -I includes $(FLAGS) -o $@ -c $<

all: $(NAME)


$(NAME): $(OBJ_S)
	$(CC) $(FLAGS) -I $(HEADER) $(OBJ_S) -o $(EXEC)
	

clean:
	@printf "$(CCYAN)[✅]\t$(CCRED)Removal of $(EXEC) Object...$(CCEND)\n"
	@-/bin/rm -rf $(PATH_OBJ)*.o

fclean: clean
	@printf "$(CCYAN)[✅]\t$(CCRED)Removal of $(NAME)...$(CCEND)\n"
	@-/bin/rm -rf $(PATH_OBJ)
	@-/bin/rm -f $(EXEC)

.PHONY: all clean fclean re san

re: fclean all