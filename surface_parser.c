/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surface_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 10:30:00 by abdsalah          #+#    #+#             */
/*   Updated: 2026/02/07 09:53:17 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mfa.h"

static uint32_t	read_u32_le(unsigned char *p)
{
	return (p[0] | (p[1] << 8) | (p[2] << 16) | (p[3] << 24));
}

static uint16_t	read_u16_le(unsigned char *p)
{
	return (p[0] | (p[1] << 8));
}

int	get_bytes_per_pixel(uint32_t type)
{
	if (type == 0x1004)
		return (3);
	if (type == 0x1006 || type == 0x1007)
		return (2);
	return (0);
}

void	rgb555_to_rgb888(uint16_t pixel555, unsigned char *rgb)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = ((pixel555 >> 10) & 0x1F) << 3;
	g = ((pixel555 >> 5) & 0x1F) << 3;
	b = (pixel555 & 0x1F) << 3;
	rgb[0] = r;
	rgb[1] = g;
	rgb[2] = b;
}

static int	is_valid_surface(t_mfa *mfa, size_t type_offset, uint16_t width,
		uint16_t height, uint32_t type)
{
	int		bpp;
	size_t	pixel_data_start;
	size_t	pixel_data_size;

	bpp = get_bytes_per_pixel(type);
	if (bpp == 0)
		return (0);
	if (width == 0 || height == 0)
		return (0);
	if (width > 4096 || height > 4096)
		return (0);
	pixel_data_start = type_offset + 16;
	pixel_data_size = (size_t)width * height * bpp;
	if (pixel_data_start + pixel_data_size > mfa->size)
		return (0);
	return (1);
}

int	find_surfaces(t_mfa *mfa, t_surface *surfaces, int max_surfaces)
{
	size_t		i;
	int			surface_count;
	uint32_t	type;
	uint16_t	width;
	uint16_t	height;

	i = 0;
	surface_count = 0;
	if (!mfa || !surfaces || max_surfaces <= 0)
		return (0);
	while (i < mfa->size - 16 && surface_count < max_surfaces)
	{
		type = read_u32_le(&mfa->data[i]);
		if (type == 0x1004 || type == 0x1006 || type == 0x1007)
		{
			if (i >= 4)
			{
				width = read_u16_le(&mfa->data[i - 4]);
				height = read_u16_le(&mfa->data[i - 2]);
				if (is_valid_surface(mfa, i, width, height, type))
				{
					surfaces[surface_count].width = width;
					surfaces[surface_count].height = height;
					surfaces[surface_count].type = type;
					surfaces[surface_count].pixel_data = &mfa->data[i + 16];
					surfaces[surface_count].pixel_data_size = (size_t)width
						* height * get_bytes_per_pixel(type);
					surface_count++;
					i += 17;
					continue ;
				}
			}
		}
		i++;
	}
	return (surface_count);
}
