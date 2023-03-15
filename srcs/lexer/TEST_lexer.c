
#include "../../includes/minishell_flo.h"
#include <stdio.h>

// cc TEST_lexer.c split_usr_input.c lexer_utils.c -L../../libft/ -lft

int	main(int argc, char **argv)
{
	char	**ptr;

	if (argc == 1)
		return (1);
	ptr = split_usr_input(argv[1]);
	if (!ptr)
		printf("ptr == NULL\n");
	while (*ptr)
	{
		printf("%s,", *ptr);
		ptr++;
	}
	printf("\n");
	return (0);
}