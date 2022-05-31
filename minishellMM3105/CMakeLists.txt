cmake_minimum_required(VERSION 3.20.2)
project(minishell)

set(CMAKE_C_STANDARD 99)

include_directories(.)
include_directories(includes/ ~/.brew/opt/readline/include/ ./srcs/utils/tracker/include/)
include_directories(includes/parsing/ libft/includes/)

FIND_LIBRARY(READLINE readline ~/.brew/opt/readline/lib)
FIND_LIBRARY(LIBFT libft libft/)

add_executable(minishell
        srcs/builtin/built-inutils.c
        srcs/builtin/built-inutils2.c
        srcs/exec/exec.c
        srcs/exec/exec_builtin.c
        srcs/exec/exec_utils.c
        srcs/exec/exec_utils2.c
        srcs/main.c
        srcs/parsing/mini_parsing_env.c
        srcs/parsing/quotes/mini_parsing_quote.c
        srcs/parsing/quotes/mini_single_quote.c
        srcs/parsing/utils/mini_return.c
        srcs/parsing/utils/mini_strjoin.c
        srcs/utils/mini_readline_utils.c
        srcs/utils/tracker/srcs/tracker.c
        srcs/utils/tracker/srcs/tracker_utils.c
        srcs/parsing/quotes/mini_double_quote.c
        srcs/parsing/utils/mini_push_int_tab.c
        srcs/parsing/mini_parsing.c
        srcs/parsing/redirection/mini_redirection.c
        srcs/parsing/redirection/mini_redirection_first_part.c
        srcs/parsing/redirection/mini_redirection_second_part.c
        srcs/builtin/mini_env.c srcs/builtin/mini_echo.c srcs/builtin/mini_export.c srcs/builtin/mini_pwd.c srcs/builtin/mini_unset.c srcs/builtin/mini_cd.c)

#target_link_libraries(minishell ${LIBFT})