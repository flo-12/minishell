/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:27:41 by mvomiero          #+#    #+#             */
/*   Updated: 2022/12/08 19:08:51 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (fd >= 0)
	{
		ft_putstr_fd(s, fd);
		ft_putchar_fd('\n', fd);
	}
}

/* int	main(void)
{
	int	fd;
	fd = open("42", O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
	ft_putendl_fd("Buongiorno\n", fd);
	ft_putendl_fd("Buongiornissimo\n", fd);
} */
