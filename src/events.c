/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:39:36 by co-neill          #+#    #+#             */
/*   Updated: 2024/01/28 21:58:11 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void	ft_move(int keycode, t_context *c)
{
	if (keycode == KEY_UP || keycode == KEY_W)
	{
		c->max.y -= 0.1 * (c->max.y - c->min.y);
		c->min.y -= 0.1 * (c->max.y - c->min.y);
	}
	else if (keycode == KEY_LEFT || keycode == KEY_A)
	{
		c->max.x -= 0.1 * (c->max.y - c->min.y);
		c->min.x -= 0.1 * (c->max.y - c->min.y);
	}
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
	{
		c->max.x += 0.1 * (c->max.y - c->min.y);
		c->min.x += 0.1 * (c->max.y - c->min.y);
	}
	else if (keycode == KEY_DOWN || keycode == KEY_S)
	{
		c->max.y += 0.1 * (c->max.y - c->min.y);
		c->min.y += 0.1 * (c->max.y - c->min.y);
	}
}

static void	ft_zoom(t_context *c, double re, double im, int direction)
{
	double	width;
	double	height;

	width = c->max.x - c->min.x;
	height = c->max.y - c->min.y;
	if (direction == SCROLL_UP)
	{
		width /= 1.05;
		height /= 1.05;
	}
	else if (direction == SCROLL_DOWN)
	{
		width *= 1.05;
		height *= 1.05;
	}
	c->max.x = re + (width / 4);
	c->max.y = im + (height / 4);
	c->min.x = re - (width / 4);
	c->min.y = im - (height / 4);
}

static void	ft_change_iterations(int keycode, t_context *c)
{
	if (keycode == KEY_PLUS)
		c->iter_max += 10;
	else if (keycode == KEY_MINUS)
		c->iter_max -= 10;
	if (c->iter_max > c->limit)
		c->iter_max = c->limit;
	else if (c->iter_max < 2)
		c->iter_max = 2;
}

int	ft_key_input(int keycode, t_context *c)
{
	if (keycode == KEY_ESC)
		ft_clean_and_exit(c);
	else if (keycode == KEY_C)
		ft_change_colours(c);
	else if (keycode == KEY_M)
		ft_m_params(c);
	else if (keycode == KEY_J)
		ft_j_params(c, ft_generate_random(), ft_generate_random());
	else if (keycode == KEY_B)
		ft_b_params(c);
	else if (keycode == KEY_PLUS || keycode == KEY_MINUS)
		ft_change_iterations(keycode, c);
	else
		ft_move(keycode, c);
	ft_draw_fractal(c);
	return (0);
}

int	ft_mouse_input(int mousecode, int x, int y, t_context *c)
{
	t_complex	centre;

	centre.x = c->min.x + ((double) x * (c->max.x - c->min.x) / W);
	centre.y = c->min.y + ((double) y * (c->max.y - c->min.y) / H);
	if (mousecode == SCROLL_UP)
		ft_zoom(c, centre.x, centre.y, SCROLL_UP);
	else if (mousecode == SCROLL_DOWN)
		ft_zoom(c, centre.x, centre.y, SCROLL_DOWN);
	ft_draw_fractal(c);
	return (0);
}
