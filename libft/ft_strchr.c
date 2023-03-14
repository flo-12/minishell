/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:38:21 by mvomiero          #+#    #+#             */
/*   Updated: 2022/12/06 11:02:44 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}

/* 
You just iterate and return the pointer to the found character.
the second if statement is in the case the character is equal to the null termi
nator, then you have to return the pointer to the null terminator.
NULL if you find nothing.
 */

/* int main(void)
{
	char str[] = "Marcolino";
	printf("%p\n", str);
	printf("%s\n", str);
	printf("%p\n", ft_strchr(str, 'r'));
	printf("%s\n", ft_strchr(str, 'r'));
	printf("%p\n", ft_strchr(str, 'z'));
	printf("%s\n", ft_strchr(str, 'z'));
	printf("%p\n", strchr(str, 'r'));
	printf("%s\n", strchr(str, 'r'));

} */
