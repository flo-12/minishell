/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:06:54 by fbecht            #+#    #+#             */
/*   Updated: 2023/03/28 19:08:48 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "minishell.h"
#include "../../includes/minishell_flo.h"

/*
* Trigger printing of error message for function check_env_var
*/
_Bool	check_env_var_err(char *s1, char *s2, char *s3)
{
	err_msg(s1, s2, s3);
	return (false);
}

/*
* Check if str follows the rules of env-variables
*	Return:	true -> all strs follow rules
*			false -> at least one str doesn't follow rules
*	Rules:
*		1) has at least one '=' sign
*		2) str starts with alphabetic char
*		3) variable name (everyhting before first '=' sign)
*			consists only alphanumeric chars or '_'
*		4) variable value doesn't contain '(' or ')'
*/
_Bool	check_env_var(char *str)
{
	int	i;

	i = 0;
	if (!ft_isalpha(str[i]))
		return (check_env_var_err("export", str, BUILTIN_ERR_IDENT));
	while (str[i] != '=')
	{
		if (!ft_isalnum(str[i]))
			return (check_env_var_err("export", str, BUILTIN_ERR_IDENT));
		i++;
	}
	while (str[i])
	{
		if (str[i] == '(' || str[i] == ')')
			return (check_env_var_err("export", str, BUILTIN_ERR_IDENT));
		i++;
	}
	return (true);
}

/*
* Find and return index of matching variables
*	return -1 if index is not found
*/
int	get_env_var_i(char **env, char *str)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], str, strrchr(str, '=') - str))
			return (i);
		i++;
	}
	return (-1);
}

/*
* Set an environment variable
*	Replace existing variable if the variable in env is equal
*	Add new variable env to data->env if it doesn't exist
*/
void	set_env_var(t_data *data, char *env)
{
	int		i;
	char	**tmp;

	i = get_env_var_i(data->env, env);
	if (i != -1)
	{
		free(data->env[i]);
		data->env[i] = ft_strdup(env);
	}
	else
	{
		tmp = data->env;
		data->env = (char **)malloc(sizeof(char *) * (get_size_ptr(tmp) + 2));
		if (!data->env)
		{
			data->env = tmp;
			return ;
		}
		cpy_ptrs(data->env, tmp);
		data->env[get_size_ptr(tmp)] = ft_strdup(env);
		data->env[get_size_ptr(tmp) + 1] = NULL;
		free(tmp);
	}
}

/*
* Imitates the builtin function "export" of bash
* Adds a new variable to env. Variable value starts after the
* (first) =-sign
*/
int	builtin_export(t_data *data, char **args)
{
	int		i;

	if (!args)
		return (builtin_env(data));
	if (!(*args))
		return (builtin_env(data));
	i = 0;
	while (args[i])
	{
		if (!check_env_var(args[i]))
			return (EXIT_FAILURE);
		else
			set_env_var(data, args[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}
