/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:57:53 by mvomiero          #+#    #+#             */
/*   Updated: 2022/12/03 13:26:13 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
}

/* void ft_string_op(unsigned int n, char *c)
{
	if (n % 5 == 0)
	{
		c[n] = '*';
		if (c[n + 1])
			c[n + 1] = '-';
	}
}

int	main(void)
{
	char	str[] = "Buongiorno Buongiornissimo";
	ft_striteri(str, &ft_string_op);
	printf("%s\n", str);
} */
