/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 08:17:13 by co-neill          #+#    #+#             */
/*   Updated: 2024/01/24 15:02:38 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

double	ft_sqrt(double nb)
{
	double	x;
	int		i;

	if (nb <= 0)
		return (0);
	x = nb / 2;
	i = 0;
	while (i++ <= 4)
		x = 0.5 * (x + (nb / x));
	return (x);
}

double	ft_modulus(t_complex z)
{
	double	res;

	res = ft_sqrt((z.x * z.x) + (z.y * z.y));
	return (res);
}

t_complex	ft_complex_sum(t_complex a, t_complex b)
{
	t_complex	res;

	res.x = a.x + b.x;
	res.y = a.y + b.y;
	res.r = ft_modulus(res);
	return (res);
}

t_complex	ft_complex_multiply(t_complex a, t_complex b)
{
	t_complex	res;

	res.x = (a.x * b.x) - (a.y * b.y);
	res.y = (a.x * b.y) + (a.y * b.x);
	res.r = ft_modulus(res);
	return (res);
}

t_complex	ft_complex_square(t_complex z)
{
	t_complex	res;

	res = ft_complex_multiply(z, z);
	return (res);
}
