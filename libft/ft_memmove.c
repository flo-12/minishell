/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:56:52 by mvomiero          #+#    #+#             */
/*   Updated: 2022/12/09 16:55:55 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	if (dst < src)
	{
		while (i < len)
		{
			((char *) dst)[i] = ((char *) src)[i];
			i++;
		}
	}
	else
	{
		while (i < len)
		{
			((char *) dst)[len - i - 1] = ((char *) src)[len - i - 1];
			i++;
		}
	}
	return (dst);
}

/* 
This is an older Version, but it had malloc so I changed at the end
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*temp;

	temp = (char *)malloc(sizeof(char) * len);
	if (!temp)
		return (NULL);
	ft_memcpy(temp, src, len);
	ft_memcpy(dst, temp, len);
	free (temp);
	return (dst);
} */

/* int main(void)
{
	char src[] = "Marcolino";
	// so here is actually the proof that memmove handels even overflow
	// the result of this printf will be Marcolino anyways, even if 
	// the destination is only 5. So this is the first loop.
	char dest[] = "ciao";

	ft_memmove(dest, src, 10);
	printf("%s\n", dest);

	char src2[] = "ciao";
	// so here the 
	// the result of the other loop:
	// tif I just copy the first characters then I have to go on with the others
	char dest2[] = "Marcolino";

	ft_memmove(dest2, src2, 4);
	printf("%s\n", dest2);
	printf("%s\n", dest2 + 5);
} */
