/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:18:55 by mvomiero          #+#    #+#             */
/*   Updated: 2022/12/06 11:45:25 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	s_len;
	size_t	d_len;

	s_len = ft_strlen(src);
	d_len = ft_strlen(dst);
	j = d_len;
	i = 0;
	if ((d_len < dstsize - 1) && dstsize > 0)
	{
		while (src[i] && d_len + i < dstsize - 1)
		{
			dst[j] = src[i];
			i++;
			j++;
		}
		dst[j] = 0;
	}
	if (d_len >= dstsize)
		d_len = dstsize;
	return (d_len + s_len);
}

/* 
you go to the end of dest, copy src, finish with null.
J and not d_len because the destination can be longer of course.
 */

/* 
had problems before becuse not putting the last if statement. It is
important because dstsize can be even 0. 
 */

/* int main(void)
{
	char	*dest = (char *)malloc (sizeof(char) * 15);
	dest[0] = 'c';
	char	src[] = "Ciao";
	
	//printf("%s\n", dest);
	ft_strlcat(dest, src, 4);
	printf("%s\n", dest);

} */
