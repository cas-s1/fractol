/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:56:21 by co-neill          #+#    #+#             */
/*   Updated: 2024/01/26 11:22:48 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_b_params(t_context *c)
{
	c->name = "burningship";
	c->fractal = BURNINGSHIP;
	c->max.x = 2.0;
	c->max.y = 2.0;
	c->min.x = -2.0;
	c->min.y = -2.0;
}

int	ft_burningship(t_context *c, double re, double im)
{
	t_complex	z;
	int			i;

	z = ft_complex_init(0, 0);
	i = -1;
	while (i++ < c->iter_max)
	{
		if (z.r > 2.0)
			break ;
		if (z.x < 0)
			z.x *= -1;
		if (z.y < 0)
			z.y *= -1;
		z = ft_complex_square(z);
		z.x += re;
		z.y += im;
	}
	return (i);
}
