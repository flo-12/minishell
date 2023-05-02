/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:47:51 by mvomiero          #+#    #+#             */
/*   Updated: 2023/05/02 18:34:07 by mvomiero         ###   ########.fr       */
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
		// It is to update the history of commands going with arrow up
		add_history(data->user_input);
		// since the ret from lexer is a bool and minishell is a void function,
		// we don't need a ret variable.
		if (lexer(data))
		{
			token_lstadd_back(&data->token, token_lstnew(NULL, END));
			if (syntax_check(&data->token))
				g_last_exit_code = 2;
			else
			{
				
				parser(data);
				//print_cmd_list(data);
				g_last_exit_code = executor(data);
			}
			//print_token_list(&data->token);
		}
		free_data(data, false);
	}
}

int main(int ac, char **av, char **env)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	
	//if (ac != 1)
	//	return (ft_putendl_fd("minishell doesn't accept arguments!", 2), 1);
	if (!init_data(&data, env))
		exit_minishell(&data, EXIT_FAILURE);
	
	if (ac == 3 && !ft_strncmp(av[1], "-c", 3) && av[2])
		minishell_testing(&data, av[2]);
	else
		minishell(&data);
	
	(void)av;
	exit_minishell(&data, g_last_exit_code);
	return (0);
}
