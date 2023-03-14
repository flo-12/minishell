/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:45:51 by mvomiero          #+#    #+#             */
/*   Updated: 2022/11/30 16:05:19 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*str;

	str = (char *)b;
	while (len > 0)
	{
		str[len - 1] = c;
		len--;
	}
	return (b);
}

/* first, you create a char string. Then you cast the type of b and convert it 
to str. then you just fill everything starting from the end. It's the size that 
counts not the null teminator. */

/* 
This is an alternative
{
	int	i;

	i = 0;
	while (i < (int)len)
	{
		((char*)b)[i] = ((unsigned char)c);
		i++;
	}
	return (b);
} */

/* 
this is the main to check it!
int main(void)
{
	void	*b;
	char	*r;

	b = malloc(sizeof(char) * 5);
	//r = ft_memset(b, 'a', 4);
	r = "ciao";
	printf("%s\n", r);
	r = ft_memset(b, 'a', 4);
	printf("%s\n", r);
	//printf("%d\n", ft_strlen("Marco"));

	printf("Ciao marcolino\n");
} */
