/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:14:46 by mvomiero          #+#    #+#             */
/*   Updated: 2023/03/28 18:24:17 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* parser:
	redirecting function, iterates trough the token list and builds the command
	list. The first if condition is to initialize the command list, the others
	handle the different type of tokens.
	-- parse_word() builds the array of strings made by the command and its 
		arguments
	-- parse_pipe() handles the pipe and initialize a new node in the 
		command list
	-- other functions are about the redirection
 */
void	parser(t_data *data)
{
	t_token *temp;
	
	temp = data->token;
	token_lstadd_back(&temp, token_lstnew(NULL, END));
	// how is the token list in case of no input or input is empty string?
	while (temp->next != NULL)
	{
		if (temp == data->token)
			cmd_lst_add_end(&data->cmd, cmd_lst_new());
		if (temp->type == WORD)
			parse_word(&data->cmd, &temp);
 		else if (temp->type == INPUT)
			parse_input(&data->cmd, &temp);
		else if (temp->type == TRUNC)
			parse_output(&data->cmd, &temp, 't');
		else if (temp->type == APPEND)
			parse_output(&data->cmd, &temp, 'a');
		else if (temp->type == HEREDOC)
			parse_heredoc(&data->cmd, &temp);
		else if (temp->type == PIPE)
			parse_pipe(&data->cmd, &temp);
		// case for the spaces
		else if (temp->type == SPACES)
			temp = temp->next;
		else if (temp->type == END)
			break ;
	}
}