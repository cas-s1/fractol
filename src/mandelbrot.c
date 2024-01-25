/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:27:56 by co-neill          #+#    #+#             */
/*   Updated: 2024/01/25 11:25:06 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_m_params(t_context *c)
{
	c->name = "mandelbrot";
	c->fractal = MANDELBROT;
	c->iter_max = 128;
	c->limit = MAX_ITERS;
	c->max.x = 2.0;
	c->max.y = 2.0;
	c->min.x = -2.0;
	c->min.y = -2.0;
}
