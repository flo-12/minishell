/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_heredoc_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:22:46 by mvomiero          #+#    #+#             */
/*   Updated: 2023/05/02 17:24:49 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* 
	clears old infiles if there are some
 */
bool	clear_old_infiles_heredoc(t_io_fds *io)
{
	if (io->infile)
	{
		if (io->fd_in == -1 || (io->outfile && io->fd_out == -1))
			return (false);
		if (io->heredoc_delimiter != NULL)
		{
			free_pointer(io->heredoc_delimiter);
			io->heredoc_delimiter = NULL;
			unlink(io->infile);
		}
		free_pointer(io->infile);
		close(io->fd_in);
	}
	return (true);
}
