# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 22:58:14 by rcuminal          #+#    #+#              #
#    Updated: 2022/05/20 01:05:14 by rcuminal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Setting Color
CCEND 			=   	\033[0m
CCYAN 			=   	\033[34m
CGREEN			=   	\033[33m
CCRED 			=   	\033[31m
CCPURPLE 		=   	\033[35m
                	
EXEC 			= 	 minishell
NAME 			= 	 $(EXEC)
NAMEBONUS 		= 	 $(EXEC)_bonus
CC 			= 	 gcc
                	
PATH_SRC		=	./srcs/
PATH_OBJ		=	./objs/
                	
PATH_SRC_BONUS	=	./srcs_bonus/
PATH_OBJ_BONUS	=	./objs_bonus/
                	
SRC 			=   	main.c			\
						built-in.c		\
						built-in2.c		\
						built-inutils.c \
						built-inutils2.c \
						parsing.c		\
						exec.c 			\
						exec_builtin.c 			\
						exec_utils.c 	\
						exec_utils2.c 	\
                	
OBJ_SRC			=	$(SRC:.c=.o)
                	
SRC_O			=	$(addprefix $(PATH_SRC), $(SRC))
OBJ_S			=	$(addprefix $(PATH_OBJ), $(OBJ_SRC))
                	
SRC_BONUS 		=   
						
                	
OBJ_SRC_BONUS	=	$(SRC_BONUS:.c=.o)
                	
SRCBONUS		=	$(addprefix $(PATH_SRC_BONUS), $(SRC_BONUS))
OBJ_BONUS		=	$(addprefix $(PATH_OBJ_BONUS), $(OBJ_SRC_BONUS))
                	
HEADER 			= 	includes/$(EXEC).h
HEADERBONUS 		= 	includes_bonus/$(EXEC)_bonus.h
MK				= 	Makefile
SAN 			= 	
FLAGS 			= 	
#-ggdb 
INC_INC = -I ~/.brew/opt/readline/include
INC_LIB = -L ~/.brew/opt/readline/lib  
 


DIR_FT			=	libft/
DEPEND_FT		= 	$(DIR_FT)objs/libft.a
DIR_TRACK		=	tracker/
DEPEND_TRACK	= 	$(DIR_TRACK)libtracker.a
LIB				= 	-lreadline	$(INC_LIB) $(INC_INC) -L$(DIR_TRACK) -ltracker -L$(DIR_FT)objs -lft

all: $(NAME)
bonus: $(NAME_BONUS)

$(PATH_OBJ)%.o : $(PATH_SRC)%.c $(HEADER) $(MK)
	@mkdir $(PATH_OBJ) 2> /dev/null || true
	@-$(CC) -I ./includes -o $@ -c $<
	@printf "\r\t\033[K$(CCYAN)\t$< $(CCPURPLE)--> $(CCYAN)$@ $(CCEND)"

$(PATH_OBJ_BONUS)%.o : $(PATH_SRC_BONUS)%.c $(HEADERBONUS) $(MK)
	@mkdir $(PATH_OBJ_BONUS) 2> /dev/null || true
	@-$(CC) -I ./includes -o $@ -c $<
	@printf "\r\t\033[K$(CCYAN)\t$< $(CCPURPLE)--> $(CCYAN)$@ $(CCEND)"

$(DEPEND_FT):
	make -C $(DIR_FT)
	
$(DEPEND_TRACK):
	make -C $(DIR_TRACK)

$(NAME): $(OBJ_S) $(DEPEND_FT) $(DEPEND_TRACK) $(HEADER) $(MK)
	@$(CC) $(SAN) $(LIB) $(FLAGS) $(OBJ_S) -o $(NAME)
	@printf "$(CCYAN)[✅]\t$(CCPURPLE)Compilation ./$(NAME)...$(CCEND)\n"

$(NAMEBONUS): $(OBJ_BONUS) $(DEPEND_FT) $(DEPEND_TRACK) $(HEADERBONUS) $(MK)
	@$(CC) $(SAN) $(LIB) $(FLAGS) $(OBJ_SRC_BONUS) -o $(NAMEBONUS)
	@printf "$(CCYAN)[✅]\t$(CCPURPLE)Compilation ./$(NAMEBONUS)_bonus...$(CCEND)\n"

san: $(OBJ_S) $(DEPEND_FT) $(DEPEND_TRACK) $(HEADER) $(HEADERBONUS) $(MK)
	@$(CC) $(FLAGS) $(SAN) $(LIB) $(OBJ_S) -o $(NAME)
	@printf "$(CCYAN)[✅]\t$(CCPURPLE)Compilation with sanitize $(NAME)...$(CCEND)\n"
	#@$(CC) $(FLAGS) $(SAN) $(LIB) $(OBJ_S) -o $(NAME_BONUS)
	#@printf "$(CCYAN)[✅]\t$(CCPURPLE)Compilation with sanitize $(NAME_BONUS)...$(CCEND)\n"

clean:
	@make clean -C libft
	@make clean -C tracker
	@printf "$(CCYAN)[✅]\t$(CCRED)Removal of $(EXEC) Object...$(CCEND)\n"
	@-/bin/rm -rf $(PATH_OBJ_BONUS)
	@-/bin/rm -rf $(PATH_OBJ)

fclean: clean
	@make fclean -C libft
	@make fclean -C tracker
	@printf "$(CCYAN)[✅]\t$(CCRED)Removal of $(NAME)...$(CCEND)\n"
	@-/bin/rm -f $(EXEC)
	@-/bin/rm -f $(EXEC)_bonus
norme:
	@echo "\033[33mNorme ..."
	@norminette $(SRC)
	@norminette $(HEADER)

start:
	@sleep 0.5
	@clear
	@printf "\n\n\n$(CCYAN)"
	@printf "\t\t$(EXEC)"
	@printf "\n\n\n"
	@printf "Execution make:\n$(CCEND)"

git:	fclean
	@git add .
	@git commit -m "$(filter-out $@,$(MAKECMDGOALS))"
	@git push

.PHONY: all clean fclean re san
.SILENT :
re: fclean all