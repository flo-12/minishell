/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:13:39 by mvomiero          #+#    #+#             */
/*   Updated: 2023/03/21 12:51:19 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/************* HEADERS *************/

// Inlcuded just the ones from the other project, we have to check at the end 
// which ones we are using and which ones no
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

# include "libft.h"
# include "minishell_define.h"

// unify the headers before heading in the project
# include "minishell_marco.h"
//# include "minishell_flo.h"


/************* FUNCTIONS *************/

/* INITIALIZATION */

bool	init_data(t_data *data, char **env);

/* LEXER */
_Bool	lexer(t_data *data);
char	**split_usr_input(char *usr_input);
void	var_expansion(char **usr_split, char **env);
t_token	*tokenization(char **usr_split);
void	quote_removal(t_token *token);
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

/* EXPANSION */

/* PARSER */

/* EXECUTION */

/* UTILS */

/* EXIT */

void	exit_minishell(t_data *data, int exno);
void	free_data(t_data *data, bool clear_history);






#endif
