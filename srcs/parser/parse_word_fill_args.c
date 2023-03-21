/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_word_fill_args.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:37:55 by mvomiero          #+#    #+#             */
/*   Updated: 2023/03/21 19:36:23 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int	count_arguments(t_token *temp)
{
	int	i;

	i = 0;
	while (temp && (temp->type == WORD || temp->type == SPACES))
	{
		if(temp->type == WORD && temp->next->type != WORD)
			i++;
		temp = temp->next;
	}
	return (i);
}

static void	fill_args_array(t_token **temp, char **args, int *i)
{
	char	*str_join;
	
	while (*temp && ((*temp)->type == WORD || (*temp)->type == SPACES))
	{
		while ((*temp)->type == WORD && (*temp)->next->type == WORD)
		{
			str_join = ft_strjoin((*temp)->str, (*temp)->next->str);
			// is it here mallocated? if not control for the frees
			(*temp)->next->str = str_join;
			(*temp) = (*temp)->next;
		}
		if ((*temp)->type == WORD)
		{
			args[*i] = ft_strdup((*temp)->str);
			*i += 1;
		}
		(*temp) = (*temp)->next;
	}
	
}

void	create_args_default_mode(t_token **token_node, t_command *last_cmd)
{
	int		i;
	int		nb_args;
	t_token	*temp;

	i = 0;
	temp = *token_node;
	nb_args = count_arguments(temp);
	last_cmd->args = malloc(sizeof(char *) * (nb_args + 2));
	if (!last_cmd->args)
		return ;
	temp = *token_node;
	i = 0;
	last_cmd->args[i] = ft_strdup(last_cmd->command);
	i++;
	fill_args_array(&temp, last_cmd->args, &i);
	/* while (temp->type == WORD || temp->type == SPACES)
	{
		last_cmd->args[i] = ft_strdup(temp->str);
		i++;
		temp = temp->next;
	} */
	last_cmd->args[i] = NULL;
	*token_node = temp;
	return ;
}

static char	**copy_default_in_new_tab(
	int len, char **new_tab, t_command *last_cmd, t_token **tk_node)
{
	int		i;
	t_token	*temp;

	i = 0;
	temp = *tk_node;
	while (i < len)
	{
		new_tab[i] = last_cmd->args[i];
		i++;
	}
	fill_args_array(&temp, new_tab, &i);
	/* while (temp->type == WORD || temp->type == SPACES)
	{
		new_tab[i] = ft_strdup(temp->str);
		i++;
		temp = temp->next;
	} */
	new_tab[i] = NULL;
	return (new_tab);
}

void	add_args_default_mode(t_token **token_node, t_command *last_cmd)
{
	int		i;
	int		len;
	char	**new_tab;
	t_token	*temp;

	i = 0;
	temp = *token_node;
	while (temp->type == WORD || temp->type == SPACES)
	{
		i++;
		temp = temp->next;
	}
	len = 0;
	while (last_cmd->args[len])
		len++;
	new_tab = malloc(sizeof(char *) * (i + len + 1));
	if (!new_tab)
		return ;
	new_tab = copy_default_in_new_tab(len, new_tab, last_cmd, token_node);
	free_array_str(last_cmd->args);
	last_cmd->args = new_tab;
	*token_node = temp;
	return ;
}

void	fill_args(t_token **token_node, t_command *last_cmd)
{
		if (last_cmd && !(last_cmd->args))
			create_args_default_mode(token_node, last_cmd);
		else
			add_args_default_mode(token_node, last_cmd);
}