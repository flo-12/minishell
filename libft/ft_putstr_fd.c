/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:18:19 by mvomiero          #+#    #+#             */
/*   Updated: 2022/12/08 19:08:12 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (fd >= 0)
		write(fd, s, ft_strlen(s));
}

/* int	main(void)
{
	int	fd;
	fd = open("42", O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
	ft_putstr_fd("Buongiorno\n", fd);
	ft_putstr_fd("Buongiornissimo\n", fd);
} */
