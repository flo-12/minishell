/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:54:39 by mvomiero          #+#    #+#             */
/*   Updated: 2023/03/22 11:32:47 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_word(t_command **cmd, t_token **token_lst)
{
	printf("entering parse word");
	
	t_token		*tkn_temp;
	t_command	*cmd_temp;

	tkn_temp = *token_lst;
	while (tkn_temp && (tkn_temp->type == WORD || tkn_temp->type == SPACES))
	{
		cmd_temp = cmd_lst_get_end(*cmd);
		if (tkn_temp->prev == NULL || cmd_temp->command == NULL ||
			(tkn_temp->prev && tkn_temp->prev->type == PIPE))
		{
			cmd_temp->command = ft_strdup(tkn_temp->str);
			if (!cmd_temp->args)
			{
				cmd_temp->args = malloc(sizeof * cmd_temp->args * 2);
				if (!cmd_temp->args)
					return ;
				cmd_temp->args[0] = ft_strdup(cmd_temp->command);
				printf("\n\nCOMMAND: %s\n\n", cmd_temp->args[0]);
				cmd_temp->args[1] = NULL;
			}
			
			tkn_temp = tkn_temp->next;
			printf("command set");
		}
		else
			fill_args(&tkn_temp, cmd_temp);
	}
	*token_lst = tkn_temp;
	// goes on iterating trough the tkn list
}