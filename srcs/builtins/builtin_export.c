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

/*
Imitates the builtin function "export" of bash
Adds a new variable to env. Variable value starts after the
(first) =-sign
*/
int	builtin_export(t_data *data, cahr *var)
{
	// check if var != NULL
	// check if var has =-sign
	// check if var consists of characters that are not allowed in a variable (e.g. ?, /, ...)
	//	=> ERROR and return(EXIT_FAILURE)

	// If all checks passed, doublicate string and add at the end of data->env
	// return(EXIT_SUCCESS)
}
