/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:15:23 by mvomiero          #+#    #+#             */
/*   Updated: 2023/04/20 17:58:53 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* static int	execute_builtin(t_data *data, t_command *cmd)
{
	int	ret;

	ret = CMD_NOT_FOUND;
	if (ft_strncmp(cmd->command, "cd", 3) == 0)
		ret = builtin_cd(data, cmd->args);
	else if (ft_strncmp(cmd->command, "echo", 5) == 0)
		ret = builtin_echo(data, cmd->args);
	else if (ft_strncmp(cmd->command, "env", 4) == 0)
		ret = builtin_env(data, cmd->args);
	else if (ft_strncmp(cmd->command, "export", 7) == 0)
		ret = builtin_export(data, cmd->args);
	else if (ft_strncmp(cmd->command, "pwd", 4) == 0)
		ret = builtin_pwd(data, cmd->args);
	else if (ft_strncmp(cmd->command, "unset", 6) == 0)
		ret = builtin_unset(data, cmd->args);
	else if (ft_strncmp(cmd->command, "exit", 5) == 0)
		ret = builtin_exit(data, cmd->args);
	return (ret);
} */

static int	execute_sys_bin(t_data *data, t_command *cmd)
{
	if (!cmd->command || cmd->command[0] == '\0')
		return (CMD_NOT_FOUND);
	if (cmd_is_dir(cmd->command))
		return (CMD_NOT_FOUND);
	cmd->path = find_path(cmd->command, data->env);
	//cmd->path = get_cmd_path(data, cmd->command);
	if (!cmd->path)
		return (CMD_NOT_FOUND);
	if (execve(cmd->path, cmd->args, data->env) == -1)
		return (err_msg("execve error", strerror(errno), NULL), errno);
	return (EXIT_FAILURE);
}

static int	execute_local_bin(t_data *data, t_command *cmd)
{
	int	ret;

	ret = check_command_not_found(cmd);
	if (ret != 0)
		return (ret);
	if (execve(cmd->command, cmd->args, data->env) == -1)
		return (err_msg("execve error", strerror(errno), NULL), errno);
	return (EXIT_FAILURE);
}

int	execute_command(t_data *data, t_command *cmd)
{
	int	ret;

	if (!check_infile_outfile(cmd->io_fds))
		exit_minishell(data, EXIT_FAILURE);
	// setting the necessary pipes redirections to IN and OUT
	set_pipes(cmd);
	// all the pipes are closed! remember, we are in a chil process so it means
	// in all the others they will still be opened
	close_pipes(data->cmd);
	// io redirection and direct closing of the fd
	redirect_io(cmd->io_fds);
	// Executing the path if '/' is found, if not looks for builtins and sys cmds
	if (ft_strchr(cmd->command, '/'))
	{
		ret = execute_local_bin(data, cmd);
		exit_minishell(data, ret);
	}
	else
	{
		//ret = execute_builtin(data, cmd);
		//if (ret != CMD_NOT_FOUND)
		//	exit_minishell(data, ret);
		ret = execute_sys_bin(data, cmd);
		if (ret != CMD_NOT_FOUND)
			exit_minishell(data, ret);
	}
	return (ret);
}

