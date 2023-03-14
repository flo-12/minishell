/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:41:54 by mvomiero          #+#    #+#             */
/*   Updated: 2022/12/01 17:13:57 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * sign);
}

/* int main(void)
{

	printf("%d\n", atoi(" -124"));
	printf("%d\n", ft_atoi(" -124"));
	printf("%d\n", atoi("25"));
	printf("%d\n", ft_atoi(" 25"));
	printf("%d\n", atoi("-2147483648"));
	printf("%d\n", ft_atoi("-2147483648"));
	printf("%d\n", INT_MIN);
} */
