/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:12:12 by mvomiero          #+#    #+#             */
/*   Updated: 2022/12/12 11:17:44 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	slen;
	size_t	i;

	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = 0;
	return (sub);
}

/* 
to make a malloc allocated substring starting at start and going on for the len
ght len. Quite easy then, just with a loop and two iterators.

those two lines:
if (len > slen - start)
	len = slen - start;
it is just because if not you allocate to much space with malloc!
 */

/* int main(void)
{
	char	src[] = "Buongiorno Marco";
	char	*str = ft_substr(src, 4, 10);
	printf("%s\n", str);
} */
