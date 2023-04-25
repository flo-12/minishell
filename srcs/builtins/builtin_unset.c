/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:20:05 by fbecht            #+#    #+#             */
/*   Updated: 2023/04/19 15:20:08 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
//#include "../../includes/minishell_flo.h"

/*
* Remove (and free) the environment variable var of
* the set in data->env.
* Precondition: var exists in data->env
*/
void	unset_env_var(t_data *data, char *var)
{
	int		i;
	char	**tmp;

	i = get_env_var_i(data->env, var);
	tmp = (char **)malloc(sizeof(char *) * get_size_ptr(data->env));
	if (!tmp)
		return ;
	tmp[get_size_ptr(data->env) - 1] = NULL;
	free(data->env[i]);
	data->env[i] = NULL;
	cpy_ptrs(tmp, data->env);
	cpy_ptrs(tmp + i, data->env + i + 1);
	free(data->env);
	data->env = tmp;
}

/*
* Imitates the builtin function "unset" of bash
* Removes variable from env. Doesn't display anything
* if variable doesn't exist.
*/
int	builtin_unset(t_data *data, char **args)
{
	char	*tmp;
	int		i;

	if (!args)
		return (EXIT_SUCCESS);
	while (*args)
	{
		tmp = ft_strjoin(*args, "=");
		i = get_env_var_i(data->env, tmp);
		if (i != -1)
		{
			if ((data->env[i] - ft_strchr(data->env[i], '=')) * (-1)
				== (long int)ft_strlen(*args))
				unset_env_var(data, tmp);
		}
		free(tmp);
		args++;
	}
	return (EXIT_SUCCESS);
}
