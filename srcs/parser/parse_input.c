/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:19:18 by mvomiero          #+#    #+#             */
/*   Updated: 2023/04/28 17:25:26 by mvomiero         ###   ########.fr       */
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
	{
		if (io->fd_in == -1 || (io->outfile && io->fd_out == -1))
			return (false);
		free_pointer(io->infile);
		close(io->fd_in);
	}
	return (true);
}

/* open_infile:
	the clear_old_infile() function first checks if there are old infiles and 
	deletes them. the infile in the struct is set as the value of the string
	of the token. if the string is empty, then is an error.
	the file is then opened and the corresponding value issaved in fd_in.
 */
static void	open_infile(t_io_fds *io, char *file)
{
	if (!clear_old_infiles(io))
		return ;
	io->infile = ft_strdup(file);
	io->fd_in = open(io->infile, O_RDONLY);
	if (io->fd_in == -1)
		err_msg(io->infile, strerror(errno), NULL);
}

/* parse_input:
	after setting the temp iterator and getting the last command, the io struct
	is initialized. if the next node is a space, jumps directly to the following
	node. The infile is opened, then sets the token list pointing to temp
 */
void	parse_input(t_command **last_cmd, t_token **token_lst)
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
	open_infile(cmd->io_fds, temp->str);
	temp = temp->next;
	*token_lst = temp;
}

/*	
	//was having this condition before but i dont actually need it 
	if (io->infile && io->infile[0] == '\0')
		err_msg(io->infile, strerror(errno));
 	{
		ft_putendl_fd("minishell: : No such file or directory\n", 2);
		return ;
	} */