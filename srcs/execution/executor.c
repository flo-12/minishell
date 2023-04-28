/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 18:11:25 by mvomiero          #+#    #+#             */
/*   Updated: 2023/04/28 11:34:30 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* wait_children:
	waits for the created children processes.
	- wpid stores the return value of wait(), which is the pid of the terminated 
		child
	- wstatus is an integer that stores information about about the ended 
		chil process. It can be inspected with macros in order to get the exit 
		status of ended process, which will be stored in endstatus.
	
	The function first has to close the pipes opened in the main process.
	In the first part of the function, an infinite loop calls wait until the
	value resulting form wait is equal to the result of the first forking call,
	so until the pid of the process waited for does correspond to the first 
	child. If the loop is not stopped at this condition, another call of wait 
	would result in a -1, which will result in en err_msg.

	In the second part of the function, the status of wait() is analyzed in
	order to get the corresponding exit code of the ended process.
	This will be the return value of the function
	-- for more info, see man 2 wait. Here shortly:
	WIFSIGNALED -> child terminated by a signal(see Notion for more infos)
	WIFEXITED -> child terminated normally
 */
static int	wait_children(t_data *data)
{
	pid_t	wpid;
	int		wstatus;
	int		endstatus;

	wstatus = 0;
	wpid = 0;
	close_pipes(data->cmd);
	while (1)
	{
		wpid = wait(&wstatus);
		if (wpid == -1)
			return (err_msg("wait error", strerror(errno), NULL), EXIT_FAILURE);
		//printf("^---pid wait %d -- status %d-- %d\n", data->pid, wstatus, wpid);
		if (wpid == data->pid)
			break ;
		continue ;
	}
	if (WIFSIGNALED(wstatus))
		endstatus = 128 + WTERMSIG(wstatus);
	else if (WIFEXITED(wstatus))
		endstatus = WEXITSTATUS(wstatus);
	else
		endstatus = wstatus;
	//printf("final status is %d\n", endstatus);
	return (endstatus);
}

/* create_children:
	creates children processes in order to execute the different commands.
	All the processes created are children of the main process (in the while 
	loop is the the stopping condition that pid != 0, so the main process will
	be forked as long as there are commands).
	if the pid == 0, it means it's a child process and so the execute_command()
	function is called.
 */
static int	create_children(t_data *data)
{
	t_command	*cmd;

	cmd = data->cmd;
	while (data->pid != 0 && cmd)
	{
		data->pid = fork();
		if (data->pid == -1)
			return (err_msg("fork error", strerror(errno), NULL), EXIT_FAILURE);
		else if (data->pid == 0)
			execute_command(data, cmd);
		cmd = cmd->next;
	}
	return wait_children(data);
}

/* executor:
	first two if conditions to check if the command list is not created and if 
	there is not not the command (second condition), it's for the case where a 
	redirection is set but no command is given as input.
	general distributor function:
	- the pipes are created;
	- children processes are created, and the execute_command function is called
	- the system waits for all the children to be finished and collects
		the exit code of the last process executed, which will then be returned
		from this function as well and assigned to the last_exit_code global
		variable
	in case of error, EXIT_FAILURE is returned.
 */
int	executor(t_data *data)
{
	int	ret;

	if (!data || !data->cmd)
		return (EXIT_FAILURE);
	if (!data->cmd->command)
		return (EXIT_SUCCESS);
	if (!data->cmd->pipe_output && !data->cmd->prev
		&& check_infile_outfile(data->cmd->io_fds))
	{
		redirect_io(data->cmd->io_fds);
		ret = execute_builtin(data, data->cmd);
		restore_io(data->cmd->io_fds);
		if (ret != CMD_NOT_FOUND)
			return (ret);
	}
	if (!create_pipes(data))
		return (EXIT_FAILURE);
	return (create_children(data));
}

/* int	execute(t_data *data)
{
	int	ret;

	ret = prep_for_exec(data);
	if (ret != CMD_NOT_FOUND)
		return (ret);
	if (!data->cmd->pipe_output && !data->cmd->prev
		&& check_infile_outfile(data->cmd->io_fds))
	{
		redirect_io(data->cmd->io_fds);
		ret = execute_builtin(data, data->cmd);
		restore_io(data->cmd->io_fds);
	}
	if (ret != CMD_NOT_FOUND)
		return (ret);
	return (create_children(data));
} */
