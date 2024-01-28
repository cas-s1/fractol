/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:48:26 by co-neill          #+#    #+#             */
/*   Updated: 2024/01/28 16:43:30 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

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
	t_img		img;
	t_pos		pix;
	t_complex	julia_values;
	t_complex	max;
	t_complex	min;
}	t_context;

#endif
