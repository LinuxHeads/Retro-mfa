/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 18:01:55 by abdsalah          #+#    #+#             */
/*   Updated: 2026/02/07 09:53:10 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mfa.h"

void	graphics_setup(t_graphics *graphics)
{
	graphics->mlx = mlx_init();
	if (graphics->mlx == NULL)
	{
		write(2, "Error: Failed to initialize graphics\n", 36);
		exit(1);
	}
	graphics->win = mlx_new_window(graphics->mlx, 1024, 768, "Retro MFA");
	if (graphics->win == NULL)
	{
		mlx_destroy_display(graphics->mlx);
		free(graphics->mlx);
		write(2, "Error: Failed to create window\n", 31);
		exit(1);
	}
	graphics->img = mlx_new_image(graphics->mlx, 1024, 768);
	if (graphics->img == NULL)
	{
		mlx_destroy_window(graphics->mlx, graphics->win);
		mlx_destroy_display(graphics->mlx);
		free(graphics->mlx);
		write(2, "Error: Failed to create image\n", 31);
		exit(1);
	}
	graphics->data = (int *)mlx_get_data_addr(graphics->img, &graphics->bpp,
			&graphics->line_len, &graphics->endian);
}

void	free_graphics(t_graphics *graphics)
{
	if (graphics->img)
		mlx_destroy_image(graphics->mlx, graphics->img);
	if (graphics->win)
		mlx_destroy_window(graphics->mlx, graphics->win);
	if (graphics->mlx)
	{
		mlx_destroy_display(graphics->mlx);
		free(graphics->mlx);
	}
}

int	close_window(void *graphics)
{
	t_graphics	*gfx;

	gfx = (t_graphics *)graphics;
	free_graphics(gfx);
	exit(0);
	return (0);
}

int	esc_close_window(int keycode, void *graphics)
{
	t_graphics	*gfx;

	if (keycode == 65307) // ESC key
	{
		gfx = (t_graphics *)graphics;
		free_graphics(gfx);
		exit(0);
	}
	return (0);
}
