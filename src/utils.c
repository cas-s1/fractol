/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:01:59 by co-neill          #+#    #+#             */
/*   Updated: 2024/01/25 11:44:05 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

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

int	ft_calculate_pixel(t_context *c, double re, double im)
{
	if (c->fractal == MANDELBROT)
		return (ft_mandelbrot(c, re, im));
	else if (c->fractal == JULIA)
		return (ft_julia(c, re, im));
	else if (c->fractal == BURNINGSHIP)
		return (ft_burningship(c, re, im));
	else
		return (0);
}

void	ft_draw_fractal(t_context *c)
{
	double	re;
	double	im;
	int		i;

	mlx_clear_window(c->mlx, c->win);
	c->pix.y = -1;
	while (c->pix.y++ < H)
	{
		c->pix.x = -1;
		while (c->pix.x++ < W)
		{
			re = c->min.x + ((double) c->pix.x * (c->max.x - c->min.x) / W);
			im = c->min.y + ((double) c->pix.y * (c->max.y - c->min.y) / H);
			i = ft_calculate_pixel(c, re, im);
			if (i == c->iter_max)
				ft_pixel_to_image(&c->img, c->pix.x, c->pix.y, 0xFFFFFF);
			else
				ft_pixel_to_image(&c->img, c->pix.x, c->pix.y, 0x000000);
		}
	}
	mlx_put_image_to_window(c->mlx, c->win, c->img.img, 0, 0);
}
