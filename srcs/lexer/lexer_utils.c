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

//#include "minishell.h"

#include "../../includes/minishell_flo.h"

/*
Free each string of a pointer, pointing to several strings
At the end, free the pointer
*/
void	free_ptr(char **ptr)
{
	char	**tmp;

	tmp = ptr;
	if (!ptr)
		return ;
	while (*ptr)
	{
		free(*ptr);
		ptr++;
	}
	free(tmp);
}

/*
get the number of strings in a ptr to strings
*/
int	get_size_ptr(char **ptr)
{
	int	i;

	i = 0;
	if (!ptr)
		return (i);
	while (ptr[i])
		i++;
	return (i);
}

/*
copy each str-ptr of a ptr to an other ptr
*/
void	cpy_ptrs(char **dst, char **src)
{
	if (!src)
		return ;
	while (*src)
	{
		*dst = *src;
		dst++;
		src++;
	}
}

/*
Finds and returns the consecutive number of spaces
at the beginning of the string
*/
int	get_nbr_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	return (i);
}
