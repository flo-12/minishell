/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:29:29 by mvomiero          #+#    #+#             */
/*   Updated: 2023/03/02 18:01:09 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	void	*p;

	if (count == 0 || size == 0)
		return (ft_strdup(""));
	total_size = count * size;
	if (count < ULONG_MAX / size)
	{
		p = malloc(total_size);
		if (!p)
			return (NULL);
	}
	else
		return (NULL);
	ft_bzero(p, total_size);
	return (p);
} */

void	*ft_calloc(size_t count, size_t size)
{
	void	*r;

	r = malloc(count * size);
	if (!r)
		return (NULL);
	ft_bzero(r, size * count);
	return (r);
}

/* 
From mathematics, the principle.
This was to fix some limit cases where count * size is > then size_t
count < ULONG_MAX / size
count * size < ULONG_MAX / size * size 
count * size < ULONG_MAX 

Quite easy, like malloc, but you fill the positions with 0s - for that the bzero
function is TOP.
So compared to malloc, two arguments but the principle is the same, just you don
t do the multiplication:
malloc(count * sizeof());
calloc(count, sizeof());
 */

/* 
This was just to test some functions
int main(void)
{

	if ((SIZE_MAX *SIZE_MAX) > SIZE_MAX)
		printf("yo\n");
	printf("%lu size max\n", SIZE_MAX);
	printf("%lu size max\n", (SIZE_MAX * SIZE_MAX));
	printf("%llu size bla\n", ULLONG_MAX);
	printf("%lu size long max\n", ULONG_MAX);
	printf("%llu size bla\n", (unsigned long long)(SIZE_MAX * SIZE_MAX));
	printf("%ld\n", LONG_MAX);
	printf("%ld\n", sizeof(void *));
	return (0);
} */

/* int main(void)
{

	char	*ptr;
	ptr = ft_calloc(5, sizeof(char));
	printf("%d\n", ptr[1]);

} */
