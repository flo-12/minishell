
#ifndef MINISHELL_MARCO_H
# define MINISHELL_MARCO_H

#include "minishell.h"

/* MACROS */

# define HEREDOC_NAME "/tmp/.minishell_heredoc_"
# define END 9
// MV: error 127 (command not found) is defined in errno.h but as EKEYEXPIRED, 
// so it's of course valid for other errors as well. That's why this macro here,
// for better understanding in code.
# define CMD_NOT_FOUND 127

/* FREE - EXIT */

void	free_pointer(void *ptr);

void	err_msg(char *s1, char *s2, char *s3);

void	free_cmd_list(t_command **lst, void (*del)(void *));

/* INITIALIZATION */

void	init_io(t_command *cmd);

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
void		parse_word_fill_args(t_token **token_node, t_command *last_cmd);
void		parse_word(t_command **cmd, t_token **token_lst);
void		parse_input(t_command **last_cmd, t_token **token_lst);
void		parse_output(t_command **last_cmd, t_token **token_lst, char c);
void		parse_heredoc(t_command **last_cmd, t_token **token_lst);

bool		generate_heredoc(t_io_fds *io);
bool		evaluate_heredoc_line(char **line,
									t_io_fds *io, bool *ret);
bool		fill_heredoc(t_io_fds *io, int fd);

/* EXECUTOR */


bool	create_pipes(t_data *data);
int		execute_command(t_data *data, t_command *cmd);



// sandbox
void	token_create_list(t_data *data);

/* UTILS */

void	free_array_str(char **array);




#endif
