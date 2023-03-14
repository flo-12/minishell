/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:48:19 by mvomiero          #+#    #+#             */
/*   Updated: 2022/12/12 11:16:37 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}

/* 

You just iterate backwords and return the pointer to the first character
 you found.
 */

/* int main(void)
{
	char str[] = "Marcolirno";
	printf("%p\n", str);
	printf("%s\n", str);
	printf("%p\n", ft_strrchr(str, 'r'));
	printf("%s\n", ft_strrchr(str, 'r'));
	printf("%p\n", ft_strrchr(str, 'z'));
	printf("%s\n", ft_strrchr(str, 'z'));
	printf("%p\n", strrchr(str, 'z'));
	printf("%s\n", strrchr(str, 'z'));
	printf("%p\n", strrchr(str, 'r'));
	printf("%s\n", strrchr(str, 'r'));

} */
