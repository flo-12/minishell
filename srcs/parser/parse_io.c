/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_io.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:33:57 by mvomiero          #+#    #+#             */
/*   Updated: 2023/04/28 14:08:31 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* clear_old_infiles:
	if there is already a value for infile:
	if the value of fd is -1, returns false: the file has problem and that's the
	error that will be displayed. If not, frees the pointer and closes the fd to
	make space for the new one.
 */
static bool	clear_old_infiles(t_io_fds *io)
{
	if (io->infile)
	// enters just if infile is already set (if not is initialized == NULL)
	{
		if (io->fd_in == -1 || (io->outfile && io->fd_out == -1))
			return (false);
		free_pointer(io->infile);
		close(io->fd_in);
	}
	else if (io->outfile)
	{
		if (io->fd_out == -1 || (io->infile && io->fd_in == -1))
			return (false);
		free_pointer(io->outfile);
		close(io->fd_out);
	}
	return (true);
}

/* open_infile:
	the clear_old_infile() function first checks if there are old infiles and 
	deletes them. the infile in the struct is set as the value of the string
	of the token. if the strinf is empty, then is an error.
	the file is then opened and the corresponding value issaved in fd_in.
 */
static void	open_infile(t_io_fds *io, char *infile, int fd, char *file, char c)
{
	if (!clear_old_infiles(io))
	//if (!remove_old_file_ref(io, true))
		return ;
	io->infile = ft_strdup(file);
/* 	// should be safe to remove this condition, handled in the next one
	if (io->infile && io->infile[0] == '\0')
	{
		ft_putendl_fd("minishell: : No such file or directory\n", 2);
		return ;
	} */
	if (c == 'i')
		io->fd_in = open(io->infile, O_RDONLY);
	if (io->fd_in == -1)
		err_msg(io->infile, strerror(errno), NULL);

		//errmsg_cmd(io->infile, NULL, strerror(errno), false);
		// MV : I'll have to set the errors better then ft_putendl
		// you have to use strerror, to get for example if the file is not 
		// existing
		//ft_putendl_fd("minishell: Error opening file descriptor\n", 2);
}

/* parse_input:
	after setting the temp iterator and getting the last command, the io struct
	is initialized. if the next node is a space, jumps directly to the following
	node. The infile is opened, then sets the token list pointing to temp
 */
void	parse_input(t_command **last_cmd, t_token **token_lst, char c)
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
	//open_infile(cmd->io_fds, temp->str, c);
	open_infile(cmd->io_fds, &cmd->io_fds->infile, &cmd->io_fds->fd_in, temp->str, c);
	temp = temp->next;
	*token_lst = temp;
}