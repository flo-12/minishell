/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_io.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:27:19 by mvomiero          #+#    #+#             */
/*   Updated: 2023/04/28 17:40:55 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	check_infile_outfile(t_io_fds *io)
{
	if (!io || (!io->infile && !io->outfile))
		return (true);
	if ((io->infile && io->fd_in == -1)
		|| (io->outfile && io->fd_out == -1))
		return (false);
	return (true);
}

void	redirect_io(t_io_fds *io)
{
	if (!io)
		return ;
	io->stdin_backup = dup(STDIN_FILENO);
	close(io->stdin_backup);
	io->stdout_backup = dup(STDOUT_FILENO);
	close(io->stdout_backup);
	if (io->fd_in != -1)
	{
		dup2(io->fd_in, STDIN_FILENO);
		close(io->fd_in);
	}
	if (io->fd_out != -1)
	{
		dup2(io->fd_out, STDOUT_FILENO);
		close(io->fd_out);
	}
}

bool	restore_io(t_io_fds *io)
{
	int	ret;

	ret = true;
	if (!io)
		return (ret);
	if (io->stdin_backup != -1)
	{
		if (dup2(io->stdin_backup, STDIN_FILENO) == -1)
			ret = false;
		close(io->stdin_backup);
		io->stdin_backup = -1;
	}
	if (io->stdout_backup != -1)
	{
		if (dup2(io->stdout_backup, STDOUT_FILENO) == -1)
			ret = false;
		close(io->stdout_backup);
		io->stdout_backup = -1;
	}
	return (ret);
}
