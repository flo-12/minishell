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

void	free_ptr(char **ptr)
{
	if (!ptr)
		return ;
	while (*ptr)
	{
		free(*ptr);
		ptr++;
	}
	free(ptr);
}

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
