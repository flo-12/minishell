/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:50:43 by mvomiero          #+#    #+#             */
/*   Updated: 2022/12/02 19:15:07 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = 0;
	return (str);
}

/* 
This is a random function I created to have some string manipulation.
So it will complete with '*' all the characters with index > then 8, 
and the other it just makes an inversion of from lower to upper of the contrary.

char ft_string_op(unsigned int n, char c)
{
	if (n > 8)
		return ('*');
	else
	{
		if (c >= 'a' && c <= 'z')
			return (c - 32);
		else if (c >= 'A' && c <= 'Z')
			return (c + 32);
		return (c);
	}
}

int	main(void)
{

	printf("%s\n", ("Buongiornissimo\n"));
	printf("%s\n", ft_strmapi("Buongiornissimo", &ft_string_op));
} */
