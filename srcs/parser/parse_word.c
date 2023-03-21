/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:54:39 by mvomiero          #+#    #+#             */
/*   Updated: 2023/03/21 13:52:16 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_word(t_command **cmd, t_token **token_lst)
{
	t_token		*tkn_temp;
	t_command	*cmd_temp;

	tkn_temp = *token_lst;
	while (tkn_temp->type == WORD || tkn_temp->type == SPACES)
	{
		cmd_temp = cmd_lst_get_end(*cmd);
		if (tkn_temp->prev == NULL || cmd_temp->command == NULL ||
			(tkn_temp->prev && tkn_temp->prev->type == PIPE))
		{
			cmd_temp->command = ft_strdup(tkn_temp->str);
			tkn_temp = tkn_temp->next;
		}
		else
			return;
		//	fill_args(&tkn_temp, cmd_temp);
	}
	*token_lst = tkn_temp;
	// goes on iterating trough the tkn list
}