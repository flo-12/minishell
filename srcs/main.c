/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:47:51 by mvomiero          #+#    #+#             */
/*   Updated: 2023/05/03 19:48:14 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_last_exit_code;

static void	minishell(t_data *data)
{
	while (1)
	{
		signal_interactive();
		data->user_input = readline(PROMPT);
		if (!data->user_input)
		{
			printf("exit\n");
			return (exit_minishell(data, 0));
		}
		signal_non_interactive();
		add_history(data->user_input);
		if (lexer(data))
		{
			token_lstadd_back(&data->token, token_lstnew(NULL, END));
			remove_token_spaces(&data->token);
			if (syntax_check(&data->token))
				g_last_exit_code = 2;
			else
			{
				parser(data);
				g_last_exit_code = executor(data);
			}
		}
		free_data(data, false);
	}
}

int	main(int ac, char **av, char **env)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	if (ac != 1)
		return (ft_putendl_fd("minishell doesn't accept arguments!", 2), 1);
	if (!init_data(&data, env))
		exit_minishell(&data, EXIT_FAILURE);
	minishell(&data);
	(void)av;
	exit_minishell(&data, g_last_exit_code);
	return (0);
}
