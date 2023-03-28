/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:41:29 by fbecht            #+#    #+#             */
/*   Updated: 2023/03/15 12:41:31 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//#include "../../includes/minishell_flo.h"

/*
Add a new node at the back of the list "token" of the type
WORD and containing the all the chars until the next quote
of the same type (single/double).
Return: length of the str between the quotes (inlcuding
	the quotes)
Precondition: str starts with a quote and consists the
	same type of quote (signle/double) again
*/
int	token_add_quote_node(t_token **token, char *str)
{
	int		i;
	char	*tmp;

	i = 1;
	while (str[i] != str[0] && str[i])
		i++;
	tmp = (char *)malloc(sizeof(char) * (i + 2));
	if (!tmp)
		return (i + 1);
	ft_strlcpy(tmp, str, i + 2);
	token_lstadd_back(token, token_lstnew(tmp, WORD));
	return (i + 1);
}

/*
Add a new node at the back of the list "token" of the type
WORD and containing the chars of str, belonging to a word:
	* seperatred by an other token (e.g. space or pipe)
	* exception if str starts with quotes: the word ends
		when the same type (signle / double) of quotes is
		found
Return: length of the string that is stored in the t_token
Precondition: str doesn't start with a space, pipe, input,
trunc, heredoc or append
*/
int	token_add_word_node(t_token **token, char *str)
{
	int		i;
	char	*tmp;

	if (*str == '\'' || *str == '\"')
		return (token_add_quote_node(token, str));
	i = 1;
	while ((str[i] != ' ' && str[i] != '|'
			&& str[i] != '<' && str[i] != '>') && str[i])
		i++;
	i--;
	tmp = (char *)malloc(sizeof(char) * (i + 2));
	if (!tmp)
		return (i + 1);
	ft_strlcpy(tmp, str, i + 2);
	token_lstadd_back(token, token_lstnew(tmp, WORD));
	return (i + 1);
}

/*
Add a new node at the back of the list "token" of the type
PIPE ('|'), INPUT ('<'), TRUNC ('>'), HEREDOC ('<<') or 
APPEND ('>>')
Return:  length of the token
Precondition: str must start with one of the beforehand 
	mentioned types
*/
int	token_add_sepcial_node(t_token **token, char *str)
{
	if (*str == '|')
		token_lstadd_back(token, token_lstnew(NULL, PIPE));
	else if (*str == '<')
	{
		if (*(str + 1) == '<')
		{
			token_lstadd_back(token, token_lstnew(NULL, HEREDOC));
			return (2);
		}
		token_lstadd_back(token, token_lstnew(NULL, INPUT));
	}
	else if (*str == '>')
	{
		if (*(str + 1) == '>')
		{
			token_lstadd_back(token, token_lstnew(NULL, APPEND));
			return (2);
		}
		token_lstadd_back(token, token_lstnew(NULL, TRUNC));
	}
	return (1);
}

/*
Add a new node at the back of the list "token" of the type 
SPACES
	* Exception: no node added, if previous node is already
		a space
Return: number of consecutive spaces at the beginning of str
Precondition: str must start with a space
*/
int	token_add_space(t_token **token, char *str)
{
	if (*token)
	{
		if ((token_lstlast(*token))->type != SPACES)
			token_lstadd_back(token, token_lstnew(NULL, SPACES));
	}
	else
		token_lstadd_back(token, token_lstnew(NULL, SPACES));
	return (get_nbr_spaces(str));
}

/*
Initializes the double-linked list t_token with at least one
node for each string in usr_split and splitting the argument
into tokens - t_token.type - (from e_token_types) as followed:
	- SPACES: one ore more spaces (' ')
	- WORD: string which doesn't contain any other tokens
	- PIPE: '|'
	- INPUT: '<'
	- TRUNC: '>'
	- HEREDOC: '<<'
	- APPEND: '>>'
In case of word, the string is stored in str (plus copy in
str_backup). In all other cases, str and str_backup must be
NULL.
Return: double-linked list t_token (NULL in case of error)
Precondition: usr_split != NULL
*/
t_token	*tokenization(char **usr_split)
{
	t_token	*token;
	int		i;

	token = NULL;
	while (*usr_split)
	{
		i = 0;
		while ((*usr_split)[i])
		{
			if ((*usr_split)[i] == ' ')
				i += token_add_space(&token, (*usr_split) + i);
			else if ((*usr_split)[i] == '|' || (*usr_split)[i] == '<'
					|| (*usr_split)[i] == '>')
				i += token_add_sepcial_node(&token, (*usr_split) + i);
			else
				i += token_add_word_node(&token, (*usr_split) + i);
		}
		usr_split++;
	}
	return (token);
}
