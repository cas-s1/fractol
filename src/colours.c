/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:16:46 by co-neill          #+#    #+#             */
/*   Updated: 2024/01/28 17:38:51 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void	purple_light_to_dark(int *colours)
{
	colours[0x0] = COLOUR_PURPLE_0;
	colours[0x1] = COLOUR_PURPLE_1;
	colours[0x2] = COLOUR_PURPLE_2;
	colours[0x3] = COLOUR_PURPLE_3;
	colours[0x4] = COLOUR_PURPLE_4;
	colours[0x5] = COLOUR_PURPLE_5;
	colours[0x6] = COLOUR_PURPLE_6;
	colours[0x7] = COLOUR_PURPLE_7;
	colours[0x8] = COLOUR_PURPLE_8;
	colours[0x9] = COLOUR_PURPLE_9;
	colours[0xa] = COLOUR_PURPLE_A;
	colours[0xb] = COLOUR_PURPLE_B;
	colours[0xc] = COLOUR_PURPLE_C;
	colours[0xd] = COLOUR_PURPLE_D;
	colours[0xe] = COLOUR_PURPLE_E;
	colours[0xf] = COLOUR_PURPLE_F;
}

static void	green_light_to_dark(int *colours)
{
	colours[0x0] = COLOUR_GREEN_0;
	colours[0x1] = COLOUR_GREEN_1;
	colours[0x2] = COLOUR_GREEN_2;
	colours[0x3] = COLOUR_GREEN_3;
	colours[0x4] = COLOUR_GREEN_4;
	colours[0x5] = COLOUR_GREEN_5;
	colours[0x6] = COLOUR_GREEN_6;
	colours[0x7] = COLOUR_GREEN_7;
	colours[0x8] = COLOUR_GREEN_8;
	colours[0x9] = COLOUR_GREEN_9;
	colours[0xa] = COLOUR_GREEN_A;
	colours[0xb] = COLOUR_GREEN_B;
	colours[0xc] = COLOUR_GREEN_C;
	colours[0xd] = COLOUR_GREEN_D;
	colours[0xe] = COLOUR_GREEN_E;
	colours[0xf] = COLOUR_GREEN_F;
}

static void	red_light_to_dark(int *colours)
{
	colours[0x0] = COLOUR_RED_0;
	colours[0x1] = COLOUR_RED_1;
	colours[0x2] = COLOUR_RED_2;
	colours[0x3] = COLOUR_RED_3;
	colours[0x4] = COLOUR_RED_4;
	colours[0x5] = COLOUR_RED_5;
	colours[0x6] = COLOUR_RED_6;
	colours[0x7] = COLOUR_RED_7;
	colours[0x8] = COLOUR_RED_8;
	colours[0x9] = COLOUR_RED_9;
	colours[0xa] = COLOUR_RED_A;
	colours[0xb] = COLOUR_RED_B;
	colours[0xc] = COLOUR_RED_C;
	colours[0xd] = COLOUR_RED_D;
	colours[0xe] = COLOUR_RED_E;
	colours[0xf] = COLOUR_RED_F;
}

void	ft_init_colours(t_context *c)
{
	int	*colours;

	colours = (int *) malloc(sizeof(int) * N_COLOURS);
	if (!colours)
		exit(1);
	c->colours = colours;
	purple_light_to_dark(c->colours);
}

void	ft_change_colours(t_context *c)
{
	c->colour_index++;
	if (c->colour_index == 3)
		c->colour_index = 0;
	if (c->colour_index == 0)
		purple_light_to_dark(c->colours);
	else if (c->colour_index == 1)
		green_light_to_dark(c->colours);
	else if (c->colour_index == 2)
		red_light_to_dark(c->colours);
	else
		purple_light_to_dark(c->colours);
}
