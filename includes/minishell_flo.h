
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


# include "../libft/libft.h"

char	**split_usr_input(char *usr_input);
void	free_ptr(char **ptr);
int		get_size_ptr(char **ptr);
void	cpy_ptrs(char **dst, char **src);
int		get_nbr_spaces(char *str);

/* TESTING FUNCTIONS */
void	printf_ptrs(char **ptr);

/******************************************************************************
*								ENUMS									      *
******************************************************************************/

enum e_token_types {
	SPACES = 1,
	WORD,
	VAR,
	PIPE,
	INPUT,
	TRUNC,
	HEREDOC,
	APPEND,
	END
};

enum e_quoting_status {
	DEFAULT,
	SQUOTE,
	DQUOTE
};

#endif