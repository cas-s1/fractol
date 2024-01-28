/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:27:56 by co-neill          #+#    #+#             */
/*   Updated: 2024/01/26 18:07:13 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_m_params(t_context *c)
{
	c->name = "mandelbrot";
	c->fractal = MANDELBROT;
	c->max.x = 1.0;
	c->max.y = 1.5;
	c->min.x = -3.0;
	c->min.y = -1.5;
}

int	ft_mandelbrot(t_context *c, double re, double im)
{
	t_complex	z;
	int			i;

	z = ft_complex_init(0, 0);
	i = -1;
	while (i++ < c->iter_max)
	{
		if (ft_modulus(z) > 2.0)
			break ;
		z = ft_complex_square(z);
		z.x += re;
		z.y += im;
	}
	return (i);
}
