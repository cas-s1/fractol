/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 11:36:26 by co-neill          #+#    #+#             */
/*   Updated: 2023/04/29 15:38:12 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fill_str(char *s, long n, int digits, int sign)
{
	s[digits] = '\0';
	while (digits-- > sign)
	{
		s[digits] = (n % 10) + 48;
		n /= 10;
	}
	if (sign != 0)
		s[0] = 45;
	return (s);
}

static int	count_digits_abs(const unsigned int n)
{
	unsigned int	digits;
	unsigned int	tmp;

	digits = 0;
	tmp = n;
	if (n == 0)
		return (1);
	while (tmp > 0)
	{
		tmp /= 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	int		sign;
	int		i;

	nb = n;
	sign = 0;
	i = 0;
	if (nb < 0)
	{
		nb *= -1;
		sign = 1;
		i++;
	}
	i += count_digits_abs(nb);
	str = (char *) malloc((i + 1) * sizeof(char));
	if (!str)
		return (0);
	str = fill_str(str, nb, i, sign);
	return (str);
}
