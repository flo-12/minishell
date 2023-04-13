/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:49:01 by fbecht            #+#    #+#             */
/*   Updated: 2023/03/28 19:50:48 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "minishell.h"
#include "../../includes/minishell_flo.h"

/*
* Imitates the builtin function "env" of bash
*	prints the current environment variables
*	additionally add new variables in args
*		error if at least one args doesn't
*		follow the rules for new env-variables
*/
int	builtin_env(t_data *data, char **args)
{
	char	i;

	if (args)
	{
		if (check_env_var(args))
			builtin_export(data, args);
		else
			return (EXIT_FAILURE);
	}
	if (!data->env)
		return (EXIT_SUCCESS);
	i = 0;
	while (data->env[i])
	{
		printf("%s\n", data->env[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}
