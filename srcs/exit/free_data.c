/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:43:40 by mvomiero          #+#    #+#             */
/*   Updated: 2023/05/02 11:36:36 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_pointer(void *ptr)
{
	if (ptr != NULL)
	{
		free(ptr);
		ptr = NULL;
	}
}

void	free_array_str(char **array)
{
	int	i;

	i = 0;
	if (array)
	{
		while (array[i])
		{
			if (array[i])
			{
				free_pointer(array[i]);
				array[i] = NULL;
			}
			i++;
		}
		free(array);
		array = NULL;
	}
}

void	token_lstdelone(t_token *lst)
{
	if (!lst)
		return ;
	if (lst->str)
		free(lst->str);
	if (lst->str_backup)
		free(lst->str_backup);
	lst->str = NULL;
	lst->str_backup = NULL;
	free(lst);
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

void	free_data(t_data *data, bool clear_history)
{
	if (data && data->user_input)
	{
		free_pointer(data->user_input);
		data->user_input = NULL;
	}
	if (data && data->token)
		token_lstclear(&data->token);
	if (data && data->cmd)
		free_cmd_list(&data->cmd, &free_pointer);
	if (clear_history == true)
	{
		if (data && data->working_dir)
			free_pointer(data->working_dir);
		if (data && data->old_working_dir)
			free_pointer(data->old_working_dir);
		if (data && data->env)
			free_array_str(data->env);
		rl_clear_history();
	}
}
