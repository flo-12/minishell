/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:39:18 by fbecht            #+#    #+#             */
/*   Updated: 2023/03/27 10:39:20 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "minishell.h"

#include "../../includes/minishell_flo.h"

void	token_lstadd_back(t_token **start, t_token *new)
{
	t_token	*tmp;

	if (!new || !start)
		return ;
	if (!*start)
	{
		*start = new;
		return ;
	}
	tmp = *start;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

void	token_lstclear(t_token **lst)
{
	t_token	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		token_lstdelone(*lst);
		*lst = NULL;
		*lst = tmp;
	}
}

void	token_lstdelone(t_token *lst)
{
	if (!lst)
		return ;
	if (lst->str)
	{
		free(lst->str);
		free(lst->str_backup);
	}
	free(lst);
}

t_token	*token_lstnew(char *str, int type)
{
	t_token	*new_node;
	char	*str_backup;

	new_node = (t_token *)malloc(sizeof(t_token));
	if (!new_node)
		return (NULL);
	new_node->str = NULL;
	if (str)
	{
		str_backup = ft_strdup(str);
		if (!str_backup)
		{
			token_lstdelone(new_node);
			return (NULL);
		}
	}
	else
		str_backup = NULL;
	new_node->str = str;
	new_node->str_backup = str_backup;
	new_node->type = type;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

t_token	*token_lstlast(t_token *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}
