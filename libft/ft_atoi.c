/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 23:24:40 by co-neill          #+#    #+#             */
/*   Updated: 2023/04/25 10:42:00 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	res;

	sign = 1;
	res = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
	{
		str++;
	}
	if (*str == 45)
	{
		sign *= -1;
		str++;
	}
	else if (*str == 43)
		str++;
	while (*str > 47 && *str < 58)
	{
		res = res * 10 + *str - 48;
		str++;
	}
	return (res * sign);
}
/*
int	main(void)
{
	char testStr[] = "    \n  +37";
	printf("%d\n", ft_atoi(testStr));
	return (0);
}
*/
