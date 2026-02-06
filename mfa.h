/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mfa.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 15:21:04 by abdsalah          #+#    #+#             */
/*   Updated: 2026/02/06 18:20:15 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MFA_H
# define MFA_H

# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <string.h>

typedef struct s_graphics
{
    void		*mlx;
	void		*win;
	void		*img;
	int			*data;
	int			bpp;
	int			line_len;
	int			endian;
}
				t_graphics;
    
typedef struct s_mfa
{
    unsigned char *data;
    size_t         size;
}   t_mfa;

void    graphics_setup(t_graphics *graphics);
void    free_graphics(t_graphics *graphics);
void 	free_mfa(t_mfa *mfa);
FILE    *file_setup(const char *filename);
t_mfa 	*load_mfa(FILE *input);
bool	endswith(const char *str, const char *suffix);
long 	getFileSize(FILE *file);

#endif