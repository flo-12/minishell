/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 18:11:25 by mvomiero          #+#    #+#             */
/*   Updated: 2023/04/18 19:24:03 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	wait_children(t_data *data)
{
	pid_t	wpid;
	int		wstatus;
	int		endstatus;

	wstatus = 0;
	wpid = 0;
	while (1)
	{
		wpid = wait(&wstatus);
		if (wpid == -1)
			return (err_msg("wait error", strerror(errno), NULL), EXIT_FAILURE);
		//return (errmsg_cmd("wait", NULL, strerror(errno), EXIT_FAILURE));
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
			;
			//execute_command(data, cmd);
		cmd = cmd->next;
	}
	return (0);
}

int	execute(t_data *data)
{
	int	ret;
	
	//if (!create_pipes(data))
	//	return (EXIT_FAILURE);
	if (!create_children(data))
		return (EXIT_FAILURE);
	// to delete
	//close_fds(data->cmd, false);
	ret = wait_children(data);
	return (ret);
}