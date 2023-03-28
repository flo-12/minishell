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

/*
Imitates the builtin function "env" of bash
Prints the current environment variables
*/
int	env(t_data *data)
{
	char	**tmp;

	if (!data->env)
		return (EXIT_FAILURE);
	tmp = data->env;
	while (*tmp)
	{
		printf("%s", *tmp);	// QUESTION: does env have the \n at the end of each string or do we have to add it in printf?
		tmp++;
	}
	return (EXIT_SUCCESS);
}
