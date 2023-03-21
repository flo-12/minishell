
#include "../../includes/minishell_flo.h"
#include <stdio.h>

// cc TESTS.c quote_removal.c var_expansion.c split_usr_input.c lexer_utils.c -L../../libft/ -lft

void	printf_ptrs(char **ptr)
{
	if (!ptr)
	{
		printf("ptr == NULL\n");
		return ;
	}
	while (*ptr)
	{
		printf("%s,", *ptr);
		ptr++;
	}
}

/************* FOR TOKENIZATION *************/
int	main(int argc, char **argv)
{
	char 	**ptr;
	char	**env;

	if (argc == 1)
		return (1);
	
	printf("------ AFTER SPLIT ------\n");
	ptr = split_usr_input(argv[1]);
	printf_ptrs(ptr);
	printf("\n\n");

	printf("------ AFTER VAR-EXPANSION ------\n");
	if (argc == 5)
	{
		env = (char **)malloc(sizeof(char *) * 4);
		env[0] = argv[2];
		env[1] = argv[3];
		env[2] = argv[4];
		env[3] = NULL;
	}
	else
	{
		env = (char **)malloc(sizeof(char *) * 4);
		env[0] = "USER=fbecht";
		env[1] = "CROISSANT=french";
		env[2] = "LATE_LUNCH=Marco";
		env[3] = NULL;
	}
	var_expansion(ptr, env);
	printf_ptrs(ptr);
	printf("\n\n");

	printf("------ AFTER QUOTE REMOVAL ------\n");
	quote_removal(ptr);
	printf_ptrs(ptr);
	printf("\n\n");

	return (0);
}

/************* FOR QUOTE REMOVAL *************/
/*int	main(int argc, char **argv)
{
	char 	**ptr;
	char	**env;

	if (argc == 1)
		return (1);
	
	printf("------ AFTER SPLIT ------\n");
	ptr = split_usr_input(argv[1]);
	printf_ptrs(ptr);
	printf("\n\n");

	printf("------ AFTER VAR-EXPANSION ------\n");
	if (argc == 5)
	{
		env = (char **)malloc(sizeof(char *) * 4);
		env[0] = argv[2];
		env[1] = argv[3];
		env[2] = argv[4];
		env[3] = NULL;
	}
	else
	{
		env = (char **)malloc(sizeof(char *) * 4);
		env[0] = "USER=fbecht";
		env[1] = "CROISSANT=french";
		env[2] = "LATE_LUNCH=Marco";
		env[3] = NULL;
	}
	var_expansion(ptr, env);
	printf_ptrs(ptr);
	printf("\n\n");

	printf("------ AFTER QUOTE REMOVAL ------\n");
	quote_removal(ptr);
	printf_ptrs(ptr);
	printf("\n\n");

	return (0);
}*/

/************* FOR VAR EXPANSION *************/
/*int	main(int argc, char **argv)
{
	char 	**ptr;
	char	**env;

	if (argc == 1)
		return (1);
	ptr = split_usr_input(argv[1]);
	printf("------ AFTER SPLIT ------\n");
	printf_ptrs(ptr);
	printf("\n\n");
	if (argc == 5)
	{
		env = (char **)malloc(sizeof(char *) * 4);
		env[0] = argv[2];
		env[1] = argv[3];
		env[2] = argv[4];
		env[3] = NULL;
	}
	else
	{
		env = (char **)malloc(sizeof(char *) * 4);
		env[0] = "USER=fbecht";
		env[1] = "CROISSANT=french";
		env[2] = "LATE_LUNCH=Marco";
		env[3] = NULL;
	}
	var_expansion(ptr, env);
	printf("------ AFTER VAR-EXPANSION ------\n");
	printf_ptrs(ptr);
	printf("\n\n");

	return (0);
}*/



/************* FOR SPLITTING *************/
/*int	main(int argc, char **argv)
{
	char	**ptr;

	if (argc == 1)
		return (1);
	ptr = split_usr_input(argv[1]);
	printf("split_input_by_space DONE\n");
	printf_ptrs(ptr);
	printf("\n");
	return (0);
}*/
