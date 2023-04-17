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

// cc test_builtins.c ../builtins/builtin_cd.c ../builtins/builtin_pwd.c ../builtins/builtin_echo.c ../builtins/builtin_utils.c ../builtins/builtin_export.c ../builtins/builtin_env.c ../utils/utils.c -L../../libft/ -lft -o test_builtins.out
// valgrind --leak-check=full ./test_builtins.out E=sdjkfwe A=jkwefwe

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

void	test_pwd(t_data *data)
{
	printf("\n\n------ TEST_PWD ------\n");
	if (builtin_pwd(data) == EXIT_FAILURE)
		printf("\nEXIT_FAILURE\n");
	else
		printf("\nEXIT_SUCCESS\n");
}

void	test_echo(t_data *data, char **args)
{
	printf("\n\n------ TEST_ECHO ------\n");
	if (builtin_echo(data, args) == EXIT_FAILURE)
		printf("\nEXIT_FAILURE\n");
	else
		printf("\nEXIT_SUCCESS\n");
}

void	test_cd(t_data *data, char **args)
{
	char	*path;

	printf("\n\n------ TEST_ECHO ------\n");
	printf("1st test: with argv");
	if (builtin_cd(data, args) == EXIT_FAILURE)
		printf("\nEXIT_FAILURE\n");
	else
		printf("\nEXIT_SUCCESS\n");
	printf("data->env[PWD]=%s\n", data->env[get_env_var_i(data->env, "PWD=")]);
	printf("data->env[OLDPWD]=%s\n", data->env[get_env_var_i(data->env, "OLDPWD=")]);
	printf("data->working_dir=%s\n", data->working_dir);
	printf("data->old_working_dir=%s\n", data->old_working_dir);
	printf("getcwd=%s\n", getcwd(path, 0));
	free(path);
/*	printf("2nd test: without args (go back to HOME)");
	if (builtin_cd(data, NULL) == EXIT_FAILURE)
		printf("\nEXIT_FAILURE\n");
	else
		printf("\nEXIT_SUCCESS\n");
	printf("3rd test: with non-existant path /nfs/homes42/fbecht/42_Projects/Level_3/minishell_project/ (error)");
	free(args[1]);
	args[1] = ft_strdup("/nfs/homes42/fbecht/42_Projects/Level_3/minishell_project/");
	if (builtin_cd(data, NULL) == EXIT_FAILURE)
		printf("\nEXIT_FAILURE\n");
	else
		printf("\nEXIT_SUCCESS\n");
	printf("4th test: with regular absolute path /nfs/homes/fbecht/42_Projects/");
	free(args[1]);
	args[1] = ft_strdup("/nfs/homes/fbecht/42_Projects/");
	if (builtin_cd(data, NULL) == EXIT_FAILURE)
		printf("\nEXIT_FAILURE\n");
	else
		printf("\nEXIT_SUCCESS\n");
	printf("data->env[PWD]=%s\n", data->env[get_env_var_i(data->env, "PWD=")]);
	printf("data->env[OLDPWD]=%s\n", data->env[get_env_var_i(data->env, "OLDPWD=")]);
	printf("data->working_dir=%s\n", data->working_dir);
	printf("data->old_working_dir=%s\n", data->old_working_dir);
	printf("getcwd=%s\n", getcwd(path, 0));
	free(path);
	printf("5th test: with regular relative path ../../include/");
	free(args[1]);
	args[1] = ft_strdup("../../include/");
	if (builtin_cd(data, NULL) == EXIT_FAILURE)
		printf("\nEXIT_FAILURE\n");
	else
		printf("\nEXIT_SUCCESS\n");
	printf("data->env[PWD]=%s\n", data->env[get_env_var_i(data->env, "PWD=")]);
	printf("data->env[OLDPWD]=%s\n", data->env[get_env_var_i(data->env, "OLDPWD=")]);
	printf("data->working_dir=%s\n", data->working_dir);
	printf("data->old_working_dir=%s\n", data->old_working_dir);
	printf("getcwd=%s\n", getcwd(path, 0));
	free(path);
	printf("6th test: with \"-\" as change to previous dir");
	free(args[1]);
	args[1] = ft_strdup("-");
	if (builtin_cd(data, NULL) == EXIT_FAILURE)
		printf("\nEXIT_FAILURE\n");
	else
		printf("\nEXIT_SUCCESS\n");
	printf("data->env[PWD]=%s\n", data->env[get_env_var_i(data->env, "PWD=")]);
	printf("data->env[OLDPWD]=%s\n", data->env[get_env_var_i(data->env, "OLDPWD=")]);
	printf("data->working_dir=%s\n", data->working_dir);
	printf("data->old_working_dir=%s\n", data->old_working_dir);
	printf("getcwd=%s\n", getcwd(path, 0));
	free(path);
	printf("7th test: with \"--\" as change to HOME");
	free(args[1]);
	args[1] = ft_strdup("--");
	if (builtin_cd(data, NULL) == EXIT_FAILURE)
		printf("\nEXIT_FAILURE\n");
	else
		printf("\nEXIT_SUCCESS\n");
	printf("data->env[PWD]=%s\n", data->env[get_env_var_i(data->env, "PWD=")]);
	printf("data->env[OLDPWD]=%s\n", data->env[get_env_var_i(data->env, "OLDPWD=")]);
	printf("data->working_dir=%s\n", data->working_dir);
	printf("data->old_working_dir=%s\n", data->old_working_dir);
	printf("getcwd=%s\n", getcwd(path, 0));
	free(path);*/
}

int	main(int argc, char **argv)
{
	t_data	data;
	char	**args;
	int		i;
	int		t_export = 0;
	int		t_env = 0;
	int		t_pwd = 0;
	int		t_echo = 0;	// be careful: argv is used for export AND echo
	int		t_cd = 1;	// be careful: argv is used for export AND echo

	/*********** INITIALIZE DATA ***********/
	data.env = (char **)malloc(sizeof(char *) * 7);
	data.env[0] = ft_strdup("A=me\0");
	data.env[1] = ft_strdup("B=you\0");
	data.env[2] = ft_strdup("C=sjkfa\0");
	data.env[3] = ft_strdup("D=sdfgwef=fsa!/fsd3\0");
	data.env[4] = ft_strdup("HOME=/nfs/homes/fbecht\0");
	data.env[5] = ft_strdup("PWD=/nfs/homes/fbecht/42_Projects/Level_3/minishell_project/our_minishell/srcs/test\0");
	data.env[6] = ft_strdup("OLDPWD=/nfs/homes/fbecht/42_Projects/Level_3/minishell_project/our_minishell\0");
	data.env[7] = NULL;
	if (argc != 1)
		args = (char **)malloc(sizeof(char *) * argc);
	else
	{
		args = (char **)malloc(sizeof(char *) * 1);
		args[0] = NULL;
	}
	i = 0;
	while (++i < argc)
		args[i - 1] = ft_strdup(*(argv + i));
	args[argc - 1] = NULL;
	data.working_dir = ft_strdup("/nfs/homes/fbecht/42_Projects/Level_3/minishell_project/our_minishell/srcs/test");
	data.old_working_dir = ft_strdup("OLDPWD=/nfs/homes/fbecht/42_Projects/Level_3/minishell_project/our_minishell");

	/*********** START TESTS ***********/
	if (t_export)
	{
		if (argc == 1)
			test_export(&data, NULL);
		else
			test_export(&data, args);
	}
	if (t_env)
	{
		test_env(&data);
	}
	if (t_pwd)
	{
		test_pwd(&data);
	}
	if (t_echo)
	{
			test_echo(&data, args);
	}
	if (t_cd)
	{
		test_cd(&data, args);
	}
	free_ptr(data.env);
	free_ptr(args);
	return (0);
}
