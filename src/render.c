/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 10:35:00 by abdsalah          #+#    #+#             */
/*   Updated: 2026/02/07 00:57:12 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mfa.h"

static void put_pixel_mlx(t_graphics *graphics, int x, int y, int color)
{
    if (x < 0 || y < 0 || x >= 1024 || y >= 768)
        return;
    
    int pixel_index = y * (graphics->line_len / 4) + x;
    graphics->data[pixel_index] = color;
}

static int rgb_to_int(unsigned char r, unsigned char g, unsigned char b)
{
    return (r << 16) | (g << 8) | b;
}

void render_surface(t_graphics *graphics, t_surface *surface, int x, int y)
{
    unsigned char *pixel_data = surface->pixel_data;
    int bpp = get_bytes_per_pixel(surface->type);
    int row;
    int col;
    size_t offset;
    unsigned char r;
    unsigned char g;
    unsigned char b;
    uint16_t pixel555;
    int color;
    
    if (bpp == 0)
        return;
    
    for (row = 0; row < surface->height; row++)
    {
        for (col = 0; col < surface->width; col++)
        {
            r = 0;
            g = 0;
            b = 0;
            offset = (row * surface->width + col) * bpp;
            
            if (bpp == 3)
            {
                if (offset + 2 < surface->pixel_data_size)
                {
                    r = pixel_data[offset];
                    g = pixel_data[offset + 1];
                    b = pixel_data[offset + 2];
                }
            }
            else if (bpp == 2)
            {
                if (offset + 1 < surface->pixel_data_size)
                {
                    pixel555 = pixel_data[offset] | (pixel_data[offset + 1] << 8);
                    r = ((pixel555 >> 10) & 0x1F) << 3;
                    g = ((pixel555 >> 5) & 0x1F) << 3;
                    b = (pixel555 & 0x1F) << 3;
                }
            }
            
            color = rgb_to_int(r, g, b);
            put_pixel_mlx(graphics, x + col, y + row, color);
        }
    }
}
