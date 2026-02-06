/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 15:01:22 by abdsalah          #+#    #+#             */
/*   Updated: 2026/02/06 15:35:54 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mfa.h"

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        write(2, "Usage: ./retromfa <map_file>\n", 29);
        return 1;
    }
    
    FILE * input = file_setup(argv[1]);
    if (input == NULL)
        return (1);
    // graphics setup
    // mfa parse logic
    // image display
    // clean files and memory
    return (0);
}
