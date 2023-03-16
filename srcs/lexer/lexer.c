/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:47:01 by fbecht            #+#    #+#             */
/*   Updated: 2023/03/14 17:47:04 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

_bool	is_spaces(char *str)
{
	while (*str)
	{
		if (*str != ' ')
			return (false);
		str++;
	}
	return (true);
}

int	get_i_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	return (i);
}

/*
Triggers all sub-functions to split the user input into
words and tokens (including characterization of the token)
and stores the result in the struct s_token.
*/
_bool	lexer(t_data *data)
{
	char	**usr_split;

	if (data == NULL)
		return (false);
	if (*data == '\0' || is_spaces(data))
		return (false);
	usr_split = split_usr_input(data->usr_input + get_i_spaces(data->usr_input));
	if (!usr_split)
		return (false);
	var_expansion(usr_split, data->env);	// returning usr_split??
	data->token	= init_t_token(char **usr_split);
	tokenization(data->token);
	free(usr_split);	// <-- free each string and at the end the pointer
}
