/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 11:21:53 by co-neill          #+#    #+#             */
/*   Updated: 2024/01/25 11:19:43 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include <mlx.h>

// LINUX KEYCODES
# ifdef __linux__
#  define KEY_ESC 65307
#  define KEY_W 119
#  define KEY_A 97
#  define KEY_S 115
#  define KEY_D 100
#  define KEY_UP 65362
#  define KEY_DOWN 65364
#  define KEY_LEFT 65361
#  define KEY_RIGHT 65363
#  define KEY_PLUS 61
#  define KEY_MINUS 45
#  define KEY_1 49
#  define KEY_2 50
#  define KEY_3 51
#  define KEY_4 52
#  define KEY_M 58
#  define KEY_J 44
#  define KEY_B 56
#  define SCROLL_UP 4
#  define SCROLL_DOWN 5

// MACOS KEYCODES
# else
#  define KEY_ESC 53
#  define KEY_W 13
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_UP 126
#  define KEY_DOWN 125
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
#  define KEY_PLUS 24
#  define KEY_MINUS 27
#  define KEY_1 18
#  define KEY_2 19
#  define KEY_3 20
#  define KEY_4 21
#  define KEY_M 46
#  define KEY_J 38
#  define KEY_B 11
#  define SCROLL_UP 4
#  define SCROLL_DOWN 5
# endif

// CONSTANTS
# define W 1280
# define H 720
# define MANDELBROT_DEFAULT_RE 0
# define MANDELBROT_DEFAULT_IM 0
# define JULIA_DEFAULT_RE -1
# define JULIA_DEFAULT_IM 0
# define MAX_ITERS 512
# define MANDELBROT 1
# define JULIA 2
# define BURNINGSHIP 3

// STRUCTS

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_complex
{
	double	x;
	double	y;
	double	r;
}	t_complex;

typedef struct s_context
{
	void		*mlx;
	void		*win;
	char		*name;
	int			*colours;
	int			colour_index;
	int			fractal;
	int			iter_max;
	int			limit;
	t_pos		pix;
	t_img		img;
	t_complex	julia_values;
	t_complex	max;
	t_complex	min;
}	t_context;

// fractol.c
int			ft_destroy_window(t_context *context);

// utils.c
t_complex	ft_complex_init(double re, double im);
double		ft_atod(char *s);
void		ft_pixel_to_image(t_img *data, int x, int y, int colour);

// math.c
double		ft_sqrt(double nb);
double		ft_modulus(t_complex z);
t_complex	ft_complex_sum(t_complex a, t_complex b);
t_complex	ft_complex_multiply(t_complex a, t_complex b);
t_complex	ft_complex_square(t_complex z);

// mandelbrot.c
void	ft_m_params(t_context *context);

// julia.c
void	ft_j_params(t_context *context, double re, double im);

// burningship.c
void	ft_b_params(t_context *context);

#endif
