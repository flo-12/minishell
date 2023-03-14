/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:56:31 by mvomiero          #+#    #+#             */
/*   Updated: 2022/12/06 19:12:38 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_count(int n)
{
	size_t	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		count;
	int			sig;

	count = digit_count(n);
	str = malloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
	sig = 1;
	str[count] = '\0';
	count--;
	if (n < 0)
	{
		str[0] = '-';
		sig = -1;
	}
	else if (n == 0)
		str[count] = '0';
	while (n != 0)
	{
		str[count] = (n % 10 * sig) + '0';
		n /= 10;
		count--;
	}
	return (str);
}

/* int main(void)
{
	printf("%s\n", ft_itoa(576));
	printf("%s\n", ft_itoa(INT_MAX));
	printf("%s\n", ft_itoa(INT_MIN));
} */
