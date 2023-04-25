/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:10:31 by fbecht            #+#    #+#             */
/*   Updated: 2023/04/13 17:10:33 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
//#include "../../includes/minishell_flo.h"

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
