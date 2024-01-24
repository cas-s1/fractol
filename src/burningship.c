/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:56:21 by co-neill          #+#    #+#             */
/*   Updated: 2024/01/24 17:08:58 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	ft_b_params(t_context *context)
{
	context->name = "burningship";
	context->fractal = BURNINGSHIP;
	context->iter_max = 128;
	context->limit = MAX_ITERS;
}
