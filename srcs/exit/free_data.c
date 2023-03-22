/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:43:40 by mvomiero          #+#    #+#             */
/*   Updated: 2023/03/22 12:13:35 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_pointer(void *ptr)
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

void	free_data(t_data *data, bool clear_history)
{
	if (data && data->user_input)
	{
		free_pointer(data->user_input);
		data->user_input = NULL;
	}
/* 	if (data && data->token)
		lstclear_token(&data->token, &free_pointer);
	if (data && data->cmd)
		lst_clear_cmd(&data->cmd, &free_pointer); */
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