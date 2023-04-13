/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:47:51 by mvomiero          #+#    #+#             */
/*   Updated: 2023/04/13 15:40:28 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	last_exit_code;

static void	minishell(t_data *data)
{
	while (1)
	{
		_Bool	ret;

		/* READ USER INPUT IN PROMPT (line by line) */
		data->user_input = readline(PROMPT);
		/* LEXER (for each line of user input) */
		ret = lexer(data);
		if (!ret)	// means that something went wrong and token is not initialized
		{
			// free data (especially env & user_input i guess)
			// print error
			// skip parser and executer, but stay in while-loop
		}
		/* PARSER (for Lexer list) */
		parser(data);
		
		/* TEST PRINT token list and command list */
		print_token_list(&data->token);
		print_cmd_list(data);
		
		/*
		SET-SIGNALS FROM mcombeau:
		set_signals_noninteractive();
		*/
		/*
		EXECUTION FROM mcombeau:
		if (lexer(data) && parser(data))
			last_exit_code = execute(data);
		else
			g_last_exit_code = 1;
		*/
		
		printf("geschafft!\n");
		free_data(data, false);
	}
}

int main(int ac, char **av, char **env)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	if (ac != 1)
		return (ft_putendl_fd("minishell doesn't accept arguments!", 2), 1);
	if (!init_data(&data, env))
		exit_minishell(&data, EXIT_FAILURE);
	

	minishell(&data);
	
	(void)av;
	printf("hello world!\n");

	exit_minishell(&data, last_exit_code);
	return (0);
}