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
Imitates the builtin function "export" of bash
Adds a new variable to env. Variable value starts after the
(first) =-sign
*/
int	builtin_export(t_data *data, char **args)
{
	int		i;
	char	**dup;

	if (!args)
		return (builtin_env(data, NULL));
	if (!(*args))
		return (builtin_env(data, NULL));
	if (!check_env_var(args))
		return (EXIT_FAILURE);
printf("ALL CHECKS PASSED, *args=%s\n", *args);
	dup = (char **)malloc(sizeof(char *) * (get_size_ptr(data->env)
				+ get_size_ptr(args) + 1));
	if (!dup)
		return (EXIT_FAILURE);
	cpy_ptrs(dup, data->env);
	i = 0;
	while (args[i])
	{
		*(dup + get_size_ptr(data->env) + i) = ft_strdup(args[i]);
		i++;
	}
	free(data->env);
	data->env = dup;
	return (EXIT_SUCCESS);
}
