# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/18 22:07:03 by abarchil          #+#    #+#              #
#    Updated: 2021/12/21 08:10:38 by abarchil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILE = main.c export.c $(wildcard src/*.c) minishell_init.c env.c pwd.c cd.c unset.c

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
%.o:%.c includes/minishell.h
	@echo "$(CYAN)----------- COMPILING $<"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ_FILE)
	@$(CC) $(CFLAGS) $(OBJ_FILE)  -lreadline -o $(NAME)

clean :
	@echo "$(YELLOW)------------ REMOVING OBJECT FILES"
	@rm -rf $(OBJ_FILE)
fclean : clean
	@echo "$(YELLOW)------------ REMOVING MINISHELL"
	@rm -rf $(NAME)
re : fclean all

.PHONY : clean fclean re 