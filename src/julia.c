/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:54:37 by co-neill          #+#    #+#             */
/*   Updated: 2024/01/24 17:09:04 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	ft_j_params(t_context *context, double re, double im)
{
	context->name = "julia";
	context->fractal = JULIA;
	context->iter_max = 128;
	context->limit = MAX_ITERS;
	context->julia_values.x = re;
	context->julia_values.y = im;
}
