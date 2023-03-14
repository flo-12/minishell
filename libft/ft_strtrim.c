/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:15:29 by mvomiero          #+#    #+#             */
/*   Updated: 2022/12/06 15:47:03 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_char_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	k;

	j = 0;
	while (s1[j] && ft_char_set(s1[j], set))
		j++;
	k = ft_strlen(s1);
	while (k > j && ft_char_set(s1[k - 1], set))
		k--;
	str = (char *)malloc(sizeof(char) * (k - j + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (j < k)
	{
		str[i] = s1[j];
		j++;
		i++;
	}
	str[i] = 0;
	return (str);
}

/* 
Just trim the beginning and the end of the string s1 of the characters of set.
so you do a loop at the beginning, one at the end, and one to write the new stri
ng. 
j = start, k = end, i = iteration new string.
 */

/* int main(void)
{
	char	*str = ft_strtrim("blbablaBuongiorno! blabbla", "bla");
	printf("%s\n", str);
} */

/* 
Anoter main to test it (from the test)
int main(void)
{

	char * s = ft_strtrim("   xxxtripouillee", " x");
	printf("%s\n", s);
	return (0);
} */
