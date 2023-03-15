/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_expansion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:41:37 by fbecht            #+#    #+#             */
/*   Updated: 2023/03/15 12:41:39 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Parses through each string in usr_split and replaces
variables with its values.
	variable: $<VAR_NAME>
Variables are only allowed from env. If the variable
is not found, starting from the $-sign everything will
be deleted. If the string is empty afterwards, it is
freed and the pointer removed.
$-signs in singles quotes ('') are ignored.
*/
void	var_expansion(char **usr_split, char **env)
{

}
