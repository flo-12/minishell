
#include "../../includes/minishell_flo.h"
#include <stdio.h>

// cc test_lexer_full.c ../lexer/lexer.c ../lexer/quote_removal.c ../lexer/tokenization.c ../lexer/token_list_utils.c ../lexer/var_expansion.c ../lexer/split_usr_input.c ../lexer/lexer_utils.c -L../../libft/ -lft -o test_lexer.out
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
	t_data	*data;
	char	**env;
	_Bool	res;

	if (argc != 2)
		return (1);
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (1);
	data->user_input = argv[1];
	data->env = (char **)malloc(sizeof(char *) * 4);
	data->env[0] = "ME=fbecht";
	data->env[1] = "CROISSANT=french";
	data->env[2] = "LATE_LUNCH=Marco";
	data->env[3] = NULL;

	res = lexer(data);
	if (!res)
	{
		perror("lexer result NULL\n");
		return (1);
	}
	printf_token(data->token);
	free(data->env);
	token_lstclear(&data->token);
	free(data);
	
	return (0);
}
