/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:54:37 by co-neill          #+#    #+#             */
/*   Updated: 2024/01/25 11:27:07 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_j_params(t_context *c, double re, double im)
{
	c->name = "julia";
	c->fractal = JULIA;
	c->iter_max = 128;
	c->limit = MAX_ITERS;
	c->max.x = 2.0;
	c->max.y = 2.0;
	c->min.x = -2.0;
	c->min.y = -2.0
	c->julia_values.x = re;
	c->julia_values.y = im;
}
