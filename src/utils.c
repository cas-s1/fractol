/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:01:59 by co-neill          #+#    #+#             */
/*   Updated: 2024/01/24 16:34:52 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

t_complex	ft_complex_init(double re, double im)
{
	t_complex	z;

	z.x = re;
	z.y = im;
	z.r = ft_modulus(z);
	return (z);
}

double	ft_atod(char *s)
{
	int		zeros;
	char	*dot;
	double	left;
	double	right;

	if (!s)
		return (0.0);
	left = ft_atoi(s);
	dot = ft_strchr(s, 46);
	if (!dot)
		return (left);
	zeros = 0;
	dot++;
	while (*dot++ == 48)
		zeros++;
	dot -= zeros + 1;
	right = ft_atoi(dot);
	while (right >= 1)
		right /= 10.0;
	while (zeros-- != 0)
		right /= 10.0;
	if (s[0] == 45)
		return ((left + right) * -1);
	return (left + right);
}

void	ft_pixel_to_image(t_img *data, int x, int y, int colour)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *) dst = colour;
}
