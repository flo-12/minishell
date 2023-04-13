/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_define.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:29:46 by mvomiero          #+#    #+#             */
/*   Updated: 2023/04/13 15:43:40 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_DEFINE_H
# define MINISHELL_DEFINE_H

# include "minishell.h"

/* MACROS */

# define PROMPT "Hello world!"
# define PROMPT_HEREDOC ">"
# define BUILTIN_ERR_IDENT "not a valid identifier"

/* GLOBAL VARIABLE */

extern int	last_exit_code;

/* STRUCTS */

typedef struct s_token
{	
	char			*str;
	char			*str_backup;
	int				type;
	struct s_token	*prev;
	struct s_token	*next;
}	t_token;

typedef struct s_io_fds
{
	char	*infile;
	char	*outfile;
	char	*heredoc_delimiter;
	int		fd_in;
	int		fd_out;
}	t_io_fds;

typedef struct s_command
{
	char				*command;
	char				*path;
	char				**args;
	bool				pipe_output;
	int					*pipe_fd;
	t_io_fds			*io_fds;
	struct s_command	*next;
	struct s_command	*prev;
}	t_command;

typedef struct s_data
{
	char		*user_input;
	char		**env;
	char		*working_dir;
	char		*old_working_dir;
	t_token		*token;
	t_command	*cmd;
	pid_t		pid;
}	t_data;

/* ENUMS */
enum e_token_types {
	SPACES = 1,
	WORD,
	PIPE,
	INPUT,
	TRUNC,
	HEREDOC,
	APPEND
};

# endif