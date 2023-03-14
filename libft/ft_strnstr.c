/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:25:09 by mvomiero          #+#    #+#             */
/*   Updated: 2022/12/09 17:41:04 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (i < len && haystack[i])
	{
		j = 0;
		while (i + j < len && haystack[i + j] == needle[j] && needle[j])
			j++;
		if (needle[j] == '\0')
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}

/* 
Quite easy. You have to look for the needle in the haystack, and return the 
pointer poistion of the needle. 
So: you do two iterators, a nested loop to check the recurrence of the needle.
to have i and j separated is quite good, so you don't grow the i and you can dir
ectly use it for the return value.

NB: Had after to put the first if conditition. It works for needle = "" or somet
hing similar...you still have to return haystack and not NULL.
 */

/* int main(void)
{
	// Example direct from the man ahahah
	const char *largestring = "Foo Bar Baz";
	const char *smallstring = "Bar";
	char *ptr;

	ptr = ft_strnstr(largestring, smallstring, 10);
	printf("%s\n", ptr);

} */