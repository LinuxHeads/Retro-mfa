/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 15:27:36 by abdsalah          #+#    #+#             */
/*   Updated: 2026/02/07 13:02:39 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mfa.h"

long	getFileSize(FILE *file)
{
	long	size;

	fseek(file, 0, SEEK_END);
	size = ftell(file);
	fseek(file, 0, SEEK_SET); // Reset to beginning
	return (size);
}

FILE	*file_setup(const char *filename)
{
	FILE	*in;

	if (endswith(filename, ".mfa") == 0)
	{
		write(2, "Error: Invalid file type. Expected .mfa\n", 40);
		exit(1);
	}
	in = fopen(filename, "r");
	if (in == NULL)
	{
		perror("Error: ");
		exit(1);
	}
	return (in);
}
