/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:14:23 by mvomiero          #+#    #+#             */
/*   Updated: 2022/12/06 17:50:56 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (s1[i] == 0)
			return (0);
		i++;
	}
	return (0);
}

/* 
Quite easy...you yust go on until the string is not finished, the char are the
same and the iterator is less then n...then you give back the value of the char
casted to unsigned int (that is how they want it - see man pages)
 */

/* 
this was a previous version, didnt work because of the lacking in the comparison
of the conversion to an unsigned char...like for example with strings "".
Another problem was with the final if condition because n can actually be 0.
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
		i ++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
} */

/* int main(void)
{
	char str1[] = "Marcolino";
	char str2[] = "Marcalino";
	printf("%s\n", str1);
	printf("%s\n", str2);
	printf("%d\n", ft_strncmp(str1, str2, 0));
	printf("%d\n", ft_strncmp(str1, str2, 8));
	printf("%c\n", ft_strncmp(str1, str2, 8));
	printf("Now with the built-in function\n");
	printf("%d\n", strncmp(str1, str2, 0));
	printf("%d\n", strncmp(str1, str2, 8));
	printf("%c\n", strncmp(str1, str2, 8));

} */
