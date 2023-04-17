
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


//# define PATH_MAX 4096

int		builtin_env(t_data *data);
int		builtin_export(t_data *data, char **args);
int		builtin_pwd(t_data *data);
int		builtin_echo(t_data *data, char **args);
int		builtin_cd(t_data *data, char **args);
int		get_env_var_i(char **env, char *str);
void	set_env_var(t_data *data, char *env);

int		get_size_ptr(char **ptr);
void	cpy_ptrs(char **dst, char **src);
void	free_ptr(char **ptr);

void	err_msg(char *s1, char *s2, char *s3);

/******************************************************************************
*								ENUMS									      *
******************************************************************************/



#endif