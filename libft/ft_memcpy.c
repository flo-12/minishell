/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:08:06 by mvomiero          #+#    #+#             */
/*   Updated: 2022/12/09 18:15:19 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	i = 0;
	d = (char *)dst;
	s = (char *)src;
	if (!d && !s)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

/*  With memcpy the behavior with overlapping memory is undefined (it depends 
from the complier)...so better to use memmove, wich is kinda the same).
For difference: see video from CodeVault
 */

/* int main(void)
{
	char src[] = "Marcolino";
	char dest[20];

	ft_memcpy(dest, src, 10);
	printf("%s\n", dest);

	printf("Ciao marcolino\n");
} */

/*
int main(void)
{
	char	str[] = "Ciao Marc";
	
	ft_memcpy(str, str + 5, 4);
	printf("%s\n", str);
}
*/
