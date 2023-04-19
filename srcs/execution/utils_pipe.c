/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:42:55 by mvomiero          #+#    #+#             */
/*   Updated: 2023/04/19 13:04:43 by mvomiero         ###   ########.fr       */
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