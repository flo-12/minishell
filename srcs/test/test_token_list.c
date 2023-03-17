/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_token_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:52:25 by mvomiero          #+#    #+#             */
/*   Updated: 2023/03/16 16:27:24 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* static void	print_token_type(t_token *token, char *prefix)
{
	printf("%s", prefix);
	if (token->type == SPACES)
		printf("SPACES\n");
	else if (token->type == WORD)
		printf("WORD\n");
	else if (token->type == VAR)
		printf("VAR\n");
	else if (token->type == PIPE)
		printf("PIPE\n");
	else if (token->type == INPUT)
		printf("INPUT\n");
	else if (token->type == TRUNC)
		printf("TRUNC\n");
	else if (token->type == HEREDOC)
		printf("HEREDOC\n");
	else if (token->type == APPEND)
		printf("APPEND\n");
	else if (token->type == END)
		printf("END\n");
}

void	print_token_list(t_token **tokens)
{
	t_token	*lst;
	int		i;

	lst = *tokens;
	printf("\n---- TOKEN LIST\n");
	i = 0;
	while (lst)
	{
		printf("--- Token [%d] [%p]\n", i, lst);
		printf("\tString = [%s]\n", lst->str);
		printf("\tStr backup = [%s]\n", lst->str_backup);
		print_token_type(lst, "\tType = ");
		printf("\tStatus = %d\n", lst->status);
		if (lst->prev)
			printf("\tPrev = [%p]\n", lst->prev);
		else
			printf("\tPrev = NULL\n");
		if (lst->next)
			printf("\tNext = [%p]\n", lst->next);
		else
			printf("\tNext = NULL\n");
		i++;
		lst = lst->next;
	}
} */


void test_token_list(t_data *data)
{
	char	*tests[] = {
		"input_1",
		"expected output_1",
		"input_2",
		"expected output_2",
		NULL
	};

	(void)data;
	for (int i = 0; tests[i]; i += 2)
	{
		printf("Input: %s\n", tests[i]);
		printf("Expected output: %s\n", tests[i + 1]);
/* 		data->user_input = tests[i];
		if (lexer(data))
			print_token_list(data->token); */
	}
}




/* 
// OLD VERSION ---- To delete

void	test()
{
	int	fd_in;
	int	fd_out;
	int	fd_test;

	fd_in = open("./test/test_files/in.txt", O_RDONLY);
	fd_out = open("./test/test_files/out.txt", O_RDONLY);
	fd_test = open("./test/test_files/in.txt", O_RDWR);

	char *in = get_next_line(fd_in);
	char *out = get_next_line(fd_out);
	char *test = get_next_line(fd_test);

	if (ft_strncmp(out, test, ft_strlen(out)))
		printf ("%sOK!\n", in);
	
	close(fd_in);
	close(fd_out);
	close(fd_test);
} */