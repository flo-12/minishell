/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:04:43 by mvomiero          #+#    #+#             */
/*   Updated: 2022/12/08 19:06:49 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
		write(fd, &c, 1);
}

/* 
So quite easy. instead the standard output, you just "write" the char to the
fd output. fd is an int and corresponds to the opening of a file, as you can see
in the main here under. Parameters to the open function below are the name of 
the file and some options (write, create, append...)

 */

/* int	main(void)
{
	int	fd;
	fd = open("42", O_WRONLY | O_CREAT | O_APPEND);
	ft_putchar_fd('c', fd);
} */
