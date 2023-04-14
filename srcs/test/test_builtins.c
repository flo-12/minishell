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

// cc test_builtins.c ../builtins/builtin_utils.c ../builtins/builtin_export.c ../builtins/builtin_env.c ../utils/utils.c -L../../libft/ -lft -o test_builtins.out
// valgrind: valgrind --leak-check=full ./test_builtins.out E=sdjkfwe A=jkwefwe

#include "../../includes/minishell_flo.h"

/*
COPIED FROM error.c
*/
void	err_msg(char *s1, char *s2, char *s3)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(s1, STDERR_FILENO);
	if (s2)
	{
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd(s2, STDERR_FILENO);
		if (s3)
		{
			ft_putstr_fd(": ", STDERR_FILENO);
			ft_putstr_fd(s3, STDERR_FILENO);
		}
	}
	ft_putstr_fd("\n", STDERR_FILENO);	
}

void	test_export(t_data *data, char **args)
{
	printf("\n\n------ TEST_EXPORT ------\n");
	if (builtin_export(data, args) == EXIT_FAILURE)
		printf("\nEXIT_FAILURE\n");
	else
		printf("\nEXIT_SUCCESS\n");
	printf("LAST ENV: \"%s\"\n", data->env[get_size_ptr(data->env) - 1]);
}

void	test_env(t_data *data)
{
	printf("\n\n------ TEST_ENV ------\n");
	if (builtin_env(data) == EXIT_FAILURE)
		printf("\nEXIT_FAILURE\n");
	else
		printf("\nEXIT_SUCCESS\n");
}

int	main(int argc, char **argv)
{
	t_data	data;
	char	**args;
	int		i;
	int		t_export = 1;
	int		t_env = 1;

	data.env = (char **)malloc(sizeof(char *) * 5);
	data.env[0] = ft_strdup("A=me\0");
	data.env[1] = ft_strdup("B=you\0");
	data.env[2] = ft_strdup("C=sjkfa\0");
	data.env[3] = ft_strdup("D=sdfgwef=fsa!/fsd3\0");
	data.env[4] = NULL;
	args = (char **)malloc(sizeof(char *) * argc);
	i = 0;
	while (++i < argc)
		args[i - 1] = ft_strdup(*(argv + i));
	args[argc - 1] = NULL;
	if (t_export)
	{
		if (argc == 1)
			test_export(&data, NULL);
		else
			test_export(&data, args);
	}
	if (t_env)
	{
		if (argc == 1)
			test_env(&data);
		else
			test_env(&data);
	}
	free_ptr(data.env);
	free_ptr(args);
	return (0);
}
