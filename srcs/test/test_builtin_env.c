/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 19:21:43 by fbecht            #+#    #+#             */
/*   Updated: 2023/04/13 19:21:45 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// cc test_builtins.c ../builtins/builtin_exit.c ../builtins/builtin_unset.c ../builtins/builtin_cd.c ../builtins/builtin_pwd.c ../builtins/builtin_echo.c ../builtins/builtin_utils.c ../builtins/builtin_export.c ../builtins/builtin_env.c ../utils/utils.c -L../../libft/ -lft -o test_builtins.out
// valgrind --leak-check=full ./test_builtins.out E=sdjkfwe A=jkwefwe

#include <stdio.h>
#include <stdlib.h>

typedef struct s_data
{
	char		*user_input;
	char		**env;
	char		*working_dir;
	char		*old_working_dir;
}	t_data;

int	builtin_env(t_data *data);

void	test_env(t_data *data)
{
	printf("\n\n------ TEST_ENV ------\n");
	if (builtin_env(data) == 1)
		printf("\nEXIT_FAILURE\n");
	else
		printf("\nEXIT_SUCCESS\n");
}

int	main(int argc, char **argv)
{
	t_data	data;

	(void)argv;
	(void)argc;
	/*********** INITIALIZE DATA ***********/
	data.env = (char **)malloc(sizeof(char *) * 8);
	data.env[0] = "A=me";
	data.env[1] = "B=you";
	data.env[2] = "C=sjkfa";
	data.env[3] = "D=sdfgwef=fsa!/fsd3";
	data.env[4] = "HOME=/nfs/homes/fbecht";
	data.env[5] = "PWD=/nfs/homes/fbecht/42_Projects/Level_3/minishell_project/our_minishell/srcs/test";	data.env[6] = "OLDPWD=/nfs/homes/fbecht/42_Projects/Level_3/minishell_project/our_minishell";
	data.env[7] = NULL;
	
	test_env(&data);
	return (0);
}
