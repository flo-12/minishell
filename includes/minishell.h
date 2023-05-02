/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:13:39 by mvomiero          #+#    #+#             */
/*   Updated: 2023/05/02 17:23:38 by mvomiero         ###   ########.fr       */
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
bool		init_data(t_data *data, char **env);
void		init_io(t_command *cmd);

/* LEXER */
_Bool		lexer(t_data *data);
char		**split_usr_input(char *usr_input);
void		var_expansion(char **usr_split, char **env);
t_token		*tokenization(char **usr_split);
void		quote_removal(t_token *token);

/* LEXER_UTILS */
int			get_nbr_spaces(char *str);

/* TOKEN_LIST_UTILS */
t_token		*token_lstnew(char *str, int type);
void		token_lstdelone(t_token *lst);
void		token_lstclear(t_token **lst);
void		token_lstadd_back(t_token **start, t_token *new);
t_token		*token_lstlast(t_token *lst);

/* PARSER */
void		parser(t_data *data);
bool		syntax_check(t_token **token_lst);
t_command	*cmd_lst_new(void);
void		cmd_lst_add_end(t_command **lst, t_command *new_node);
t_command	*cmd_lst_get_end(t_command *cmd);
void		parse_pipe(t_command **cmd, t_token **token_lst);
void		parse_word_fill_args(t_token **token_node, t_command *last_cmd);
void		parse_word(t_command **cmd, t_token **token_lst);
void		parse_input(t_command **last_cmd, t_token **token_lst);
void		parse_output(t_command **last_cmd, t_token **token_lst, char c);
void		parse_heredoc(t_command **last_cmd, t_token **token_lst);
bool		clear_old_infiles_heredoc(t_io_fds *io);
bool		generate_heredoc(t_io_fds *io);
bool		evaluate_heredoc_line(char **line, t_io_fds *io, bool *ret);
bool		fill_heredoc(t_io_fds *io, int fd);

/* SIGNALS */
void		signal_non_interactive(void);
void		signal_interactive(void);

/* EXECUTION */
int			executor(t_data *data);
int			execute_command(t_data *data, t_command *cmd);
int			execute_builtin(t_data *data, t_command *cmd);
// utils_pipe.c
bool		create_pipes(t_data *data);
void		set_pipes(t_command *c);
void		close_pipes(t_command *cmds);
// utils_io.c
bool		check_infile_outfile(t_io_fds *io);
void		redirect_io(t_io_fds *io);
bool		restore_io(t_io_fds *io);
// utils_path.c
bool		cmd_is_dir(char *cmd);
int			check_command_not_found(t_command *cmd);
char		*find_path(char *cmd, char **envp);
// utils_expand.c
void		expand_exit_code(char **args);

/* BUILTINS */
int			builtin_env(t_data *data);
int			builtin_export(t_data *data, char **args);
int			builtin_pwd(t_data *data);
int			builtin_echo(t_data *data, char **args);
int			builtin_cd(t_data *data, char **args);
int			builtin_unset(t_data *data, char **args);
int			builtin_exit(t_data *data, char **args);
int			builtin_exit(t_data *data, char **args);
int			get_env_var_i(char **env, char *str);
void		set_env_var(t_data *data, char *env);
_Bool		valid_env_var_name(char *env_name);

/* UTILS */
void		free_ptr(char **ptr);
int			get_size_ptr(char **ptr);
void		cpy_ptrs(char **dst, char **src);
int			ft_isspace(int c);
void		free_array_str(char **array);

/* EXIT */

void		exit_minishell(t_data *data, int exno);
void		free_pointer(void *ptr);
void		free_data(t_data *data, bool clear_history);
void		err_msg(char *s1, char *s2, char *s3);
void		err_msg_syntax(int type);
void		free_cmd_list(t_command **lst, void (*del)(void *));

/* TEST - PRINT */
void		print_cmd_list(t_data *data);
void		print_token_list(t_token **tokens);
void		minishell_testing(t_data *data, char *arg);

#endif
