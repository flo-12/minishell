/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:38:15 by mvomiero          #+#    #+#             */
/*   Updated: 2022/12/12 11:42:49 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*str1;
	char	*str2;

	i = 0;
	str1 = (char *)s1;
	str2 = (char *)s2;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}

/*
A bit like strcmp
 */

/* int main(void)
{
	char str1[] = "Marcolino";
	char str2[] = "Marcalino";
	printf("%s\n", str1);
	printf("%s\n", str2);
	printf("%d\n", ft_memcmp(str1, str2, 0));
	printf("%d\n", ft_memcmp(str1, str2, 8));
	printf("%c\n", ft_memcmp(str1, str2, 8));
	printf("Now with the built-in function\n");
	printf("%d\n", memcmp(str1, str2, 0));
	printf("%d\n", memcmp(str1, str2, 8));
	printf("%c\n", memcmp(str1, str2, 8));

} */