/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:42:55 by mvomiero          #+#    #+#             */
/*   Updated: 2023/04/28 17:42:23 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* create_pipes:
	create a pipe for each command that has a pipe output or if the previous 
	command has a pipe output (it will be the one reciving infos as input).
	If a command will redirect both input and output trough pipes of course the
	created pipe will just be one, thanks to the || operator in the if 
	condition.
	In case of error, a message is printed and false is returned. 
 */
bool	create_pipes(t_data *data)
{
	t_command	*tmp;

	tmp = data->cmd;
	while (tmp)
	{
		if (tmp->pipe_output || (tmp->prev && tmp->prev->pipe_output))
		{
			tmp->pipe_fd = malloc(sizeof * tmp->pipe_fd * 2);
			if (!tmp->pipe_fd)
				return (err_msg("malloc error", strerror(errno), NULL), false);
			if (pipe(tmp->pipe_fd) != 0)
				return (err_msg("pipe error", strerror(errno), NULL), false);
		}
		tmp = tmp->next;
	}
	return (true);
}

/* set_pipe_fds:
	- sets the input pipe pipe_fd[0] of the previous command as STDIN 0,
	- sets the output pipe pipe_fd[1] of the previous command as STDOUT 1.
 */
void	set_pipes(t_command *cmd)
{
	if (cmd->prev && cmd->prev->pipe_output)
		dup2(cmd->prev->pipe_fd[0], STDIN_FILENO);
	if (cmd->pipe_output)
		dup2(cmd->pipe_fd[1], STDOUT_FILENO);
}

void	close_pipes(t_command *cmds)
{
	while (cmds)
	{
		if (cmds->pipe_fd)
		{
			close(cmds->pipe_fd[0]);
			close(cmds->pipe_fd[1]);
		}
		cmds = cmds->next;
	}
}
