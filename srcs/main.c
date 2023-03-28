/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:47:51 by mvomiero          #+#    #+#             */
/*   Updated: 2023/03/21 16:17:39 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	last_exit_code;

static void	minishell(t_data *data)
{
	while (1)
	{
		//set_signals_interactive();
		data->user_input = readline(PROMPT);
		/* if (lexer(data) && parser(data))
			last_exit_code = execute(data);
		else
			g_last_exit_code = 1; */
			
		//set_signals_noninteractive();
		/* if (parse_user_input(data) == true)
			g_last_exit_code = execute(data);
		else
			g_last_exit_code = 1; */
		printf("%s\n", data->user_input);
		free_data(data, false);
	}
}

int main(int ac, char **av, char **env)
{
	t_data	data;
	_Bool	ret;

	ft_memset(&data, 0, sizeof(t_data));
	if (ac != 1)
		return (ft_putendl_fd("minishell doesn't accept arguments!", 2), 1);
	if (!init_data(&data, env))
		exit_minishell(&data, EXIT_FAILURE);
	
	ret = lexer(&data);
	if (!ret)	// means that something went wrong and token is not initialized
	{
		// free data (especially env & user_input i guess)
		return (0);
	}
	//test_token_list(&data);
	
	
	
	token_create_list(&data);
	print_token_list(&((&data)->token));
	parser(&data);
	print_cmd_list(&data);

	minishell(&data);
	
	(void)av;
	printf("hello world!\n");

	exit_minishell(&data, last_exit_code);
	return (0);
}