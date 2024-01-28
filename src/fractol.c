/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 10:44:11 by co-neill          #+#    #+#             */
/*   Updated: 2024/01/28 22:09:36 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void	ft_init_global(t_context *c)
{
	c->mlx = mlx_init();
	c->win = mlx_new_window(c->mlx, W, H, c->name);
	c->img.img = mlx_new_image(c->mlx, W, H);
	c->img.addr = mlx_get_data_addr(c->img.img, 
			&c->img.bpp, &c->img.line_len, &c->img.endian);
	c->iter_max = 64;
	c->limit = MAX_ITERS;
	c->colour_index = 0;
	ft_init_colours(c);
	mlx_hook(c->win, 17, 0, ft_clean_and_exit, c);
	mlx_key_hook(c->win, ft_key_input, c);
	mlx_mouse_hook(c->win, ft_mouse_input, c);
	if (!c->mlx || !c->win || !c->img.img || !c->colours)
	{
		ft_putstr_fd("Memory allocation failure", 2);
		exit(1);
	}
}

int	ft_clean_and_exit(t_context *c)
{
	mlx_clear_window(c->mlx, c->win);
	mlx_destroy_image(c->mlx, c->img.img);
	mlx_destroy_window(c->mlx, c->win);
	mlx_destroy_display(c->mlx);
	free(c->colours);
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

static void	ft_print_controls(void)
{
	ft_putstr_fd("- Use arrow keys or WASD to move around the fractal\n", 1);
	ft_putstr_fd("- Zoom to mouse position by scrolling\n", 1);
	ft_putstr_fd("- Using the C key will cycle through colour options\n", 1);
	ft_putstr_fd("- Use M, J and B keys to switch fractal\n", 1);
	ft_putstr_fd("- Using the J key will generate a random parameter\n", 1);
	ft_putstr_fd("- + / - will add / reduce iterations\n", 1);
	ft_putstr_fd("- Use the ESC key or window cross to exit\n", 1);
}

int	main(int ac, char **av)
{
	t_context	c;

	if (ac < 2 || ac > 4)
		ft_program_instructions();
	else if (!ft_strncmp(av[1], "mandelbrot", 11) && ac == 2)
		ft_m_params(&c);
	else if (!ft_strncmp(av[1], "julia", 6) && ac == 2)
		ft_j_params(&c, JULIA_DEFAULT_RE, JULIA_DEFAULT_IM);
	else if (!ft_strncmp(av[1], "julia", 6) && ac == 4
		&& (ft_atod(av[2]) || ft_atod(av[3])))
		ft_j_params(&c, ft_atod(av[2]), ft_atod(av[3]));
	else if (!ft_strncmp(av[1], "burningship", 12) && ac == 2)
		ft_b_params(&c);
	else
		ft_program_instructions();
	ft_init_global(&c);
	ft_draw_fractal(&c);
	ft_print_controls();
	mlx_loop(c.mlx);
	return (0);
}
