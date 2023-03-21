/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sandbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:40:02 by mvomiero          #+#    #+#             */
/*   Updated: 2023/03/21 19:37:22 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"




t_token	*lst_new_token(char *str, int type)
{
	t_token	*new_node;

	new_node = malloc(sizeof(t_token) * 1);
	if (!(new_node))
		return (NULL);
	new_node->str = str;
	new_node->var_exists = false;
	new_node->type = type;
	new_node->status = 0;
	new_node->join = false;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

void	lst_add_back_token(t_token **alst, t_token *new_node)
{
	t_token	*start;

	start = *alst;
	if (start == NULL)
	{
		*alst = new_node;
		return ;
	}
	if (alst && *alst && new_node)
	{
		while (start->next != NULL)
			start = start->next;
		start->next = new_node;
		new_node->prev = start;
	}
}

void	token_create_list(t_data *data)
{
	data->token = lst_new_token("echo", WORD);
	lst_add_back_token(&data->token, lst_new_token(" ", SPACES));
	lst_add_back_token(&data->token, lst_new_token("hello", WORD));
	lst_add_back_token(&data->token, lst_new_token(" ", SPACES));
	lst_add_back_token(&data->token, lst_new_token("", WORD));
	lst_add_back_token(&data->token, lst_new_token(" ", SPACES));
	lst_add_back_token(&data->token, lst_new_token("|", PIPE));
	lst_add_back_token(&data->token, lst_new_token(" ", SPACES));
	lst_add_back_token(&data->token, lst_new_token("echo", WORD));
	lst_add_back_token(&data->token, lst_new_token(" ", SPACES));
	lst_add_back_token(&data->token, lst_new_token("ciao", WORD));
	lst_add_back_token(&data->token, lst_new_token(" ", SPACES));
	lst_add_back_token(&data->token, lst_new_token("ciao", WORD));
	lst_add_back_token(&data->token, lst_new_token("marco", WORD));
	lst_add_back_token(&data->token, lst_new_token("stop", APPEND));



}