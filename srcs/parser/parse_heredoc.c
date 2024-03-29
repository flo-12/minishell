/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:45:30 by mvomiero          #+#    #+#             */
/*   Updated: 2023/05/02 17:25:41 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* generate_geredoc:
	creates a file where is stored the input, thanks the fill_heredoc() function
	
	TO REMOVE HEREDOC: use the unlink() function -> removes a file, parameter is
	the path of the file.
 */
bool	generate_heredoc(t_io_fds *io)
{
	int		tmp_fd;
	bool	ret;

	ret = true;
	tmp_fd = open(io->infile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	ret = fill_heredoc(io, tmp_fd);
	close(tmp_fd);
	return (ret);
}

static bool	heredoc_line_check(char **line, t_io_fds *io, int *nb, bool *ret)
{
	if (*line == NULL)
	{
		printf("minishell: warning: here-document at line %d delimited by \
end-of-file (wanted `%s')\n", *nb, io->heredoc_delimiter);
		*ret = false;
		return (false);
	}
	if (ft_strncmp(*line, io->heredoc_delimiter,
			ft_strlen(io->heredoc_delimiter) + 1) == 0)
	{
		*ret = true;
		return (false);
	}
	return (true);
}

/* fill_heredoc:
	reads the input thanks the redline() function until the line is equal to the
	delimiter.
 */
bool	fill_heredoc(t_io_fds *io, int fd)
{
	char	*line;
	bool	ret;
	int		nb_line;

	nb_line = 0;
	ret = false;
	line = NULL;
	while (1)
	{
		signal_interactive();
		line = readline(PROMPT_HEREDOC);
		signal_non_interactive();
		if (!heredoc_line_check(&line, io, &nb_line, &ret))
			break ;
		ft_putendl_fd(line, fd);
		free_pointer(line);
		nb_line++;
	}
	free_pointer(line);
	return (ret);
}

/* 
	creates a name for the heredoc file. It will be a hidden file in the /temp
	folder. the static variable guarantees to have successive numbers.
 */
static char	*generate_heredoc_name(void)
{
	static int	i;
	char		*name;
	char		*number;

	number = ft_itoa(i);
	if (!number)
		return (NULL);
	name = ft_strjoin(HEREDOC_NAME, number);
	free(number);
	i++;
	return (name);
}

/* parse_heredoc:
	similar structure to the function that parses the input. a t_fds_io is set
	just to more practically iterate and call the different functions (if not
	is necessary every time to write cmd->io_fds->infile for example).
	After setting the iterators and checking for existing old files, and
	jump to the next token in the token list (or skipping a space if there is 
	one), a name is created for a file that will be the heredoc.
	The generate_heredoc() function is called to create the heredoc file and 
	fill it with the input of the user. If the function is successful, it will
	return true, else the fd has a problem and is set to -1.
	
 */
void	parse_heredoc(t_command **last_cmd, t_token **token_lst)
{
	t_token		*temp;
	t_command	*cmd;
	t_io_fds	*io;

	temp = *token_lst;
	cmd = cmd_lst_get_end(*last_cmd);
	init_io(cmd);
	io = cmd->io_fds;
	if (!clear_old_infiles_heredoc(io))
		return ;
	if (temp->next->type == SPACES)
		temp = temp->next->next;
	else
		temp = temp->next;
	*token_lst = temp;
	io->heredoc_delimiter = temp->str;
	io->infile = generate_heredoc_name();
	if (generate_heredoc(io))
	{
		io->fd_in = open(io->infile, O_RDONLY);
	}
	else
		io->fd_in = -1;
	temp = temp->next;
	*token_lst = temp;
}
