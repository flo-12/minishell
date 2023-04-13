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

/*
* Trigger printing of error message for function check_env_var
*/
_Bool	check_env_var_err(char *s1, char *s2, char *s3)
{
	err_msg(s1, s2, s3);
	return (false);
}

/*
* Check if each str in vars follows the rules of env-variables
*	Return:	true -> all strs follow rules
*			false -> at least one str doesn't follow rules
*	Rules:
*		1) has at least one '=' sign
*		2) str starts with alphabetic char
*		3) variable name (everyhting before first '=' sign)
*			consists only alphanumeric chars or '_'
*		4) variable value doesn't contain '(' or ')'
*/
_Bool	check_env_var(char **vars)
{
	int	i;

	if (!vars)
		return (false);
	while (vars)
	{
		i = 0;
		if (!ft_isalpha((*vars)[i]))
			return (check_env_var_err("export", *vars, BUILTIN_ERR_IDENT));
		while ((*vars)[i] != '=')
		{
			if (!ft_isalnum((*vars)[i]))
				return (check_env_var_err("export", *vars, BUILTIN_ERR_IDENT));
			i++;
		}
		while ((*vars)[i])
		{
			if ((*vars)[i] == '(' || (*vars)[i] == ')')
				return (check_env_var_err("export", *vars, BUILTIN_ERR_IDENT));
			i++;
		}
		vars++;
	}
	return (true);
}
