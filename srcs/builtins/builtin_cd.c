/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:35:50 by fbecht            #+#    #+#             */
/*   Updated: 2023/04/17 10:35:53 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "minishell.h"
#include "../../includes/minishell_flo.h"

/*
* Update working directory and old working directory in env-variables
* and the data struct.
*/
void	update_wds(t_data *data, char *cwd)
{
	char	*tmp;

	if (get_env_var_i(data->env, "OLDPWD=") >= 0)
	{
		if (get_env_var_i(data->env, "PWD=") >= 0)
			tmp = ft_strjoin("OLDPWD",
					strchr(data->env[get_env_var_i(data->env, "PWD=")], '='));
		else
			tmp = ft_strjoin("OLDPWD=", "");
		if (!tmp)
			return ;
		set_env_var(data, tmp);
		free(tmp);
	}
	if (get_env_var_i(data->env, "PWD=") >= 0)
	{
		tmp = ft_strjoin("PWD=", cwd);
		if (!tmp)
			return ;
		set_env_var(data, tmp);
		free(tmp);
	}
	free(data->old_working_dir);
	data->old_working_dir = data->working_dir;
	data->working_dir = ft_strdup(cwd);
}

/*
* Changes the current working directory and updates the 
* env-var OLDPWD and PWD
*	Return EXIT_SUCCESS on success and EXIT_FAILURE on failure
*/
int	change_dir(t_data *data, char *path)
{
	char	cwd[PATH_MAX];
	char	*tmp;

	if (chdir(path) != 0)
		return (err_msg("cd", path, strerror(errno)), EXIT_FAILURE);
	tmp = getcwd(cwd, PATH_MAX);
	update_wds(data, cwd);
	return (EXIT_SUCCESS);
}

/*
* check if args refers to changing to home directory
*	yes -> return path to home
*	no  -> return NULL
*/
char	*check_dir_to_home(char **env, char **args)
{
	int		i;
	_Bool	home;

	home = false;
	if (!args || !args[0])
		home = true;
	else if (args[0][0] == '\0' || ft_strncmp(args[0], "--", 3) == 0)
		home = true;
	if (!home)
		return (NULL);
	i = get_env_var_i(env, "HOME=");
	if (i < 0)
		return (err_msg("cd", "HOME not set", NULL), NULL);
	return (ft_strchr(env[i], '=') + 1);
}

/*
* Imitates the builtin function "cd" of bash
*	change the working directory and store the old working
*	error (cd: <Input>: No such file or directory) if dir doesn't exist
*		and "cd: too many arguments" if more than one arguments
*	absolute path:
*			- must start with '/'
*			- can but doesn't have to end with '/'
*	relative path:
*			- can but don't have to start with '\' or '/'
*			- can but doesn't have to end with '/'
*			- interpret '..' as one directory up
*			- don't do anything if only "." is inserted
*	arg == 
*			'--' -> change working directory to <HOME> (from env)
*			'-'  -> change to previous directory
*	no arguments: change working directory to <HOME> (from env)
*/
int	builtin_cd(t_data *data, char **args)
{
	char	*path;
	int		i;

	path = check_dir_to_home(data->env, args);
	if (path)
		return (change_dir(data, path));
	else if (get_size_ptr(args) > 1)
	{
		err_msg("cd", "too many arguments", NULL);
		return (EXIT_FAILURE);
	}
	if (!strncmp(args[0], "-", 2))
	{
		i = get_env_var_i(data->env, "OLDPWD=");
		if (i < 0)
		{
			err_msg("cd", "OLDPWD not set", NULL);
			return (EXIT_FAILURE);
		}
		else
			return (change_dir(data, ft_strchr(data->env[i], '=') + 1));
	}
	return (change_dir(data, args[0]));
}
