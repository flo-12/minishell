# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 14:35:24 by mvomiero          #+#    #+#              #
#    Updated: 2023/03/14 19:20:35 by mvomiero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Program name
NAME	= minishell

# Compiler
CC		= gcc
CFLAGS	= -Werror -Wextra -Wall

# Libft
LIBFT_PATH	= libft/
LIBFT_NAME	= libft.a
LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

# includes
INC			=	-I ./includes/\
				-I ./libft/

# Sources
SRC_PATH	=	srcs/
SRC			=	main.c \
				exit/exit_minishell.c \
				exit/free_data.c \
				initialization/init_data.c \

SRCS		= $(addprefix $(SRC_PATH), $(SRC))

# Objects
OBJ_PATH	= obj/
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

all: $(LIBFT) $(OBJ_PATH) $(NAME)

$(NAME): $(OBJS)
	@echo "Compiling minishell..."
	@-$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(INC) -lreadline -lhistory -ltermcap
	@echo "\n\t\033[33;1;3mMinishell ready\033[0m\n"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
#	@echo "Compiling object files"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJ_PATH):
	@echo "Generating obj folders"
	@mkdir $(OBJ_PATH)
	@mkdir $(OBJ_PATH)/exit
	@mkdir $(OBJ_PATH)/initialization

$(LIBFT):
	@echo "Making libft..."
	@make -sC $(LIBFT_PATH)

clean:
	@echo "Removing .o object files..."
	@rm -rf $(OBJ_PATH)
	@make clean -sC $(LIBFT_PATH)

fclean: clean
	@echo "Removing minishell..."
	@rm -f $(NAME)
#	@rm -f $(LIBFT_PATH)$(LIBFT_NAME)

re: fclean all

norminette_check:
	norminette ./src
	norminette -R CheckForbiddenSourceHeader ./includes

.PHONY: all re clean fclean