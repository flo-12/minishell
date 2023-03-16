
#include "../../includes/minishell_flo.h"
#include <stdio.h>

// cc TEST_lexer.c split_usr_input.c lexer_utils.c -L../../libft/ -lft

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

int	main(int argc, char **argv)
{
	char	**ptr;

	if (argc == 1)
		return (1);
	ptr = split_usr_input(argv[1]);
	printf("split_usr_input DONE\n");
	printf_ptrs(ptr);
	printf("\n");
	return (0);
}