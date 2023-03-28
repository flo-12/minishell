
#include "../../includes/minishell_flo.h"
#include <stdio.h>

// cc test_lexer_partially.c ../lexer/quote_removal.c ../lexer/tokenization.c ../lexer/token_list_utils.c ../lexer/var_expansion.c ../lexer/split_usr_input.c ../lexer/lexer_utils.c -L../../libft/ -lft -o test_lexer.out
// valgrind: valgrind --leak-check=full ./test_lexer.out 'cd ../../../'

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

void	printf_token(t_token *token)
{
	int	i;
	if (!token)
	{
		printf("token == NULL\n");
		return ;
	}
	i = 0;
	printf("%6s|%6s|%10s\n", "index", "type", "str");
	while (token)
	{
		printf("%6d|%6d|%10s\n", i, token->type, token->str);
		token = token->next;
		i++;
	}
}

int	main(int argc, char **argv)
{
	char 	**ptr;
	char	**env;
	t_token	*token;
	_Bool	output_split = true;
	_Bool	output_varExp = true;
	_Bool	output_token = true;
	_Bool	output_quote = true;

	if (argc == 1)
		return (1);
	
	/******** SPLIT USER INPUT ********/
	ptr = split_usr_input(argv[1]);
	if (output_split)
	{
		printf("------ AFTER SPLIT ------\n");
		printf_ptrs(ptr);
		printf("\n\n");
	}

	/******** VARIABLE EXPANSION ********/
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
		env[0] = "ME=fbecht";
		env[1] = "CROISSANT=french";
		env[2] = "LATE_LUNCH=Marco";
		env[3] = NULL;
	}
	var_expansion(ptr, env);
	free(env);
	if (output_varExp)
	{
		printf("------ AFTER VAR-EXPANSION ------\n");
		printf_ptrs(ptr);
		printf("\n\n");
	}

	/******** TOKENIZATION ********/
	token = tokenization(ptr);
	if (output_token)
	{
		printf("------ AFTER TOKENIZATION ------\n");
		printf_token(token);
		printf("\n\n");
	}
	free_ptr(ptr);

	/******** QUOTE REMOVAL ********/
	quote_removal(token);
	if (output_quote)
	{
		printf("------ AFTER QUOTE REMOVAL ------\n");
		printf_token(token);
		printf("\n\n");
	}
	token_lstclear(&token);

	return (0);
}
