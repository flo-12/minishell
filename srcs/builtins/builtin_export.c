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

#include "minishell.h"
//#include "../../includes/minishell_flo.h"

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
	int		len;
	char	*env_name;

	if (ft_strchr(str, '='))
		len = ft_strchr(str, '=') - str;
	else
		len = ft_strlen(str);
	env_name = (char *)malloc(sizeof(char) * (len + 1));
	if (!env_name)
		return (err_msg("export", "malloc error", NULL), false);
	ft_strlcpy(env_name, str, len + 1);
	if (valid_env_var_name(env_name))
		return (true);
	else
		return (err_msg("export", str, BUILTIN_ERR_IDENT), false);
	/*i = 0;
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
	}*/
	//return (true);
}

/*
* Imitates the builtin function "export" of bash
* Adds a new variable to env. Variable value starts after the
* (first) =-sign
*/
int	builtin_export(t_data *data, char **args)
{
	int		i;
	int		exit_code;

	if (!args || !(*args))
		return (builtin_env(data));
	exit_code = EXIT_SUCCESS;
	i = 0;
	while (args[i])
	{
		if (!check_env_var(args[i]))
			exit_code = EXIT_FAILURE;
		else
			set_env_var(data, args[i]);
		i++;
	}
	return (exit_code);
}
