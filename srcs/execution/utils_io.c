/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_io.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:27:19 by mvomiero          #+#    #+#             */
/*   Updated: 2023/04/20 17:00:33 by mvomiero         ###   ########.fr       */
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