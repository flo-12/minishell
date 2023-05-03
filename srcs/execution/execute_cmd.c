/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:15:23 by mvomiero          #+#    #+#             */
/*   Updated: 2023/04/28 17:45:38 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_builtin(t_data *data, t_command *cmd)
{
	int	ret;

	ret = CMD_NOT_FOUND;
	if (ft_strncmp(cmd->command, "cd", 3) == 0)
		ret = builtin_cd(data, cmd->args + 1);
	else if (ft_strncmp(cmd->command, "echo", 5) == 0)
		ret = builtin_echo(data, cmd->args + 1);
	else if (ft_strncmp(cmd->command, "env", 4) == 0)
		ret = builtin_env(data);
	else if (ft_strncmp(cmd->command, "export", 7) == 0)
		ret = builtin_export(data, cmd->args + 1);
	else if (ft_strncmp(cmd->command, "pwd", 4) == 0)
		ret = builtin_pwd(data);
	else if (ft_strncmp(cmd->command, "unset", 6) == 0)
		ret = builtin_unset(data, cmd->args + 1);
	else if (ft_strncmp(cmd->command, "exit", 5) == 0)
		ret = builtin_exit(data, cmd->args + 1);
	return (ret);
}

static int	execute_sys_cmd(t_data *data, t_command *cmd)
{
	if (cmd->command[0] == '\0' && get_env_var_i(data->env, "PATH=") == -1)
		return (err_msg(cmd->command, "No such file or directory", NULL),
			CMD_NOT_FOUND);
	if (!cmd->command || cmd->command[0] == '\0'
		|| !ft_strncmp(cmd->command, "..", 3))
		return (err_msg(cmd->command, "command not found", NULL),
			CMD_NOT_FOUND);
	else if (!ft_strncmp(cmd->command, ".", 2))
		return (err_msg(cmd->command, "filename argument required", NULL), 2);
	cmd->path = find_path(cmd->command, data->env);
	if (!cmd->path && get_env_var_i(data->env, "PATH=") == -1)
		return (err_msg(cmd->command, "No such file or directory", NULL),
			CMD_NOT_FOUND);
	else if (!cmd->path)
		return (err_msg(cmd->command, "command not found", NULL),
			CMD_NOT_FOUND);
	if (execve(cmd->path, cmd->args, data->env) == -1)
		return (err_msg("execve error", strerror(errno), NULL), errno);
	return (EXIT_FAILURE);
}

/* execute_local_cmd:
	checks if the command is not found, non executable or a directory.
	It is needed to do this check before if not the error will be counted as an
	execve error.
	After the check, execve is launched with the given path.
 */
static int	execute_local_cmd(t_data *data, t_command *cmd)
{
	int	ret;

	ret = check_command_not_found(cmd);
	if (ret != 0)
		return (ret);
	if (execve(cmd->command, cmd->args, data->env) == -1)
		return (err_msg("execve error", strerror(errno), NULL), errno);
	return (EXIT_FAILURE);
}

/* execute_command:
	Since when this function is executed we are in a child process (it is calld
	when pid == 0), every time we want to terminate the process we will have to
	use the exit_minishell() function and not the free_data() one.

	- checks if the infile and outfiles are correct or not set (no redirection)
		or if they have problems (fd == -1): in this case minishell is exited.
	- sets the pipes for pipe redirection
	- closes all the pipes, that were created in the main process and inherited
		from the chil process
	- redirects the io whith external files and then closes them.
		// ?? MV : should I actually close all the files, or do that in the main
		process at the end.. still have to look at that
	- if '/' is found, the function will just try to execute the given path
	- else, if the command if found among the builtins, the builtin will be 
		executed. In the case the command is not a builtin, the execute_sys_cmd
		function is called.
 */
int	execute_command(t_data *data, t_command *cmd)
{
	int	ret;

	expand_exit_code(cmd->args);
	if (!check_infile_outfile(cmd->io_fds))
		exit_minishell(data, EXIT_FAILURE);
	set_pipes(cmd);
	close_pipes(data->cmd);
	redirect_io(cmd->io_fds);
	if (ft_strchr(cmd->command, '/'))
	{
		ret = execute_local_cmd(data, cmd);
		exit_minishell(data, ret);
	}
	else
	{
		ret = execute_builtin(data, cmd);
		if (ret != CMD_NOT_FOUND)
			exit_minishell(data, ret);
		ret = execute_sys_cmd(data, cmd);
		exit_minishell(data, ret);
	}
	return (ret);
}
