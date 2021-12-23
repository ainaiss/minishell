# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/18 22:07:03 by abarchil          #+#    #+#              #
#    Updated: 2021/12/23 20:18:44 by abarchil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILE = main.c export.c src/ft_strjoin.c src/ft_memcmp.c src/ft_split.c \
	src/ft_strchr.c src/ft_strcmp.c minishell_init.c env.c pwd.c cd.c unset.c echo.c \
	src/ft_calloc.c src/ft_del_node.c src/ft_isalpha.c src/ft_memcpy.c src/ft_lstnew.c \
	src/ft_memmove.c src/ft_memset.c src/ft_putstr_fd.c src/ft_putchar_fd.c src/ft_remchar.c \
	src/ft_strdup.c src/ft_strlen.c src/ft_strtrim.c src/ft_substr.c src/get_next_line.c \
	src/ft_bzero.c src/ft_lstadd_back.c lexing.c parsing.c src/ft_strndup.c

OBJ_FILE = $(SRC_FILE:.c=.o)

NAME = minishell

CC = gcc

RED = \033[0;31m

RESET = \033[0m

CYAN = \033[0;36m

YELLOW = \033[0;33m

CFLAGS = -Wall -Werror -Wextra 

all : $(NAME)
	@echo "$(RED) \
			███╗  ███╗██╗███╗   ██╗██╗ ██████╗██╗  ██╗███████╗██╗     ██╗    \n\
			████╗ ████║██║████╗ ██║██║██╔════╝██║  ██║██╔════╝██║     ██║     \n\
			██╔████╔██║██║██╔██╗██║██║╚█████╗ ███████║█████╗  ██║     ██║     \n\
			██║╚██╔╝██║██║██║╚████║██║ ╚═══██╗██╔══██║██╔══╝  ██║     ██║     \n\
			██║ ╚═╝ ██║██║██║ ╚███║██║██████╔╝██║  ██║███████╗███████╗███████╗\n\
			╚═╝     ╚═╝╚═╝╚═╝  ╚══╝╚═╝╚═════╝ ╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝ \n $(RESET)"
#	@echo "           		MADE WITH 💜 BY : abarchil & fel-boua $(RED)"
%.o:%.c includes/minishell.h
	@echo "$(CYAN)           		<----------- COMPILING $< -----------> $(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ_FILE)
	@$(CC) $(CFLAGS) $(OBJ_FILE)  -lreadline -o $(NAME)

clean :
	@echo "$(YELLOW)           		<----------- REMOVING OBJECT FILES ----------->$(RESET)"
	@rm -rf $(OBJ_FILE)
fclean : clean
	@echo "$(YELLOW)           		<----------- REMOVING MINISHELL ----------->$(RESET)"
	@rm -rf $(NAME)
re : fclean all

.PHONY : clean fclean re 