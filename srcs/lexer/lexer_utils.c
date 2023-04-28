/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:23:53 by fbecht            #+#    #+#             */
/*   Updated: 2023/03/15 17:23:56 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//#include "../../includes/minishell_flo.h"

/*
Finds and returns the consecutive number of spaces
at the beginning of the string
*/
int	get_nbr_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	return (i);
}
