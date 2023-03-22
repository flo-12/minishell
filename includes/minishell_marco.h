
#ifndef MINISHELL_MARCO_H
# define MINISHELL_MARCO_H

#include "minishell.h"

/* TEST */

void	test_token_list(t_data *data);

/* TEST - print */

void		print_cmd_list(t_data *data);
void		print_token_list(t_token **tokens);

/* PARSER */

void		parser(t_data *data);

t_command	*cmd_lst_new(void);
void		cmd_lst_add_end(t_command **lst, t_command *new_node);
t_command	*cmd_lst_get_end(t_command *cmd);
void		parse_pipe(t_command **cmd, t_token **token_lst);
void		fill_args(t_token **token_node, t_command *last_cmd);
void		parse_word(t_command **cmd, t_token **token_lst);


// sandbox
void	token_create_list(t_data *data);

/* UTILS */

void	free_array_str(char **array);




#endif
