/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 15:27:36 by abdsalah          #+#    #+#             */
/*   Updated: 2026/02/06 15:33:25 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mfa.h"

FILE    *file_setup(const char *filename)
{
    FILE * in;
    
    in = fopen(filename, "r");
    return in;
}
