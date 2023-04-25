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

#include "minishell.h"
//#include "../../includes/minishell_flo.h"

/*
* Imitates the builtin function "env" of bash
*	prints the current environment variables
*	no arguments (adding new variables) allowed
*/
int	builtin_env(t_data *data)
{
	char	i;

	if (!data->env)
		return (EXIT_FAILURE);
	i = 0;
	while (*(data->env + i))
		printf("%s\n", *(data->env + (i++)));
	return (EXIT_SUCCESS);
}
