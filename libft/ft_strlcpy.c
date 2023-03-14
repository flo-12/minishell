/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:48:22 by mvomiero          #+#    #+#             */
/*   Updated: 2022/11/30 18:12:02 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	while (src[i])
		i++;
	return (i);
}

/* 

you just copy the string, add the null terminator and then go on to the 
end of src because the return value is the length of the source.

Condition size > 0:
it is because if the size is 0, you don't have to put the final null terminator!

*/

/* int main(void)
{
	char	str[] = "Ciao Marc bello";
	
	ft_strlcpy(str, str + 5, 0);
	//strlcpy(str, str + 5, 0);
	printf("%s\n", str);
} */
