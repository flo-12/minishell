
#ifndef MINISHELL_MARCO_H
# define MINISHELL_MARCO_H

#include "minishell.h"

/* TEST */

void	test_token_list(t_data *data);

/* PARSER */

void		parser(t_data *data);


t_command	*cmd_lst_new(void);
void		cmd_lst_add_end(t_command **lst, t_command *new_node);
t_command	*cmd_lst_get_end(t_command *cmd);
void		parse_pipe(t_command **cmd, t_token **token_lst);


#endif