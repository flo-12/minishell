/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:47:13 by mvomiero          #+#    #+#             */
/*   Updated: 2022/12/06 18:43:41 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_count_str(char const *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == c))
			i++;
		if (str[i] != 0)
			count ++;
		while (str[i] && (str[i] != c))
			i++;
	}
	return (count);
}

static	size_t	ft_str_len(char const *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static	char	*ft_str(char const *str_i, char c)
{
	char	*str_o;
	size_t	i;
	size_t	str_len;

	i = 0;
	str_len = ft_str_len(str_i, c);
	str_o = (char *)malloc(sizeof(char) * (str_len + 1));
	if (!str_o)
		return (NULL);
	while (i < str_len)
	{
		str_o[i] = str_i[i];
		i++;
	}
	str_o[i] = 0;
	return (str_o);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	i;

	i = 0;
	array = (char **)malloc(sizeof(char *) * (ft_count_str(s, c) + 1));
	if (!array)
		return (NULL);
	while (*s)
	{
		while (*s && (*s == c))
			s++;
		if (*s != 0)
		{
			array[i] = ft_str(s, c);
			i++;
		}
		while (*s && (*s != c))
			s++;
	}
	array[i] = 0;
	return (array);
}

/* 
You split the string given as parameter in substring. Kinda the same of the 
piscine, but here just one character(insted of a sep string). That makes thinks 
easier, since it's just a character, on the other hand you have to include it
as a second parameter in all other functions.
NB: for the count of strings, you use an iterator i, for building the array in 
the principal function, you use the pointer notation in order to build the 
substrings that compose the resulting array!.
 */

/* int main(void)
{
	char	**array = ft_split("ciao come stai?", ' ');
	printf("%s\n", array[0]);
	printf("%s\n", array[1]);
	printf("%s\n", array[2]);
} */

/* int main(void)
{
	char	**array = ft_split("  tripouille  42  ", ' ');
	printf("%s\n", array[0]);
	printf("%s\n", array[1]);
	printf("%s\n", array[2]);
} */
