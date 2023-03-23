/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:58:41 by mvomiero          #+#    #+#             */
/*   Updated: 2023/03/23 19:28:01 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* 
	same as parse_input, but for the output and different parameters for the 
	opening of the file descriptor
 */
static bool	clear_old_outfiles(t_io_fds *io)
{
	if (io->outfile)
	{
		if (io->fd_out == -1 || (io->infile && io->fd_in == -1))
			return (false);
		free_pointer(io->outfile);
		close(io->fd_out);
	}
	return (true);
}

/* 
	same as parse_input, but for the output and different parameters for the 
	opening of the file descriptor
 */
static void	open_outfile(t_io_fds *io, char *file, char c)
{
	if (!clear_old_outfiles(io))
	//if (!remove_old_file_ref(io, true))
		return ;
	io->outfile = ft_strdup(file);
	if (io->outfile && io->outfile[0] == '\0')
	{
		ft_putendl_fd("minishell: : No such file or directory\n", 2);
		return ;
	}
	if (c == 't')
		io->fd_out = open(io->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	else if (c == 'a')
		io->fd_out = open(io->outfile, O_WRONLY | O_CREAT | O_APPEND, 0664);
	if (io->fd_out == -1)
		//errmsg_cmd(io->outfile, NULL, strerror(errno), false);
		// MV : I'll have to set the errors better then ft_putendl
		// you have to use strerror, to get for example if the file is not 
		// existing
		ft_putendl_fd("minishell: Error opening file descriptor\n", 2);
}

/* 
	same as parse_input, but for the output and different parameters for the 
	opening of the file descriptor
 */
void	parse_output(t_command **last_cmd, t_token **token_lst, char c)
{
	t_token		*temp;
	t_command	*cmd;

	temp = *token_lst;
	cmd = cmd_lst_get_end(*last_cmd);
	init_io(cmd);
	if (temp->next->type == SPACES)
		temp = temp->next->next;
	else
		temp = temp->next;
	open_outfile(cmd->io_fds, temp->str, c);
	temp = temp->next;
	*token_lst = temp;
}
