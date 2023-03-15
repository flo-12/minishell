/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_token_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:52:25 by mvomiero          #+#    #+#             */
/*   Updated: 2023/03/15 18:06:29 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
}