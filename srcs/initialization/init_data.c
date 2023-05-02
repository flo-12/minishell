/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:20:26 by mvomiero          #+#    #+#             */
/*   Updated: 2023/05/02 12:02:47 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	env_var_count(char **env)
{
	int	i;

	i = 0;
	while (env && env[i])
		i++;
	return (i);
}

static bool	init_env(t_data *data, char **env)
{
	int	i;

	data->env = ft_calloc(env_var_count(env) + 1, sizeof * data->env);
	if (!data->env)
		return (false);
	i = 0;
	while (env[i])
	{
		data->env[i] = ft_strdup(env[i]);
		if (!data->env[i])
			return (false);
		i++;
	}
	return (true);
}

static bool	init_wds(t_data *data, char **env)
{
	while (*env)
	{
		if (ft_strncmp(*env, "PWD=", ft_strlen("PWD=")) == 0)
			data->working_dir = ft_strdup(ft_strchr(*env, '=') + 1);
		else if (ft_strncmp(*env, "OLDPWD=", ft_strlen("OLDPWD=")) == 0)
			data->old_working_dir = ft_strdup(ft_strchr(*env, '=') + 1);
		env++;
	}
	if (!data->working_dir || !data->old_working_dir)
		return (false);
	return (true);
}

bool	init_data(t_data *data, char **env)
{
	if (!init_env(data, env))
		return (ft_putendl_fd("Could not initalize environment!", 2), false);
	if (!init_wds(data, env))
		return (ft_putendl_fd("Could not initalize working directories!", 2),
			false);
	data->token = NULL;
	data->user_input = NULL;
	data->cmd = NULL;
	data->pid = -1;
	g_last_exit_code = 0;
	return (true);
}

void	init_io(t_command *cmd)
{
	if (!cmd->io_fds)
	{
		cmd->io_fds = malloc(sizeof * cmd->io_fds);
		if (!cmd->io_fds)
			return ;
		cmd->io_fds->infile = NULL;
		cmd->io_fds->outfile = NULL;
		cmd->io_fds->heredoc_delimiter = NULL;
		cmd->io_fds->fd_in = -1;
		cmd->io_fds->fd_out = -1;
		cmd->io_fds->stdin_backup = -1;
		cmd->io_fds->stdout_backup = -1;
	}
}
