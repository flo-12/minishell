/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:54:39 by mvomiero          #+#    #+#             */
/*   Updated: 2023/04/28 16:52:37 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* get_cmd_str:
	gets the first command string, iterates through the token lists and joins
	WORD tokens that are not separated by a SPACES token. (the case is for
	empty strings "").
 */
static char	*get_cmd_str(t_token **temp)
{
	char	*str_join;
	char	*tmp;

	str_join = NULL;
	/*if ((*temp)->type == WORD)
		str_join = ft_strdup((*temp)->str);
	*temp = (*temp)->next;*/
	while ((*temp)->type == WORD)// && (*temp)->next->type == WORD)
	{
		tmp = str_join;
		if (tmp)
			str_join = ft_strjoin(tmp, (*temp)->str);
		else
			str_join = ft_strdup((*temp)->str);
		if (tmp)
			free(tmp);
		*temp = (*temp)->next;
		/*str_join = ft_strjoin((*temp)->str, (*temp)->next->str);
		free((*temp)->str);
		free((*temp)->next->str);
		(*temp)->next->str = str_join;
		(*temp) = (*temp)->next;*/
	}
	/*if ((*temp)->type == WORD)
		return ((*temp)->str);*/
		//return (ft_strdup((*temp)->str));
	return (str_join);
}

/* parse_word:
	parses the tokens with type WORD.
	First always goes to the last command.
	Then, iterates trough the token list: if is the beginning of the tkn list,
	so ->prev == NULL, or command not initialized or previous node is a PIPE,
	initializes the command and the args array of strings, just with two strings
	, the command and a NULL.
	If the if condition is not meet, the fill args() function is called, to fill
	all the arguments of the command.
	sets the token list to the current tkn_temp node, so the parser() function 
	can go on iterating and parsin all the elements of the list
 */
void	parse_word(t_command **cmd, t_token **token_lst)
{
	t_token		*tkn_temp;
	t_command	*cmd_temp;

	tkn_temp = *token_lst;
	while (tkn_temp && (tkn_temp->type == WORD || tkn_temp->type == SPACES))
	{
		cmd_temp = cmd_lst_get_end(*cmd);
		if (tkn_temp->prev == NULL || cmd_temp->command == NULL
			|| (tkn_temp->prev && tkn_temp->prev->type == PIPE))
		{
			cmd_temp->command = get_cmd_str(&tkn_temp);
			if (!cmd_temp->args)
			{
				cmd_temp->args = malloc(sizeof * cmd_temp->args * 2);
				if (!cmd_temp->args)
					return ;
				cmd_temp->args[0] = ft_strdup(cmd_temp->command);
				cmd_temp->args[1] = NULL;
			}
			tkn_temp = tkn_temp->next;
		}
		else
			parse_word_fill_args(&tkn_temp, cmd_temp);
	}
	*token_lst = tkn_temp;
}
