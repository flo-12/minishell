# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 14:35:24 by mvomiero          #+#    #+#              #
#    Updated: 2023/04/24 13:23:11 by mvomiero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Program name
NAME	= minishell

# Compiler
CC		= cc
CFLAGS	= -Werror -Wextra -Wall

# Libft
LIBFT_PATH	= libft/
LIBFT_NAME	= libft.a
LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

# includes
INC			=	-I ./includes/ \
				-I ./libft/ \
				-I /opt/homebrew/ \
				-I/opt/homebrew/opt/readline/include

# Sources
SRC_PATH	=	srcs/
SRC			=	main.c \
				exit/exit_minishell.c \
				exit/free_data.c \
				exit/free_cmd_list.c \
				initialization/init_data.c \
				lexer/lexer.c lexer/quote_removal.c lexer/tokenization.c lexer/token_list_utils.c \
				lexer/var_expansion.c lexer/split_usr_input.c lexer/lexer_utils.c \
				parser/cmd_list_utils.c \
				parser/parser.c \
				parser/parse_word_fill_args.c \
				parser/parse_pipe.c \
				parser/parse_word.c	\
				parser/parse_input.c \
				parser/parse_output.c \
				parser/parse_heredoc.c \
				exit/error.c \
				test/test_token_list.c \
				test/print.c \
				execution/executor.c execution/utils_pipe.c execution/execute_cmd.c \
				execution/utils_io.c execution/utils_path.c execution/utils_expand.c\
				utils/utils.c \
				
				
#				parser/sandbox.c \

SRCS		= $(addprefix $(SRC_PATH), $(SRC))

# Objects
OBJ_PATH	= obj/
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

all: $(LIBFT) $(OBJ_PATH) $(NAME)

$(NAME): $(OBJS)
	@echo "Compiling minishell..."
	@-$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(INC) -lreadline -lhistory -ltermcap 
	@echo "\n\t\033[33;1;3mMinishell ready\n"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
#	@echo "Compiling object files"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJ_PATH):
	@echo "Generating obj folders"
	@mkdir $(OBJ_PATH)
	@mkdir $(OBJ_PATH)/exit
	@mkdir $(OBJ_PATH)/initialization
	@mkdir $(OBJ_PATH)/test
	@mkdir $(OBJ_PATH)/parser
	@mkdir $(OBJ_PATH)/lexer
	@mkdir $(OBJ_PATH)/execution
	@mkdir $(OBJ_PATH)/utils


$(LIBFT):
	@echo "Making libft..."
	@make -sC $(LIBFT_PATH)
	@make clean -sC $(LIBFT_PATH)

clean:
	@echo "Removing .o object files..."
	@rm -rf $(OBJ_PATH)
	@make clean -sC $(LIBFT_PATH)

fclean: clean
	@echo "Removing minishell..."
	@rm -f $(NAME)
	@make fclean -sC $(LIBFT_PATH)
#	@rm -f $(LIBFT_PATH)$(LIBFT_NAME)

re: fclean all

norminette_check:
	norminette ./src
	norminette -R CheckForbiddenSourceHeader ./includes

compile_mac: $(OBJS)
	@echo "Compiling minishell in mac..."
	@-$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(INC) -L/opt/homebrew/opt/readline/lib \
 -lreadline -ltermcap 
	@echo "\n\t\033[33;1;3mMinishell ready (MAC)\n"

.PHONY: all re clean fclean norminette_check compile_mac