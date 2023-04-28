/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:47:51 by mvomiero          #+#    #+#             */
/*   Updated: 2023/04/28 16:03:43 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	last_exit_code;

static void	minishell(t_data *data)
{
	// while (1)
	// {
	// 	_Bool	ret;

	// 	/* READ USER INPUT IN PROMPT (line by line) */
	// 	data->user_input = readline(PROMPT);
	// 	/* LEXER (for each line of user input) */
	// 	ret = lexer(data);
	// 	if (!ret)	// means that something went wrong and token is not initialized
	// 	{
	// 		// free data (especially env & user_input i guess)
	// 		// print error
	// 		// skip parser and executer, but stay in while-loop
	// 	}
	// 	/* PARSER (for Lexer list) */
	// 	parser(data);
		
	// 	/* TEST PRINT token list and command list */
	// 	print_token_list(&data->token);
	// 	print_cmd_list(data);
		
	// 	/*
	// 	SET-SIGNALS FROM mcombeau:
	// 	set_signals_noninteractive();
	// 	*/
		
	// 	last_exit_code = executor(data);
	// 	printf("exit code: %d\n", last_exit_code);
	// 	/*
	// 	EXECUTION FROM mcombeau:
	// 	if (lexer(data) && parser(data))
	// 		last_exit_code = execute(data);
	// 	else
	// 		g_last_exit_code = 1;
	// 	*/
		
	// 	//printf("\ngeschafft!\n");
	// 	free_data(data, false);
	// 	printf("data freed\n");
	// }
	
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
			if (syntax_check(&data->token))
				last_exit_code = 2;
			else
			{
				
				parser(data);
				//print_cmd_list(data);
				last_exit_code = executor(data);
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
	exit_minishell(&data, last_exit_code);
	return (0);
}