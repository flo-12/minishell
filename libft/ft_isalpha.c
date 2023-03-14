/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:55:06 by mvomiero          #+#    #+#             */
/*   Updated: 2022/11/29 17:12:04 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/* int main(void)
{
	printf("%d\n", ft_isalpha('a'));
	printf("%d\n", ft_isalpha('1'));
	printf("%d\n", isalpha('a'));
	printf("%d\n", isalpha('1'));

} */