/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 11:21:53 by co-neill          #+#    #+#             */
/*   Updated: 2024/01/28 16:30:10 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include "../libft/libft.h"
# include <mlx.h>
# include "colours.h"
# include "structs.h"
# include "keys.h"

// CONSTANTS
# define W 640
# define H 360
# define MANDELBROT_DEFAULT_RE 0
# define MANDELBROT_DEFAULT_IM 0
# define JULIA_DEFAULT_RE -1
# define JULIA_DEFAULT_IM 0
# define MAX_ITERS 512
# define MANDELBROT 1
# define JULIA 2
# define BURNINGSHIP 3

// fractol.c
int			ft_clean_and_exit(t_context *c);

// utils.c
t_complex	ft_complex_init(double re, double im);
double		ft_atod(char *s);
void		ft_pixel_to_image(t_img *data, int x, int y, int colour);
int			ft_calculate_pixel(t_context *c, double re, double im);
void		ft_draw_fractal(t_context *c);

// math.c
double		ft_sqrt(double nb);
double		ft_modulus(t_complex z);
t_complex	ft_complex_sum(t_complex a, t_complex b);
t_complex	ft_complex_multiply(t_complex a, t_complex b);
t_complex	ft_complex_square(t_complex z);

// mandelbrot.c
void		ft_m_params(t_context *c);
int			ft_mandelbrot(t_context *c, double re, double im);

// julia.c
void		ft_j_params(t_context *c, double re, double im);
int			ft_julia(t_context *c, double re, double im);

// burningship.c
void		ft_b_params(t_context *c);
int			ft_burningship(t_context *c, double re, double im);

// colours.c
void		ft_init_colours(t_context *c);
void		ft_change_colours(t_context *c);

// events.c
int			ft_key_input(int keycode, t_context *c);
int			ft_mouse_input(int mousecode, int x, int y, t_context *c);

#endif
