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
void	quote_removal(t_token *token)
{
	char	*tmp;

	while (token)
	{
		if (token->str)
		{
			if (*(token->str) == '\"' || *(token->str) == '\'')
			{
				token->str = remove_quotes(token->str);
				token->str_backup = remove_quotes(token->str_backup);
				if (!token->str || !token->str_backup)
				{
					token_lstclear(&token);
					return ;
				}
			}
		}
		token = token->next;
	}
}
