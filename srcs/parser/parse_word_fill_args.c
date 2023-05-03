/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_word_fill_args.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:37:55 by mvomiero          #+#    #+#             */
/*   Updated: 2023/04/28 16:31:22 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* fill_args_array:
	fills the array of strings made of the command and its arguments. If there 
	are no spaces between tokens with type WORD, they will be joined in a single
	string. If the type is WORD, a new string is created.
	Else, so the type is a SPACE, just skips the node.
	line 37 was before like that, but it had a memory leak 
	//args[*i] = ft_strdup((*temp)->str);
 */
static void	fill_args_array(t_token **temp, char **args, int *i)
{
	char	*str_join;
	char	*tmp;

	while (*temp && ((*temp)->type == WORD || (*temp)->type == SPACES))
	{
		str_join = NULL;
		while ((*temp)->type == WORD)
		{
			tmp = str_join;
			if (tmp)
			{
				str_join = ft_strjoin(tmp, (*temp)->str);
				free(tmp);
			}
			else
				str_join = ft_strdup((*temp)->str);
			*temp = (*temp)->next;
		}
		args[*i] = str_join;
		*i += 1;
		(*temp) = (*temp)->next;
	}
}

/* 
	copies the existing args in the new array. Then the new args are added
	thanks to the fill_args_array() function. At the end, the array is NULL
	terminated and returned.
 */
static char	**copy_old_args_in_new_array(
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
	new_tab[i] = NULL;
	return (new_tab);
}

/* fill_args:
	goal of this function is to create an array of strings where are stored the
	command and its arguments. first step is to know the size of this array of 
	strings. For this, two iterators are set: i finds the number of token that
	have to be added, len finds the number of args that are already stored in 
	the existing array. After mallocating the new array, thanks to the 
	copy_old_args_in_new_array() function the existing args are copied and the 
	new ones are created from the tokens. the token list is at the end set to 
	the node temp is pointing to
 */
void	parse_word_fill_args(t_token **token_node, t_command *last_cmd)
{
	int		i;
	int		len;
	char	**new_tab;
	t_token	*temp;

	i = 0;
	temp = *token_node;
	while (temp->type == WORD || temp->type == SPACES)
	{
		if (temp->type == WORD)
			i++;
		temp = temp->next;
	}
	len = 0;
	while (last_cmd->args[len])
		len++;
	new_tab = malloc(sizeof(char *) * (i + len + 1));
	if (!new_tab)
		return ;
	new_tab = copy_old_args_in_new_array(len, new_tab, last_cmd, token_node);
	free(last_cmd->args);
	last_cmd->args = new_tab;
	*token_node = temp;
}
