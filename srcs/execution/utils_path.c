/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:45:05 by mvomiero          #+#    #+#             */
/*   Updated: 2023/04/21 15:25:58 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	cmd_is_dir(char *cmd)
{
	struct stat	cmd_stat;

	ft_memset(&cmd_stat, 0, sizeof(cmd_stat));
	stat(cmd, &cmd_stat);
	return (S_ISDIR(cmd_stat.st_mode));
}


int	check_command_not_found(t_command *cmd)
{
	if (access(cmd->command, F_OK) != 0)
		return (err_msg(cmd->command, strerror(errno), NULL), CMD_NOT_FOUND);
	else if (cmd_is_dir(cmd->command))
		return (err_msg(cmd->command, "Is a directory", NULL), CMD_NOT_EXEC);
	else if (access(cmd->command, F_OK | X_OK) != 0)
		return (err_msg(cmd->command, strerror(errno), NULL), CMD_NOT_EXEC);
	return (EXIT_SUCCESS);
}

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (NULL);
}