/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 15:01:22 by abdsalah          #+#    #+#             */
/*   Updated: 2026/02/07 09:53:07 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mfa.h"

int	main(int argc, char const *argv[])
{
	t_graphics	graphics;
	FILE		*input;
	t_mfa		*mfa;
	t_surface	surfaces[MAX_SURFACES];
	int			surface_count;
	int			i;
	int			pos_x;
	int			pos_y;

	if (argc != 2)
	{
		write(2, "Usage: ./retromfa <map_file>\n", 29);
		return (1);
	}
	input = file_setup(argv[1]);
	/* Load MFA file */
	mfa = load_mfa(input);
	/* Find surfaces in the MFA file */
	surface_count = find_surfaces(mfa, surfaces, MAX_SURFACES);
	if (surface_count < 5)
	{
		write(2, "Error: Could not find at least 5 surfaces\n", 42);
		free_mfa(mfa);
		fclose(input);
		return (1);
	}
	/* Setup graphics */
	graphics_setup(&graphics);
	fclose(input);
	/* Render at least 5 surfaces in a grid layout */
	pos_y = 10;
	for (i = 0; i < (surface_count < 10 ? surface_count : 10); i++)
	{
		pos_x = 10 + (i % 4) * 250;
		if (i > 0 && i % 4 == 0)
			pos_y += 200;
		render_surface(&graphics, &surfaces[i], pos_x, pos_y);
	}
	/* Display the rendered image */
	mlx_hook(graphics.win, 17, 0, (int (*)())((void *)close_window), &graphics);
	mlx_key_hook(graphics.win, (int (*)())((void *)esc_close_window),
		&graphics);
	mlx_put_image_to_window(graphics.mlx, graphics.win, graphics.img, 0, 0);
	mlx_loop(graphics.mlx);
	/* Clean up */
	free_mfa(mfa);
	free_graphics(&graphics);
	return (0);
}
