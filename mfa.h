/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mfa.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 15:21:04 by abdsalah          #+#    #+#             */
/*   Updated: 2026/02/07 09:52:56 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MFA_H
# define MFA_H

# define MAX_SURFACES 20

# include "minilibx-linux/mlx.h"
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_graphics
{
	void			*mlx;
	void			*win;
	void			*img;
	int				*data;
	int				bpp;
	int				line_len;
	int				endian;
}					t_graphics;

typedef struct s_mfa
{
	unsigned char	*data;
	size_t			size;
}					t_mfa;

typedef struct s_surface
{
	uint16_t		width;
	uint16_t		height;
	uint32_t		type;
	unsigned char	*pixel_data;
	size_t			pixel_data_size;
}					t_surface;

void				graphics_setup(t_graphics *graphics);
void				free_graphics(t_graphics *graphics);
void				free_mfa(t_mfa *mfa);
FILE				*file_setup(const char *filename);
t_mfa				*load_mfa(FILE *input);
bool				endswith(const char *str, const char *suffix);
long				getFileSize(FILE *file);

/* Surface parsing functions */
int					find_surfaces(t_mfa *mfa, t_surface *surfaces,
						int max_surfaces);
int					get_bytes_per_pixel(uint32_t type);
void				rgb555_to_rgb888(uint16_t pixel555, unsigned char *rgb);
void				render_surface(t_graphics *graphics, t_surface *surface,
						int x, int y);
int					close_window(void *graphics);
int					esc_close_window(int keycode, void *graphics);

#endif