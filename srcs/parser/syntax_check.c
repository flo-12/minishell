/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:16:46 by mvomiero          #+#    #+#             */
/*   Updated: 2023/04/28 17:24:41 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*skip_spaces(t_token *lst)
{
	t_token	*prev;

	if (lst->prev)
	{
		prev = lst->prev;
		if (prev->type == SPACES && prev->prev)
			prev = prev->prev;
	}
	else
		prev = NULL;
	return (prev);
}

bool	syntax_check(t_token **token_lst)
{
	t_token	*temp;
	t_token	*prev;

	temp = *token_lst;
	while (temp)
	{
		prev = skip_spaces(temp);
		if (prev)
		{
			if (temp->type >= PIPE && prev->type >= PIPE)
			{
				if (temp->type == END && prev->type > PIPE)
					err_msg_syntax(0);
				else if (temp->type == END && prev)
					err_msg_syntax(prev->type);
				else
					err_msg_syntax(temp->type);
				return (EXIT_FAILURE);
			}
		}
		if (temp->type == PIPE && !prev)
			return (err_msg_syntax(temp->type), EXIT_FAILURE);
		temp = temp->next;
	}
	return (EXIT_SUCCESS);
}
