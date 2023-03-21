/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:41:29 by fbecht            #+#    #+#             */
/*   Updated: 2023/03/15 12:41:31 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "minishell.h"

#include "../../includes/minishell_flo.h"

/*
Initializes the double-linked list t_token with at least one
node for each string in usr_split and splitting the argument
into tokens - t_token.type - (from e_token_types) as followed:
	- SPACES: one ore more spaces (' ')
	- WORD: string which doesn't contain any other tokens
	- PIPE: '|'
	- INPUT: '<'
	- TRUNC: '>'
	- HEREDOC: '<<'
	- APPEND: '>>'
In case of word, the string is stored in str (plus copy in
str_backup). In all other cases, str and str_backup must be
NULL.
Return: double-linked list t_token (NULL in case of error)
Precondition: usr_split != NULL
*/
t_token	*tokenization(char **usr_split)
{
	t_token	*token;


	return (token);
}
