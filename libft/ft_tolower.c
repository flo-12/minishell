/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:59:27 by mvomiero          #+#    #+#             */
/*   Updated: 2022/12/01 12:12:23 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

/* int main(void)
{
	printf("%c\n", ft_tolower('C'));
	printf("%c\n", ft_toupper('a'));
	printf("%c\n", tolower('C'));
	printf("%c\n", toupper('a'));

} */