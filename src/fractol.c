/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 10:44:11 by co-neill          #+#    #+#             */
/*   Updated: 2024/01/24 17:06:48 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	ft_create_window(t_context *context)
{
	context->mlx = mlx_init();
	context->win = mlx_new_window(context->mlx, WIDTH, HEIGHT, context->name);
	context->img.img = mlx_new_image(context->mlx, WIDTH, HEIGHT);
	context->img.addr = mlx_get_data_addr(context->img.img,
			&context->img.bpp, &context->img.line_len, &context->img.endian);
	if (!context->mlx || !context->win || !context->img.img)
	{
		ft_putstr_fd("MLX memory failure", 2);
		exit(1);
	}
}

int	ft_destroy_window(t_context *context)
{
	mlx_clear_window(context->mlx, context->win);
	mlx_destroy_image(context->mlx, context->img.img);
	mlx_destroy_window(context->mlx, context->win);
	mlx_destroy_display(context->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

static void	ft_program_instructions(void)
{
	ft_putstr_fd("Usage: ./fractol <fractal>\n\n", 1);
	ft_putstr_fd("Options:\n", 1);
	ft_putstr_fd("mandelbrot\njulia\nburningship\n\n", 1);
	ft_putstr_fd("Parameter can be given for Julia sets like so:\n", 1);
	ft_putstr_fd("./fractol julia <double1> <double2>\n", 1);
	ft_putstr_fd("Where each double is a value between -2.0 and 2.0\n", 1);
	exit(EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_context	context;

	if (ac < 2 || ac > 4)
		ft_program_instructions();
	else if (!ft_strncmp(av[1], "mandelbrot", 11) && ac == 2)
		ft_m_params(&context);
	else if (!ft_strncmp(av[1], "julia", 6) && ac == 2)
		ft_j_params(&context, JULIA_DEFAULT_RE, JULIA_DEFAULT_IM);
	else if (!ft_strncmp(av[1], "julia", 6) && ac == 4
		&& (ft_atod(av[2]) || ft_atod(av[3])))
		ft_j_params(&context, ft_atod(av[2]), ft_atod(av[3]));
	else if (!ft_strncmp(av[1], "burningship", 12) && ac == 2)
		ft_b_params(&context);
	else
		ft_program_instructions();
	ft_create_window(&context);
	context.limit = MAX_ITERS;
	//ft_draw(&context);
	mlx_hook(context.win, 17, 0, ft_destroy_window, &context);
	mlx_loop(context.mlx);
	return (0);
}
