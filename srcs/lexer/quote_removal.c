/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_removal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:21:11 by fbecht            #+#    #+#             */
/*   Updated: 2023/03/21 12:21:14 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "minishell.h"

#include "../../includes/minishell_flo.h"

/*
Copies the values of str at index 1:(end-1) - excludes
the quotes - to a NULL-terminated string tmp and frees
the argument str.
Return: new string tmp without quotes
Precondition: str starts and ends with quotes
*/
char	*remove_quotes(char *str)
{
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * (ft_strlen(str) - 1));
	if (!tmp)
		return (NULL);
	ft_strlcpy(tmp, str + 1, ft_strlen(str) - 1);
	free(str);
	return (tmp);
}

/*
Find and remove the starting and ending quotes of each
string in usr_split - if the string has any.
If the string only consists of quotes ("" or ''), the
result is an empty string (\0)
*/
void	quote_removal(char **usr_split)
{
	char	*tmp;

	while (*usr_split)
	{
		if (**usr_split == '\"' || **usr_split == '\'')
		{
			tmp = remove_quotes(*usr_split);
			if (!tmp)
			{
				free_ptr(usr_split);
				return ;
			}
			*usr_split = tmp;
		}
		usr_split++;
	}
}
