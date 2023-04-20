/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:36:32 by fbecht            #+#    #+#             */
/*   Updated: 2023/04/14 18:36:34 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "minishell.h"
#include "../../includes/minishell_flo.h"

/*
* Check if str is a valid n-flag
*	1) starts with '-'
*	2) all other chars are n's (at least one)
*/
_Bool	is_n_flag(char *str)
{
	if (*str != '-')
		return (false);
	str++;
	while (*str)
	{
		if (*str != 'n')
			return (false);
		str++;
	}
	return (true);
}

/*
* print out all args consecutivly followed by a \n (if n_flag==false)
* adds a space between each argument (not after the last arg)
*/
void	echo_print(char **args, _Bool n_flag)
{
	while (*args)
	{
		if (!ft_strncmp(*args, "$?", 3))
			printf("%d", (unsigned char)last_exit_code);
		else
			printf("%s", *args);
		if (*(args + 1))
			printf(" ");
		args++;
	}
	if (!n_flag)
		printf("\n");
}

/*
* Imitates the builtin function "echo" of bash
*	print out all the arguments with a '\n' at the end
*	no \n printed if option -n is set
*		first argument has to be -n (with a random number of n's)
*		n's are not printed
*		of first argument is -n and second one as well, then the
*			second argument is also not printed
*	E.g.: args[0]="-nnnn"; args[1]="-n"; args[2]="-n2"; args[3]="42"
*		Output in prompt: "-n2 42" (without \n)
*/
int	builtin_echo(t_data *data, char **args)
{
	_Bool	n_flag;
	int		i;

	n_flag = false;
	i = 0;
	while (args[i] && is_n_flag(args[i]))
	{
		n_flag = true;
		i++;
	}
	echo_print(args + i, n_flag);
	return (EXIT_SUCCESS);
}
