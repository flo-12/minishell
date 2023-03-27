
#ifndef MINISHELL_FLO_H
# define MINISHELL_FLO_H

# include <unistd.h>
# include <errno.h>
# include <stdbool.h>
// expands bool to _Bool (datatype), true = 1, false = 0
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <limits.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <term.h>


# include "minishell_define.h"
# include "../libft/libft.h"

char	**split_usr_input(char *usr_input);
void	var_expansion(char **usr_split, char **env);
t_token	*tokenization(char **usr_split);
//void	quote_removal(char **usr_split);

/* LEXER_UTILS */
void	free_ptr(char **ptr);
int		get_size_ptr(char **ptr);
void	cpy_ptrs(char **dst, char **src);
int		get_nbr_spaces(char *str);

/* TOKEN_LIST_UTILS */
t_token	*token_lstnew(char *str, int type);
void	token_lstdelone(t_token *lst);
void	token_lstclear(t_token **lst);
void	token_lstadd_back(t_token **start, t_token *new);
t_token	*token_lstlast(t_token *lst);

/* TESTING FUNCTIONS */
void	printf_ptrs(char **ptr);
void	printf_token(t_token *token);

/******************************************************************************
*								ENUMS									      *
******************************************************************************/

enum e_token_types {
	SPACES = 1,
	WORD,
	//VAR,
	PIPE,
	INPUT,
	TRUNC,
	HEREDOC,
	APPEND,
	//END
};

/*enum e_quoting_status {
	DEFAULT,
	SQUOTE,
	DQUOTE
};*/

#endif