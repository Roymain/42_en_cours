# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 02:23:45 by rcuminal          #+#    #+#              #
#    Updated: 2022/09/29 02:25:20 by rcuminal         ###   ########.fr        #
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
NAME 		= 	 02.a
EXEC 		= 	 02
CC 			= 	 c++

PATH_SRC	=	./srcs/
PATH_OBJ	=	./objs/

SRC 		=   main.cpp \
				ClapTrap.cpp \
				ScavTrap.cpp \
				FragTrap.cpp \



OBJ_SRC		=	$(SRC:.cpp=.o)

SRC_O		=	$(addprefix $(PATH_SRC), $(SRC))
OBJ_S		=	$(addprefix $(PATH_OBJ), $(OBJ_SRC))

HEADER 		= 	./includes/
MK			= 	Makefile
SAN 		=
FLAGS 		= -std=c++98 -Wall -Werror -Wextra

$(PATH_OBJ)%.o : $(PATH_SRC)%.cpp $(MK)
	@mkdir $(PATH_OBJ) 2> /dev/null || true
	@-$(CC) -I includes -o $@ -c $<
	@printf "\r\t\033[K$(CCYAN)\t$< $(CCPURPLE)--> $(CCYAN)$@ $(CCEND)"
	@sleep 0.1

all: $(NAME)

$(NAME): $(OBJ_S)
	@printf "\r\t\033[K$(CCYAN)[✅]\t$(EXEC) $(CCPURPLE)--> $(CCYAN) Gen Objs$(CCEND)"
	@printf "\n$(CCYAN)[✅]\t$(CCPURPLE)Creation of Objs $(EXEC)...$(CCEND)\n"
	@printf "$(CCYAN)[✅]\t$(CCPURPLE)Creation of $(NAME)...$(CCEND)\n"
	@ar rc $(PATH_OBJ)$(NAME) $(OBJ_S)
	@$(CC) -I $(HEADER) $(PATH_OBJ)$(NAME) -o $(EXEC)
	@printf "$(CCYAN)[✅]\t$(CCPURPLE)Compilation ./$(EXEC)...$(CCEND)\n"

clean:
	@printf "$(CCYAN)[✅]\t$(CCRED)Removal of $(EXEC) Object...$(CCEND)\n"
	@-/bin/rm -rf $(PATH_OBJ)*.o

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