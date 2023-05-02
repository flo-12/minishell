/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_testing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:18:11 by mvomiero          #+#    #+#             */
/*   Updated: 2023/05/02 16:22:58 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	minishell_testing(t_data *data, char *arg)
{
	char	**user_inputs;
	int		i;

	user_inputs = ft_split(arg, ';');
	if (!user_inputs)
		exit_minishell(data, EXIT_FAILURE);
	i = 0;
	while (user_inputs[i])
	{
		data->user_input = ft_strdup(user_inputs[i]);
		if (lexer(data))
		{
			token_lstadd_back(&data->token, token_lstnew(NULL, END));
			if (syntax_check(&data->token))
				g_last_exit_code = 2;
			else
			{
				
				parser(data);
				//print_token_list(&data->token);
				//printf("fd out %d", data->cmd->io_fds->fd_out);
				//print_cmd_list(data);
				g_last_exit_code = executor(data);
				//printf("fd out %d", data->cmd->io_fds->fd_out);
			}
		}
		i++;
		free_data(data, false);
	}
	free_array_str(user_inputs);
}