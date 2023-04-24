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
		return (err_msg("export", str, BUILTIN_ERR_IDENT), false);
	while (str[i] != '=')
	{
		if (!ft_isalnum(str[i]))
			return (err_msg("export", str, BUILTIN_ERR_IDENT), false);
		i++;
	}
	while (str[i])
	{
		if (str[i] == '(' || str[i] == ')')
			return (err_msg("export", str, BUILTIN_ERR_IDENT), false);
		i++;
	}
	return (true);
}

/*
* Imitates the builtin function "export" of bash
* Adds a new variable to env. Variable value starts after the
* (first) =-sign
*/
int	builtin_export(t_data *data, char **args)
{
	int		i;

	if (!args || !(*args))
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
