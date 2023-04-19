/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:15:23 by mvomiero          #+#    #+#             */
/*   Updated: 2023/04/19 13:31:24 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* int	execute_command(t_data *data, t_command *cmd)
{
	int	ret;

	if (!check_infile_outfile(cmd->io_fds))
		exit_shell(data, EXIT_FAILURE);
	set_pipe_fds(data->cmd, cmd);
	redirect_io(cmd->io_fds);
	close_fds(data->cmd, false);
	if (ft_strchr(cmd->command, '/') == NULL)
	{
		ret = execute_builtin(data, cmd);
		if (ret != CMD_NOT_FOUND)
			exit_shell(data, ret);
		ret = execute_sys_bin(data, cmd);
		if (ret != CMD_NOT_FOUND)
			exit_shell(data, ret);
	}
	ret = execute_local_bin(data, cmd);
	exit_shell(data, ret);
	return (ret);
} */

