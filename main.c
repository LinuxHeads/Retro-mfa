/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 15:01:22 by abdsalah          #+#    #+#             */
/*   Updated: 2026/02/06 18:24:24 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mfa.h"

int main(int argc, char const *argv[])
{
    t_graphics      graphics;
    FILE            *input;

    if (argc != 2)
    {
        write(2, "Usage: ./retromfa <map_file>\n", 29);
        return 1;
    }
    input = file_setup(argv[1]);
    // mfa parse logic
    t_mfa *mfa = load_mfa(input);
    if (mfa == NULL)
    {
        write(2, "Error: Failed to load MFA file\n", 31);
        fclose(input);
        return (1);
    }
    // graphics setup
    graphics_setup(&graphics);
    // mfa render logic
    // image display
    // clean files and memory
    free_mfa(mfa);
    free_graphics(&graphics);
    fclose(input);
    return (0);
}
