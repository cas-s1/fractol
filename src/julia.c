/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:54:37 by co-neill          #+#    #+#             */
/*   Updated: 2024/01/26 11:48:50 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_j_params(t_context *c, double re, double im)
{
	c->name = "julia";
	c->fractal = JULIA;
	c->max.x = 2.0;
	c->max.y = 2.0;
	c->min.x = -2.0;
	c->min.y = -2.0;
	c->julia_values.x = re;
	c->julia_values.y = im;
}

int	ft_julia(t_context *c, double re, double im)
{
	t_complex	z;
	int			i;

	z = ft_complex_init(re, im);
	i = -1;
	while (i++ < c->iter_max)
	{
		if (z.r > 2.0)
			break ;
		z = ft_complex_square(z);
		z.x += c->julia_values.x;
		z.y += c->julia_values.y;
	}
	return (i);
}
