/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 18:20:15 by fbecht            #+#    #+#             */
/*   Updated: 2023/05/02 12:31:38 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
//#include "../../includes/minishell_flo.h"

/*
* If exit is part of a pipe, "exit" should not be printed.
*	Return "false" if exit should not be printed and "true"
*	in every other case.
*/
_Bool	print_exit(t_data *data)
{
	if (!data->cmd)
		return (true);
	else if (data->cmd->next || data->cmd->prev)
		return (false);
	else
		return (true);
}

/*
* Convert the str to an int in the range 0..255 as the range
* of exit codes is defined.
*	If the str is not fully numeric, return -1
*	In case of e.g. 256 return 0 as of an overflow
*	Consecutive spaces followed by one sign (+/-) are allowed
*		(see definition of atoi with some exceptions)
*/
int	get_exit_code(char *str)
{
	int	exit_code;

	exit_code = ft_atoi(str);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
		str++;
	if (*str != '\0')
		return (-1);
	return ((unsigned char)exit_code);
}

/*
* Imitates the builtin function "exit" of bash
* 	args are the arguments entered by the user (args[0]->exit code)
*	// 1) check if there is a next or previous command -> don't print exit
	// 2) if no args					-> exit & take last_exit_code
	// 3) else if more than 1 args		-> don't exit and set 2
	// 4) else if args[0] is not numeric-> exit & set 2
	// 5) else							-> exit & set args[0]
*/
int	builtin_exit(t_data *data, char **args)
{
	int	exit_code;

	if (print_exit(data))
		printf("exit\n");
	if (!args || !args[0])
		exit_code = (unsigned char)g_last_exit_code;
	else
	{
		if (args[1])
			return (err_msg("exit", "too many arguments", NULL), 2);
		exit_code = get_exit_code(args[0]);
		if (exit_code < 0)
		{
			err_msg("exit", args[0], "numeric argument required");
			exit_code = 2;
		}
	}
	exit_minishell(data, exit_code);
	return (2);
}
