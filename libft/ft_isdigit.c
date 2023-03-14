/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:11:14 by mvomiero          #+#    #+#             */
/*   Updated: 2022/11/29 17:16:52 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

/* int main(void)
{
	printf("%d\n", ft_isdigit('0'));
	printf("%d\n", ft_isdigit('a'));
	printf("%d\n", isdigit('0'));
	printf("%d\n", isdigit('a'));
} */