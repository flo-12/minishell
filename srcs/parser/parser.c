/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:14:46 by mvomiero          #+#    #+#             */
/*   Updated: 2023/03/21 18:48:57 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parser(t_data *data)
{
	t_token *temp;
	
	temp = data->token;
	// how is the token list in case of no input or input is empty string?
	while (temp->next != NULL)
	{
		printf("\nparser loop - p = %p\n", temp);
		if (temp == data->token)
			cmd_lst_add_end(&data->cmd, cmd_lst_new());
		printf("\ncmd_list - p = %p\n", data->cmd);
		if (temp->type == WORD)
		{
			printf("\nword parsing\n");
			printf("\ncmd_list - p = %p %p\n", &data->cmd, &temp);
			parse_word(&data->cmd, &temp);
		}
/* 		else if (temp->type == INPUT)
			parse_input(&data->cmd, &temp);
		else if (temp->type == TRUNC)
			parse_trunc(&data->cmd, &temp);
		else if (temp->type == HEREDOC)
			parse_heredoc(data, &data->cmd, &temp);
		else if (temp->type == APPEND)
			parse_append(&data->cmd, &temp); */
		else if (temp->type == PIPE)
			parse_pipe(&data->cmd, &temp);
		// case for the spaces
		else if (temp->type == SPACES)
			temp = temp->next;
		// case for the end of the list


		//else if (temp->next == NULL)
		//	break ;
	}
	//prep_no_arg_commands(data);
}