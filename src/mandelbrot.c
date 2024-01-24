/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:27:56 by co-neill          #+#    #+#             */
/*   Updated: 2024/01/24 16:34:30 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	ft_m_params(t_context *context)
{
	context->name = "mandelbrot";
	context->fractal = MANDELBROT;
	context->iter_max = 128;
	context->limit = MAX_ITERS;
}
