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
# include "minishell_flo.h"


/************* FUNCTIONS *************/

/* INITIALIZATION */

bool	init_data(t_data *data, char **env);

/* LEXER */

/* EXPANSION */

/* PARSER */

/* EXECUTION */

/* UTILS */

/* EXIT */

void	exit_minishell(t_data *data, int exno);
void	free_data(t_data *data, bool clear_history);






#endif
